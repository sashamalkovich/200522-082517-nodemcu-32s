//
// Created by welm on 2019-12-16.
//

#include "controls.h"

Controls::Controls() : sourseData()
{
  sensor = new VL53L0X;
  analogValue = new int[3];
  lastAnalogValue = new int[3];
  serialData = new int[10];
  vlxValue = 0;
  buttState = new bool[7];
  //eeRead();
}

Controls::~Controls()
{
  delete[] analogValue;
  delete[] lastAnalogValue;
  delete[] serialData;
  delete sensor;
}

void Controls::setupControls()
{
  Wire.begin();
  sensor->init();
  sensor->setTimeout(500);
  sensor->startContinuous();
}

int Controls::Potentiometres(char anRead, byte control, byte channel, int sensor_number, int *analogValue, int *lastAnalogValue)
{
  analogValue[sensor_number] = analogRead(anRead) / 32;
  if ((analogValue[sensor_number] - lastAnalogValue[sensor_number]) > 1 ||
      (analogValue[sensor_number] - lastAnalogValue[sensor_number]) < -1)
  {
    if (analogValue[sensor_number] != lastAnalogValue[sensor_number])
    {
      controlChange(channel, control, analogValue[sensor_number]);
      lastAnalogValue[sensor_number] = analogValue[sensor_number];
    }
  }
  return map(analogValue[sensor_number], 0, 127, 0, 164);
}

int Controls::vlxSensor(byte control, byte channel, int sensor_number, int *analogValue, int *lastAnalogValue)
{

  uint16_t distance;
  distance = sensor->readRangeContinuousMillimeters();

  if (distance > distanceMin && distance < distanceMax)
  {
    analogValue[sensor_number] = map(distance, distanceMin, distanceMax, 0, 127);
    if ((analogValue[sensor_number] - lastAnalogValue[sensor_number]) > 1 ||
        (analogValue[sensor_number] - lastAnalogValue[sensor_number]) < -1)
    {
      if (analogValue[sensor_number] != lastAnalogValue[sensor_number])
      {
        controlChange(channel, control, analogValue[sensor_number]);
        //vlxValue = map(analogValue[sensor_number], 0, 127, 0, 164);
        lastAnalogValue[sensor_number] = analogValue[sensor_number];
      }
    }
  }
  if (distance < distanceMin && distance > distanceMin - 20)
  {
    analogValue[sensor_number] = 0;
    controlChange(channel, control, analogValue[sensor_number]);
  }
  if (distance > distanceMax && distance < distanceMax + 20)
  {
    analogValue[sensor_number] = 127;
    controlChange(channel, control, analogValue[sensor_number]);
  }
  return map(analogValue[sensor_number], 0, 127, 0, 164);
}

void Controls::buttons(byte BUTTON_PIN, byte channel, byte note, byte ctrlNum)
{
  buttState[ctrlNum] = digitalRead(BUTTON_PIN);
  //Serial.println(buttState[ctrlNum]);
  if (buttState[ctrlNum] != buttState[ctrlNum + 3])
  {
    if (buttState[ctrlNum])
    {
      noteSend(channel, 0, note, true);
      for (int i = 0; i < 12; i++)
      {
        leds[i] = CRGB(255, 225, 255);
      }
      FastLED.show();
      delayMicroseconds(5000);
    }
    else
    {
      noteSend(channel, 0, note, false);
    }
  }
  buttState[ctrlNum + 3] = buttState[ctrlNum];
}

void Controls::goProcess()
{
  POT_0_Value = Potentiometres(POT_1, controlPot_1, channel, 0, analogValue, lastAnalogValue);
  POT_1_Value = Potentiometres(POT_2, controlPot_2, channel, 1, analogValue, lastAnalogValue);
  vlxValue = vlxSensor(controlVLX, channel, 2, analogValue, lastAnalogValue);
  buttons(BUTTON_PIN_1, channel, 36, 0);
  buttons(BUTTON_PIN_2, channel, 38, 1);
  buttons(BUTTON_PIN_3, channel, 42, 2);

  //serialData = read();
  //exec(serialData);
  //sObject obj = reado();
  /*
  if (serialData[0] >= 0 && serialData[0] <= 20)
  {
    Serial.print("serialData[0]> ");
    Serial.print(serialData[0]);
    Serial.print(" serialData[1]> ");
    Serial.println(serialData[1]);
  }
  */
}

uint8_t Controls::getSensorData()
{
  return (analogValue[0] + analogValue[1] + analogValue[2]) / 3;
}

bool Controls::getHighlight()
{
  return buttState[0] || buttState[1] || buttState[3];
}
