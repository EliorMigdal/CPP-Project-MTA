#ifndef CPP_ASSIGNMENT1_GLOBALVARIABLES_H
#define CPP_ASSIGNMENT1_GLOBALVARIABLES_H
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::flush;

typedef unsigned char Byte;
const Byte MEMBERS = 10;
const Byte NAME_LEN = 21;
const Byte PAGES = 10;
const Byte STATUSES = 20;

struct Date
{
    Byte day = 0, month = 0;
    unsigned short int year = 0;
};

struct Time
{
    Byte hour = 0, minutes = 0, seconds = 0;
};

const enum class STATUS_TYPE{TEXT = 0, IMAGE = 1, VIDEO = 2};

#endif