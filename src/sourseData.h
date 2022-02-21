#include <Arduino.h>

#ifndef SOURSEDATA_H
#define SOURSEDATA_H

class sourseData
{
public:
    sourseData(/* args */);
    ~sourseData();
    static byte controlPot_1;
    static byte controlPot_2;
    static byte controlVLX;
    static byte channel;
    static uint16_t LEDprogramm;
    static uint16_t instBrightnes;
    static uint16_t distanceMin;
    static uint16_t distanceMax;
    static byte button1;
    static byte button2;
    static byte button3;
};

#endif