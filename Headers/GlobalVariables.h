#ifndef CPP_PROJECT_GLOBALVARIABLES_H
#define CPP_PROJECT_GLOBALVARIABLES_H
#pragma warning (disable:4996)
#include <iostream>
#include <string>
#include <time.h>
using std::cout;
using std::cin;
using std::endl;
using std::flush;
using std::getline;
typedef unsigned short int size_SI;
typedef unsigned char Byte;

//HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // colorize console.
//Const Variables
constexpr size_SI DEFAULT_TYPE = 9;
constexpr size_SI DEFAULT_FLUSH = 22;
constexpr size_SI CONNECT = 30;
constexpr size_SI DISCONNECT = 31;
constexpr size_SI ADD_FAN = 32;
constexpr size_SI MAX_CHARS_LEN = 250;
constexpr size_SI STATUS = 2;
constexpr size_SI EXIT = 12;
constexpr size_SI PRINT_STATUS = 10;
constexpr size_SI MEMBER = 0;
constexpr size_SI MEMBER_CREATION = 5;
constexpr size_SI MEMBER_REMOVAL = 4;
constexpr size_SI FAN_PAGE = 1;
constexpr size_SI FAN_PAGE_CREATION = 2;
constexpr int NOEXIST = -1;
constexpr size_SI MAX_ATTEMPTS = 3;

//Structures
struct Date
{
    size_SI day = 0, month = 0, year = 0;
};

struct Time
{
    int hour = 0, minutes = 0, seconds = 0;
};

//Enums
enum class STATUS_TYPE{TEXT,IMAGE,VIDEO};

//Global Functions
char* readString(const size_SI& type = DEFAULT_TYPE);
void checkMem(void* ptr);
Date& readBirthday();
void setTimeAndDate(Time& exactTime, Date& exactDate);
#endif