#ifndef CPP_PROJECT_GLOBALVARIABLES_H
#define CPP_PROJECT_GLOBALVARIABLES_H
#pragma warning (disable:4996)
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::flush;
//Aliases
typedef unsigned short int size_SI;
typedef unsigned char Byte;
//const variables
constexpr int EXIT = 12;
//////constexpr Byte MEMBERS = 10;
//////static constexpr Byte NAME_LEN = 21;
//////constexpr Byte PAGES = 10;
//////constexpr Byte STATUSES = 20;

//structures
struct Date
{
    Byte day = 0, month = 0;
    size_SI year = 0;
};

struct Time
{
    Byte hour = 0, minutes = 0, seconds = 0;
};
//Enums
enum class STATUS_TYPE{TEXT,IMAGE,VIDEO};

#endif