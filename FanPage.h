#ifndef CPP_ASSIGNMENT1_FANPAGE_H
#define CPP_ASSIGNMENT1_FANPAGE_H
#include "GlobalVariables.h"
#include "SystemData.h"
class Member;
class Status;

class FanPage : public SystemData {
private:
    char* name = nullptr;
    Member* members = nullptr;
    unsigned short int numOfMembers = 0;
    Status* bulletinBoard = nullptr;
    unsigned short int numOfStatuses = 0;

public:
    FanPage(const char* _name) {strcpy(name, _name);}
};

#endif