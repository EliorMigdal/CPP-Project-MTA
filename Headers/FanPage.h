#ifndef CPP_PROJECT_FANPAGE_H
#define CPP_PROJECT_FANPAGE_H
#include "GlobalVariables.h"
#include "SystemData.h"
class Member;
class Status;

class FanPage : public SystemData {
private:
    char* name = nullptr;
    Member* members = nullptr;
    size_SI numOfMembers = 0;
    Status* bulletinBoard = nullptr;
    size_SI numOfStatuses = 0;

public:
    FanPage() {};
    FanPage(FanPage& obj) // Copy constructor
    {
        name = strdup(obj.name);
        members = obj.members;
        numOfMembers = obj.numOfMembers;
        bulletinBoard = obj.bulletinBoard;
        numOfStatuses = obj.numOfStatuses;
    }
    FanPage(const char*& _name)
    {
        name = strdup(_name);
    }
  
};

#endif