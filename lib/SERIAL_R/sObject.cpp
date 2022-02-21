//
// Created by macbook on 04/06/2020.
//

#include "sObject.h"

sObject::sObject() {
    arr = new int[2];
    str = new char[32];
    flg = new bool[3];
    for(int i = 0; i < 2; i++){
        arr[i] = -1;
    }
    for(int i = 0; i < 32; i++){
        str[i] = char(32);
    }
    for(int i = 0; i < 3; i++){
        flg[i] = false;
    }


}

sObject::sObject(int *a, char *s, bool *f, int count) {
    arr = new int[2];
    str = new char[count];
    flg = new bool[2];
    arr = a;
    str = s;
    flg = f;

}

sObject::~sObject() {
    delete[] arr;
    delete[] str;
    delete[] flg;
}

