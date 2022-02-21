#include "serial_r.h"
///*
#ifdef DEBUG
#undef DEBUG
#endif // DEBUG DEBUG
//*/
/*
#ifndef DEBUG
#define DEBUG
#endif
*/

SerialR::SerialR()
{
    symbol_a = '<';
    symbol_b = '>';
    s = new Strings;
    commandArray = new const char *[scale];
    commandArray[0] = "POTa";
    commandArray[1] = "POTb";
    commandArray[2] = "VLXc";
    commandArray[3] = "CHANb";
    commandArray[4] = "LEDp";
    commandArray[5] = "LEDb";
    commandArray[6] = "DISTmin";
    commandArray[7] = "DISTmax";
    commandArray[8] = "LOAD";
    commandArray[9] = "STORE";
    commandArray[10] = "DEF";
    commandArray[11] = "REQUEST";
    commandArray[12] = "REFRESH";
    commandArray[13] = "BUTa";
    commandArray[14] = "BUTb";
    commandArray[15] = "BUTc";
    commandArray[16] = "RESET";
    commandArray[17] = "JOOLW";
    commandArray[18] = "JOOLV";
    commandArray[19] = "JOOLU";
    commandArray[20] = "JOOLO";
    commandArray[21] = "WOOLA";
}

SerialR::SerialR(char a, char b)
{
    symbol_a = a;
    symbol_b = b;
}

SerialR::~SerialR()
{
    free(s);
}

char *SerialR::phisicalRead()
{
    bool key = true;
    uint8_t i = 0;
    static bool sw = false;
    for (int i = 0; i < scale; i++)
    {
        s->input_string[i] = ' ';
    }
    if (Serial.available() > 0)
    {

        while (key)
        {
            s->c = Serial.read();
            if (s->c == symbol_a)
            {
                sw = true;
                continue;
            }
            else if (s->c == symbol_b)
            {
                sw = false;
                continue;
            }
            if (sw)
            {
                s->input_string[i] = s->c;
            }
            if (s->c == '\n')
            {
                s->input_string[i] = '\0';
                break;
            }
            i++;
        }
    }
    else
    {
        return s->input_string;
    }

#ifdef DEBUG
    Serial.print("input-> ");
    Serial.println(s->input_string);
#endif
    return s->input_string;
}

int *SerialR::read()
{
    return commandResponse(phisicalRead(), commandArray);
}

int *SerialR::read(const char **array)
{
    return commandResponse(phisicalRead(), array);
}

sObject &SerialR::reado()
{
    return commandResponseo(phisicalRead(), commandArray);
}

int *SerialR::commandResponse(char *input_string, const char **command_array)
{
    bool sw = false;
    bool sr = false;
    int iter = 0;
    char *temp;
    temp = new char[scale];
    for (int i = 0; i < scale; i++)
    {
        temp[i] = ' ';
    }
    s->output[0] = -1, s->output[1] = -1;
    for (uint8_t i = 0; i < scale; i++)
    {
        if (equals(input_string, command_array[i]))
        {
            s->output[0] = i;
            sr = true;
        }
    }
    for (int i = 0, y = s->output[0]; i < scale; i++, y++)
    {
        if (sr)
        {
#ifdef DEBUG
            Serial.print("i -> ");
            Serial.println(i);
            Serial.print("Response -> ");
            Serial.println(input_string[i]);
#endif
            if (input_string[i] == '(')
            {
#ifdef DEBUG
                Serial.println("Digits on");
#endif
                sw = true;
            }
            else if (input_string[i] == ')')
            {
                sw = false;
                sr = false;
#ifdef DEBUG
                Serial.println("Digits off");
#endif
                break;
            }
            if (sw)
            {
#ifdef DEBUG
                Serial.print("Read on -> ");
                Serial.println(input_string[i]);
#endif
                temp[iter] = input_string[i];
                iter++;
            }
        }
    }
    if (temp[0] != ' ')
    {
#ifdef DEBUG
    
        Serial.print("temp-> ");
        Serial.println(temp);

#endif
        s->output[1] = parseInt(temp);
    }
    else
    {
        s->output[1] = -1;
    }
    delete[] temp;
    return s->output;
}

