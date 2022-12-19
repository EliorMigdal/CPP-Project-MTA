#ifndef CPP_PROJECT_GLOBALVARIABLES_H
#define CPP_PROJECT_GLOBALVARIABLES_H
#pragma warning (disable:4996)
#include <iostream>
#include <string>
#include <time.h>
#include<string>
#include <vector>
#include<unordered_map>
#include<map>
using std::cout;
using std::cin;
using std::endl;
using std::flush;
using std::getline;
using std::string;
using std::vector;
using std::unordered_map;
using std::map;
using std::ostream;
typedef unsigned short int size_SI;
typedef unsigned char Byte;

//HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // colorize console.
//Const Variables
constexpr size_SI DEFAULT_TYPE = 9;
constexpr size_SI DEFAULT_FLUSH = 22;
constexpr size_SI MAX_CHARS_LEN = 250;
constexpr size_SI EXITi = 12;
constexpr size_SI PRINT_STATUS = 10;
constexpr size_SI MEMBER = 0;
constexpr size_SI MEMBER_CREATION = 5;
constexpr size_SI FAN_PAGE = 1;
constexpr size_SI FAN_PAGE_CREATION = 2;
constexpr int NOEXIST = -1;
constexpr size_SI MAX_ATTEMPTS = 3;
constexpr size_SI REMOVE_FAN = 1;
constexpr size_SI ADD_FAN = 0;
//Structures
struct Date
{
    string day ="0", month = "0", year = "0";
};

struct Time
{
   string hour = "0", minutes = "0", seconds = "0";
};

//Enums
enum class STATUS_TYPE{TEXT,IMAGE,VIDEO};
enum  DESCISION_TYPE { CREATEMEMBER = 1, CREATEFANPAGE, NEWSTATUS,PRINTALLSTATUSES,PRINTTENLASTSTATUSES,CONNECTMEMBERS,DISCONNECTMEMBERS,ADDFAN,REMOVEFAN,PRINTALLENTITIES,PRINTALLFRIENDS,EXIT };

//Global Functions
void checkMem(void* ptr);
void readBirthday(Date& birthday);
void setTimeAndDate(Time& exactTime, Date& exactDate);
#endif