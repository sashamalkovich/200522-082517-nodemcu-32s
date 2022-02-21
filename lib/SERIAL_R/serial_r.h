#include <Arduino.h>
#define DEBUG

#ifndef _SERIAL_R_H_
#define _SERIAL_R_H_

#include "sObject.h"


class SerialR {

public:
    SerialR();
    SerialR(char, char);
    ~SerialR();
    int *read();
    sObject &reado();
    int *read(const char **);

private:
  static const int scale = 22;
    char symbol_a;
    char symbol_b;
    char * phisicalRead();
    int * commandResponse(char *, const char **);
    bool equals(char *, const char *);
    int parseInt(char *);

    sObject &commandResponseo(char *, const char **);

    sObject so;


    struct Strings {
        Strings(){
            input_string = new char [scale];
            output = new int [2];
        }
        ~Strings(){
            delete[] input_string;
            delete[] output;
        }
        void operator delete(void * ptr, size_t size){
            free(ptr);
        }

        void operator delete[](void * ptr, size_t size){
            free(ptr);
        }

        char c = '\0';
        char *input_string;
        int *output;
    };

  const char ** commandArray;
    Strings *s;
};

#endif //_SERIAL_R_H_
