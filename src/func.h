#ifndef FUNC_
#define FUNC_

#include "controls.h"
#include "serial_r.h"
#include "run_prog.h"
#include "EEPROM.h"

class Func : public Controls, public SerialR, public RunProg
{
public:
    Func(/* args */);
    ~Func();
    void setupFunc();
    void run();

private:
    void controlTest();
    void noteTest();
    sObject out;

    struct DataBase
    {
        byte controlPot_1;
        byte controlPot_2;
        byte controlVLX;
        byte channel;
        uint16_t LEDprogramm;
        uint16_t instBrightnes;
        uint16_t distanceMin;
        uint16_t distanceMax;
        byte button1;
        byte button2;
        byte button3;
    };

    DataBase db;

    void eeRead();

    void eeWrite();

    void exe_0(int) override;

    void exe_1(int) override;

    void exe_2(int) override;

    void exe_3(int) override;

    void exe_4(int) override;

    void exe_5(int) override;

    void exe_6(int) override;

    void exe_7(int) override;

    void exe_8(int) override;

    void exe_9(int) override;

    void exe_10(int) override;

    void exe_11(int) override;

    void exe_12(int) override;

    void exe_13(int) override;

    void exe_14(int) override;

    void exe_15(int) override;

    void exe_16(int) override;

    void exe_17(int) override;

    /* data */
};

#endif // !FUNC