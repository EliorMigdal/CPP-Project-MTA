#ifndef CPP_PROJECT_FANPAGE_H
#define CPP_PROJECT_FANPAGE_H
#include "GlobalVariables.h"
class Member;
class Status;

class FanPage {
private:
    string name = "";
    Member* members = nullptr;
    size_SI numOfMembers = 0;
    Status* bulletinBoard = nullptr;
    size_SI numOfStatuses = 0;

public:
    FanPage() {};
    FanPage(FanPage& obj) // Copy constructor
    {
        this->name= obj.name;
        this->members = obj.members;
        this->numOfMembers = obj.numOfMembers;
        this->bulletinBoard = obj.bulletinBoard;
        this->numOfStatuses = obj.numOfStatuses;
    }
    FanPage(const string _name)
    {
        name = _name;
    }
  
};

#endif