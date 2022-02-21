

//
// Created by welm on 2019-12-16.
//

#include "def.h"
#include <arduino.h>
#include <VL53L0X.h>
#include <Adafruit_GFX.h>
#include <SPI.h>
#include <Wire.h>
#include "sourseData.h"
#include <EEPROM.h>
#include "bleSupport.h"
#include "Leds.h"

#ifndef BLINK_LEO_CONTROLS_H
#define BLINK_LEO_CONTROLS_H

class Controls : public sourseData, public BleSupport, public Leds
{
public:
    explicit Controls();

    ~Controls();

    void goProcess();

    void setupControls();

    uint8_t getSensorData();

    bool getHighlight();

private:
    int Potentiometres(char, byte, byte, int, int *, int *);

    int vlxSensor(byte, byte, int, int *, int *);

    void buttons(byte, byte, byte, byte);

    VL53L0X *sensor;
    //int16_t vlxValue;

    bool *buttState;
    int *analogValue;
    int *lastAnalogValue;
    int *serialData;
};

#endif //BLINK_LEO_CONTROLS_H
