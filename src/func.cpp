#include "func.h"

Func::Func(/* args */)
{
}

Func::~Func()
{
}

void Func::setupFunc()
{
    pinMode(POT_1, INPUT);
    pinMode(POT_2, INPUT);
    pinMode(LED_PIN, OUTPUT);
    pinMode(BUTTON_PIN_1, INPUT);
    pinMode(BUTTON_PIN_2, INPUT);
    pinMode(BUTTON_PIN_3, INPUT);
    setupControls();
    setupBLE();
    setupLeds();
    if (!EEPROM.begin(1000)) {
    Serial.println("Failed to initialise EEPROM");
    Serial.println("Restarting...");
    delay(1000);
    ESP.restart();
  }
    eeRead();

}

void Func::eeRead()
{
    int address = 0;
    controlPot_1 = EEPROM.readByte(address);
    address += sizeof(byte);
    controlPot_2 = EEPROM.readByte(address);
    address += sizeof(byte);
    controlVLX = EEPROM.readByte(address);
    address += sizeof(byte);
    channel = EEPROM.readByte(address);
    address += sizeof(byte);
    LEDprogramm = EEPROM.readByte(address);
    address += sizeof(byte);
    instBrightnes = EEPROM.readByte(address);
    address += sizeof(byte);
    distanceMin = EEPROM.readUShort(address);
    address += sizeof(uint16_t);
    distanceMax = EEPROM.readUShort(address);
    address += sizeof(uint16_t);
    button1 = EEPROM.readByte(address);
    address += sizeof(byte);
    button2 = EEPROM.readByte(address);
    address += sizeof(byte);
    button3 = EEPROM.readByte(address);
    address += sizeof(byte);
}

void Func::eeWrite()
{
    int address = 0;
    EEPROM.writeByte(address, controlPot_1);
    address += sizeof(byte);
    EEPROM.writeByte(address, controlPot_2);
    address += sizeof(byte);
    EEPROM.writeByte(address, controlVLX);
    address += sizeof(byte);
    EEPROM.writeByte(address, channel);
    address += sizeof(byte);
    EEPROM.writeByte(address, LEDprogramm);
    address += sizeof(byte);
    EEPROM.writeByte(address, instBrightnes);
    address += sizeof(byte);
    EEPROM.writeUShort(address, distanceMin);
    address += sizeof(uint16_t);
    EEPROM.writeUShort(address, distanceMax);
    address += sizeof(uint16_t);
    EEPROM.writeByte(address, button1);
    address += sizeof(byte);
    EEPROM.writeByte(address, button2);
    address += sizeof(byte);
    EEPROM.writeByte(address, button3);
    delay(100);
    EEPROM.commit();
}

void Func::controlTest(/* args */)
{
    static unsigned int count;
    count == 127 ? count = 0 : count++;
    controlChange(0, 23, count);
}

void Func::noteTest(/* args */)
{
    // noteSend(0, 0, 36);
}
void Func::run()
{
    //controlTest();
    //noteTest();
    goProcess();
    runPattern(instBrightnes, getSensorData(), getHighlight(), LEDprogramm);
    out = reado();

    if (out.flg[0])
    {
        //Serial.print("ARR-> ");
        //Serial.print(out.arr[0]);
        //Serial.print(", ");
        //Serial.println(out.arr[1]);
        exec(out.arr);
    }
}

void Func::exe_0(int input)
{
    controlPot_1 = input;
}

void Func::exe_1(int input)
{
    controlPot_2 = input;
}
void Func::exe_2(int input)
{
    controlVLX = input;
}

void Func::exe_3(int input)
{
    channel = input;
}

void Func::exe_4(int input)
{
    LEDprogramm = input;
}

void Func::exe_5(int input)
{
    instBrightnes = input;
}

void Func::exe_6(int input)
{
    distanceMin = input;
}

void Func::exe_7(int input)
{
    distanceMax = input;
}

void Func::exe_8(int input)
{
    eeRead();
}

void Func::exe_9(int input)
{
    eeWrite();
}

void Func::exe_10(int input)
{
    Serial.println("<DEF>");
}

void Func::exe_11(int input)
{
    Serial.println("<REQUEST(2)>");
}

void Func::exe_12(int input)
{
    //REFR
    Serial.print("<REF,");
    Serial.print(String(controlPot_1) + ",");
    Serial.print(String(controlPot_2) + ",");
    Serial.print(String(controlVLX) + ",");
    Serial.print(String(channel) + ",");
    Serial.print(String(LEDprogramm) + ",");
    Serial.print(String(instBrightnes) + ",");
    Serial.print(String(distanceMin) + ",");
    Serial.print(String(distanceMax) + ",");
    Serial.print(String(button1) + ",");
    Serial.print(String(button2) + ",");
    Serial.print(String(button3) + ",");
    Serial.print(String(deviceConnected) + ",");

    Serial.print(">");
}

void Func::exe_13(int input)
{
    button1 = input;
}

void Func::exe_14(int input)
{
    button2 = input;
}

void Func::exe_15(int input)
{
    button3 = input;
}

void Func::exe_16(int input)
{
    ESP.restart();
}

void Func::exe_17(int input)
{
   
}