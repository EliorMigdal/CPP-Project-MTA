#ifndef CPP_PROJECT_GLOBALVARIABLES_H
#define CPP_PROJECT_GLOBALVARIABLES_H
#pragma warning (disable:4996)
#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::flush;
using std::getline;
typedef unsigned short int size_SI;
typedef unsigned char Byte;

//const Variables
constexpr auto DEFAULT_TYPE = 9;
constexpr size_SI MAX_CHARS_LEN = 250;
constexpr size_SI STATUS = 2;
constexpr size_SI EXIT = 12;
constexpr size_SI PRINT_STATUS = 10;
constexpr size_SI MEMBER = 0;
constexpr size_SI FAN_PAGE = 1;

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
char* readName(const size_SI& type);
void checkMem(void* ptr);
Date& readBirthday();

#endif