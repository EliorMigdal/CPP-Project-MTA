#ifndef CPP_PROJECT_GLOBALVARIABLES_H
#define CPP_PROJECT_GLOBALVARIABLES_H
#pragma warning (disable:4996)
#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::flush;

//Aliases
typedef unsigned short int size_SI;
typedef unsigned char Byte;

//const Variables
constexpr int EXIT = 12;

//structures
struct Date
{
    size_SI day = 0, month = 0, year = 0;
};

struct Time
{
    Byte hour = 0, minutes = 0, seconds = 0;
};
//Enums
enum class STATUS_TYPE{TEXT,IMAGE,VIDEO};


#endif