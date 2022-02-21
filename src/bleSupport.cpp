#include "bleSupport.h"
bool BleSupport::deviceConnected = false;

BleSupport::BleSupport(/* args */)
{
    midiPacket[0] = 0x80; // header
    midiPacket[1] = 0x80; // timestamp, not implemented
    midiPacket[2] = 0x00; // status
    midiPacket[3] = 0x3c; // 0x3c == 60 == middle c
    midiPacket[4] = 0x00; // velocity
    pMP = new byte[5];
}

BleSupport::~BleSupport()
{
    delete[] pMP;
}

void BleSupport::setupBLE()
{
    BLEDevice::init("SM-ONE");
    //Serial.println("1");

    // Create the BLE Server
    BLEServer *pServer = BLEDevice::createServer();
    pServer->setCallbacks(new MyServerCallbacks());

    // Create the BLE Service
    BLEService *pService = pServer->createService(BLEUUID(SERVICE_UUID));

    // Create a BLE Characteristic
    pCharacteristic = pService->createCharacteristic(
        BLEUUID(CHARACTERISTIC_UUID),
        BLECharacteristic::PROPERTY_READ |
            BLECharacteristic::PROPERTY_WRITE |
            BLECharacteristic::PROPERTY_NOTIFY |
            BLECharacteristic::PROPERTY_WRITE_NR);
    //Serial.println("2");
    // https://www.bluetooth.com/specifications/gatt/viewer?attributeXmlFile=org.bluetooth.descriptor.gatt.client_characteristic_configuration.xml
    // Create a BLE Descriptor
    pCharacteristic->addDescriptor(new BLE2902());

    // Start the service
    pService->start();
    //Serial.println("3");

    // Start advertising
    BLEAdvertising *pAdvertising = pServer->getAdvertising();
    pAdvertising->addServiceUUID(pService->getUUID());
    pAdvertising->start();
   // Serial.println("4");
}

void BleSupport::controlChange(byte channel, byte controller, byte data)
{
    // Serial.println(deviceConnected);
    if (deviceConnected)
    {
        midiPacket[2] = 0xB0 + channel;
        midiPacket[3] = controller;
        midiPacket[4] = data;
        pCharacteristic->setValue(midiPacket, 5);
        pCharacteristic->notify();
    }
}
void BleSupport::noteSend(byte channel, byte control, byte note, bool onOff)
{
    if (deviceConnected)
    {                         
        if(onOff){          // note down
        midiPacket[2] = 0x90 + channel; // note down, channel 0
        midiPacket[3] = note;
        midiPacket[4] = 127;                      // velocity
        pCharacteristic->setValue(midiPacket, 5); // packet, length in bytes
        pCharacteristic->notify();
        // play note for 500ms
        }
        else
        {
        // note up
        midiPacket[2] = 0x80 + channel;
        midiPacket[3] = note;                     // note up, channel 0
        midiPacket[4] = 0;                        // velocity
        pCharacteristic->setValue(midiPacket, 5); // packet, length in bytes)
        pCharacteristic->notify();
        }
    }
}

byte *BleSupport::getMidi()
{

    pMP = pCharacteristic->getData();
    for (int i = 0; i < 5; i++)
    {
        //Serial.print(pMP[i]);
        //Serial.print(", ");
    }
    
   // Serial.println();
    return pMP;
}

byte BleSupport::getControl()
{
    return getMidi()[3];
}