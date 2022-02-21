//
// Created by welm on 2019-12-17.


#include "FastLED.h"
#include "def.h"


#ifndef LEDS_H
#define LEDS_H


class Leds {
public:
    explicit Leds();

    ~Leds();

    void setupLeds();

    void runPattern(uint16_t, uint8_t, bool, uint8_t);

    CRGB leds[NUM_LEDS];

    int vlxValue;
    int POT_0_Value;
    int POT_1_Value;

private:
    

    void rainbow();

    void rainbowWithGlitter();

    void addGlitter(fract8 chanceOfGlitter);

    void confetti();

    void sinelon();

    void bpm();

    void juggle();

    void blackOut();

    uint8_t gHue; // rotating "base color" used by many of the patterns
    unsigned long x, _timer, led_p;
    unsigned int pat;
    bool highlight = false;
    //Controls *pCtrl;


};


#endif //LEDS_H
