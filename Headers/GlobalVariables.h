#ifndef CPP_PROJECT_GLOBALVARIABLES_H
#define CPP_PROJECT_GLOBALVARIABLES_H
#pragma warning (disable:4996)
#include <iostream>
#include <string>
#include <ctime>
#include <string>
#include <vector>
#include <unordered_map>
#include <typeindex>
#include <typeinfo>
#include <fstream>

using std::cout;
using std::cin;
using std::endl;
using std::flush;
using std::getline;
using std::string;
using std::vector;
using std::unordered_map;
using std::ostream;
using std::ifstream;//reading from file
using std::ofstream;//writing to file
using std::fstream;//reading&writing
class Entity;

typedef unsigned short int size_SI;
typedef unordered_map<std::type_index, unordered_map<string, Entity*>> SystemMap;

//Const Variables
constexpr size_SI PRINT_STATUS = 10;
constexpr size_SI MEMBER_CHOOSE = 1;
constexpr size_SI FAN_PAGE_CHOOSE = 2;

//Structures
struct Date
{
    Date() = default;
    size_SI day = 0, month = 0, year = 0;
};

struct Time
{
    Time() = default;
    string hour = "0", minutes = "0", seconds = "0";
};

//Enums
enum class STATUS_TYPE {TEXT, IMAGE, VIDEO};
enum DECISION_TYPE {CREATEMEMBER = 1, CREATEFANPAGE, NEWSTATUS,
        PRINTALLSTATUSES, PRINTTENLASTSTATUSES, CONNECTMEMBERS, DISCONNECTMEMBERS, ADDFAN,
        REMOVEFAN, PRINTALLENTITIES, PRINTALLFRIENDS, EXIT};

//Global Functions
void readBirthday(Date& birthday);
void setTimeAndDate(Time& exactTime, Date& exactDate);

class GlobalExceptions : public std::exception{
public:
    const char* what() const noexcept override { return "Global error."; }
};

#endif