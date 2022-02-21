#include <HardwareSerial.h>
#include "run_prog.h"

RunProg::RunProg()
{
    /*
    arr = new RunProg::pfn_MyFuncType[20];
    arr[0] = &RunProg::exe_0;
    arr[1] = &RunProg::exe_1;
    arr[2] = &RunProg::exe_2;
    arr[3] = &RunProg::exe_3;
    arr[4] = &RunProg::exe_4;
    arr[5] = &RunProg::exe_5;
    arr[6] = &RunProg::exe_6;
    arr[7] = &RunProg::exe_7;
    arr[8] = &RunProg::exe_8;
    arr[9] = &RunProg::exe_9;
    arr[10] = &RunProg::exe_10;
    arr[11] = &RunProg::exe_11;
    arr[12] = &RunProg::exe_12;
    arr[13] = &RunProg::exe_13;
    arr[14] = &RunProg::exe_14;
    arr[15] = &RunProg::exe_15;
    arr[16] = &RunProg::exe_16;
    arr[17] = &RunProg::exe_17;
    arr[18] = &RunProg::exe_18;
    arr[19] = &RunProg::exe_19;
    */
}

RunProg::~RunProg() = default;

void RunProg::exec(int *source)
{
    for (int i = 0; i < 20; i++)
    {
        if (source[0] == i)
        {
            switch (i)
            {
            case 0:
                exe_0(source[1]);
                break;
            case 1:
                exe_1(source[1]);
                break;
            case 2:
                exe_2(source[1]);
                break;
            case 3:
                exe_3(source[1]);
                break;
            case 4:
                exe_4(source[1]);
                break;
            case 5:
                exe_5(source[1]);
                break;
            case 6:
                exe_6(source[1]);
                break;
            case 7:
                exe_7(source[1]);
                break;
            case 8:
                exe_8(source[1]);
                break;
            case 9:
                exe_9(source[1]);
                break;
            case 10:
                exe_10(source[1]);
                break;
            case 11:
                exe_11(source[1]);
                break;
            case 12:
                exe_12(source[1]);
                break;
            case 13:
                exe_13(source[1]);
                break;
            case 14:
                exe_14(source[1]);
                break;
            case 15:
                exe_15(source[1]);
                break;
            case 16:
                exe_16(source[1]);
                break;
            case 17:
                exe_17(source[1]);
                break;
            case 18:
                exe_18(source[1]);
                break;
            case 19:
                exe_19(source[1]);
                break;
            default:
                break;
            };
        }
    }
}

void RunProg::exe_0(int in)
{
    Serial.println("ex_0 " + String(in));
}

void RunProg::exe_1(int in)
{
    Serial.println("ex_1 " + String(in));
}

void RunProg::exe_2(int in)
{
    Serial.println("ex_2 " + String(in));
}

void RunProg::exe_3(int in)
{
    Serial.println("ex_3 " + String(in));
}

void RunProg::exe_4(int in)
{
    Serial.println("ex_4 " + String(in));
}

void RunProg::exe_5(int in)
{
    Serial.println("ex_5 " + String(in));
}

void RunProg::exe_6(int in)
{
    Serial.println("ex_6 " + String(in));
}

void RunProg::exe_7(int in)
{
    Serial.println("ex_7 " + String(in));
}

void RunProg::exe_8(int in)
{
    Serial.println("ex_8 " + String(in));
}

void RunProg::exe_9(int in)
{
    Serial.println("ex_9 " + String(in));
}

void RunProg::exe_10(int in)
{
    Serial.println("ex_10 " + String(in));
}

void RunProg::exe_11(int in)
{
    Serial.println("ex_11 " + String(in));
}

void RunProg::exe_12(int in)
{
    Serial.println("ex_12 " + String(in));
}

void RunProg::exe_13(int in)
{
    Serial.println("ex_13 " + String(in));
}

void RunProg::exe_14(int in)
{
    Serial.println("ex_14 " + String(in));
}

void RunProg::exe_15(int in)
{
    Serial.println("ex_15 " + String(in));
}

void RunProg::exe_16(int in)
{
    Serial.println("ex_16 " + String(in));
}

void RunProg::exe_17(int in)
{
    Serial.println("ex_17 " + String(in));
}

void RunProg::exe_18(int in)
{
    Serial.println("ex_18 " + String(in));
}

void RunProg::exe_19(int in)
{
    Serial.println("ex_19 " + String(in));
}