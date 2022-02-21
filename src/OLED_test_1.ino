#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <serial_r.h>
#include "func.h"

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET 4 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define NUMFLAKES 10 // Number of snowflakes in the animation example

#define LOGO_HEIGHT 16
#define LOGO_WIDTH 16

SerialR s;
sObject so;
Func f;

int *array;

void setup()
{
  Serial.begin(115200);
  Serial1.begin(115200);

  //Wire.begin();
  f.setupFunc();

  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C))
  { // Address 0x3C for 128x32
    Serial.println(F("SSD1306 allocation failed"));
    for (;;)
      ; // Don't proceed, loop forever
  }

  // Show initial display buffer contents on the screen --
  // the library initializes this with an Adafruit splash screen.
  display.display();
  delay(200);

  // Clear the buffer
  display.clearDisplay();
  delay(3); // power-up safety delay
}

void loop()
{
  //array = s.read();
  so = s.reado();
  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.print("A -> ");
  display.print(so.arr[0]);
  display.print(" a-> ");
  display.print(so.arr[1]);
  display.setCursor(0, 20);
  display.print("str-> ");
  display.print(so.str);

  display.setCursor(0, 10);
  display.print(" f0> ");
  display.print(so.flg[0]);
  display.print(" f1> ");
  display.print(so.flg[1]);
  display.print(" f2> ");
  display.print(so.flg[2]);
  display.display();
  // Serial.println('>' + String(so.arr[0]) + '.' + String(so.arr[1]));
  // Serial.println(so.str);
  f.run();
}