//
// Created by macbook on 04/06/2020.
//

#ifndef SERIAL_R_SOBJECT_H
#define SERIAL_R_SOBJECT_H


class sObject {
public:
    explicit sObject();
    sObject(int *, char *, bool *, int);
    ~sObject();

    int * arr;
    char * str;
    bool * flg;

    sObject& operator=(const sObject& right) {
        if (this == &right) {
            return *this;
        }
        arr = right.arr;
        str = right.str;
        flg = right.flg;
        return *this;
    }
};


#endif //SERIAL_R_SOBJECT_H
