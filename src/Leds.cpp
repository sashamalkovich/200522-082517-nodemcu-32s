//
// Created by welm on 2019-12-17.
//

#include "Leds.h"

Leds::Leds()
{
    gHue = 0;
    x = 0;
    led_p = 0;
    _timer = millis();
    pat = 0;
    vlxValue = 0;
    //pCtrl = sens;
}

Leds::~Leds() = default;

void Leds::setupLeds()
{
    delay(1000); // 3 second delay for recovery

    // tell FastLED about the LED strip configuration
    FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
    //FastLED.addLeds<LED_TYPE,DATA_PIN,CLK_PIN,COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);

    // set master brightness controlDATA_PIN
    FastLED.setBrightness(BRIGHTNESS);
}

void Leds::rainbow()
{
    // FastLED's built-in rainbow generator
    fill_rainbow(leds, NUM_LEDS, gHue, 7);
}

void Leds::rainbowWithGlitter()
{
    rainbow();
    addGlitter(80);
}

void Leds::addGlitter(fract8 chanceOfGlitter)
{
    if (random8() < chanceOfGlitter)
    {
        leds[random16(NUM_LEDS)] += CRGB::White;
    }
}

void Leds::confetti()
{
    // random colored speckles that blink in and fade smoothly
    fadeToBlackBy(leds, NUM_LEDS, 10);
    int pos = random16(NUM_LEDS);
    leds[pos] += CHSV(gHue + random8(64), 200, 255);
}

void Leds::sinelon()
{
    // a colored dot sweeping back and forth, with fading trails
    fadeToBlackBy(leds, NUM_LEDS, 20);
    int pos = beatsin16(13, 0, NUM_LEDS - 1);
    leds[pos] += CHSV(gHue, 255, 192);
}

void Leds::bpm()
{
    // colored stripes pulsing at a defined Beats-Per-Minute (BPM)
    uint8_t BeatsPerMinute = 62;
    CRGBPalette16 palette = PartyColors_p;
    uint8_t beat = beatsin8(BeatsPerMinute, 64, 255);
    for (int i = 0; i < NUM_LEDS; i++)
    { //9948
        leds[i] = ColorFromPalette(palette, gHue + (i * 2), beat - gHue + (i * 10));
    }
}

void Leds::juggle()
{
    // eight colored dots, weaving in and out of sync with each other
    fadeToBlackBy(leds, NUM_LEDS, 20);
    byte dothue = 0;
    for (int i = 0; i < 12; i++)
    {
        leds[beatsin16(i + 7, 0, NUM_LEDS - 1)] |= CHSV(dothue, 200, 255);
        dothue += 32;
    }
}

void Leds::blackOut()
{

    for (int i = 0; i < NUM_LEDS; i++)
    { //9948

        if (i >= 0 && i <= 4 || i == 11)
        {
            leds[i] = CHSV(vlxValue, 255, 255);
        }
        else if (i >= 5 && i <= 7)
        {
            leds[i] = CHSV(POT_1_Value, 255, 255);
        }
        else if (i >= 8 && i <= 10)
        {
            leds[i] = CHSV(POT_0_Value, 255, 255);
        }
    }
}

void Leds::runPattern(uint16_t bright, uint8_t getSensD, bool highlight, uint8_t lp)
{
    gHue++;

    FastLED.setBrightness(map(bright, 0, 100, 0, 255));

    if (lp == 0)
    {
        if (millis() - _timer > 20000)
        {
            led_p = x % 6;
            _timer = millis();
            x++;
        }
    }
    else
    {
        led_p = lp;
    }

    switch (led_p)
    {
    case 0:
        rainbow();
        break;
    case 1:
        rainbowWithGlitter();
        break;
    case 2:
        confetti();
        break;
    case 3:
        sinelon();
        break;
    case 4:
        bpm();
        break;
    case 5:
        juggle();
        break;
    case 6:
        blackOut();
        break;
    }

    FastLED.show();
}