sObject &SerialR::commandResponseo(char *input_string, const char **command_array)
{
    static bool sw = false;
    static bool sr = false;
    bool digiReadOn = false;
    int readStr = 0;
    int iter = 0;
    int iter_str = 0;
    char *temp;
    so.flg[0] = false;
    so.flg[1] = false;
    so.flg[2] = false;
    temp = new char[scale];
    for (int i = 0; i < scale; i++)
    {
        temp[i] = ' ';
        so.str[i] = ' ';
    }
    s->output[0] = -1, s->output[1] = -1;
    for (uint8_t i = 0; i < scale; i++)
    {
        if (equals(input_string, command_array[i]))
        {
            s->output[0] = i;
            sr = true;
            so.flg[0] = true;
        }
    }
    for (int i = 0, y = s->output[0]; i < scale; i++, y++)
    {
        if (sr)
        {
#ifdef DEBUG
            Serial.print("i -> ");
            Serial.println(i);
            Serial.print("Response -> ");
            Serial.println(input_string[i]);
#endif

            if (input_string[i] == '(')
            {
#ifdef DEBUG
                Serial.println("Digits on");
#endif
                sw = true;
                continue;
            }
            else if (input_string[i] == ')')
            {
                sw = false;
                sr = false;
                digiReadOn = true;
#ifdef DEBUG
                Serial.println("Digits off");
#endif
                continue;
            }
            if (sw)
            {
#ifdef DEBUG
                Serial.print("Read on -> ");
                Serial.println(input_string[i]);
#endif
                temp[iter] = input_string[i];
                iter++;
            }
            if (input_string[i] == '\"')
            {
                readStr++;

#ifdef DEBUG
                Serial.print("str on++ -> ");
                Serial.println(input_string[i]);
#endif
                continue;
            }
            if (readStr == 1)
            {
                so.str[iter_str] = input_string[i];

#ifdef DEBUG
                Serial.print("Read str -> ");
                Serial.println(so.str[iter_str]);
#endif
                iter_str++;
            }
            else if (readStr == 2)
            {
#ifdef DEBUG
                Serial.print("End of read str-> ");
                Serial.println(so.str);
#endif
                so.str[iter_str] = '\0';
                so.flg[2] = true;
                break;
            }
        }
    }
#ifdef DEBUG
    if (temp[0] != ' ')
    {
        Serial.print("temp-> ");
        Serial.println(temp);
    }
#endif
    if (digiReadOn)
    {
        s->output[1] = parseInt(temp);
        so.flg[1] = true;
    }
    if (s->output[0] < 0)
    {
        so.flg[0] = false;
    }

    so.arr = s->output;
    delete[] temp;
    //return s->output;
    return so;
}

bool SerialR::equals(char *input1, const char *input2)
{
    for (int i = 0; i < scale; i++)
    {
        if (input1[i] == '\0' || input1[i] == '(' || input1[i] == '\"')
        {
            break;
        }
        if (input1[i] == input2[i])
        {
        }
        else
        {
            return false;
        }
    }
    return true;
}

int SerialR::parseInt(char *c)
{
    const char *sym = "0123456789";
    int s = 0;
    int arr[scale];
    for (int i = 0; i < scale; i++)
    {
        arr[i] = -1;
    }
    int iter = 0;
    for (int i = 0; i < scale-1; i++)
    {
        for (int y = 0; y < scale-1; y++)
        {
            if (c[i] == sym[y])
            {
                arr[iter] = y;
                iter++;
            }
        }
    }
    for (int i = 0; i < scale-1; i++)
    {
        if (arr[i] < 0 || arr[i] > 9)
        {
        delayMicroseconds(500);
#ifdef DEBUG
            Serial1.print("Drop cycles-> ");
            Serial1.print(i);
            Serial1.print(" arr[i]-> ");
            Serial1.println(arr[i]);
#endif
            continue;
        }
        else
        {
            s *= 10;
            s += arr[i];
#ifdef DEBUG
            Serial.print("Accept cycles-> ");
            Serial.print(i);
            Serial.print(" arr[i]-> ");
            Serial.println(arr[i]);
#endif
        }
    }
    return s;
}
