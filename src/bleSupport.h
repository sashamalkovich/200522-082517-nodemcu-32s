#ifndef BLE_SUPPORT_
#define BLE_SUPPORT_

#include "def.h"
#include "Arduino.h"

#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEServer.h>
#include <BLE2902.h>

class BleSupport
{
private:
    BLECharacteristic *pCharacteristic;
    byte midiPacket[5];
    byte *pMP;
    byte *getMidi();

    class MyServerCallbacks : public BLEServerCallbacks
    {
        void onConnect(BLEServer *pServer)
        {
            deviceConnected = true;
        };

        void onDisconnect(BLEServer *pServer)
        {
            deviceConnected = false;
        }
    };

protected:
    static bool deviceConnected;
    void setupBLE();
    void controlChange(byte, byte, byte);
    void noteSend(byte, byte, byte, bool);
    byte getControl();

public:
    explicit BleSupport();
    ~BleSupport();
};

#endif // !BLE_SUPPORT_
