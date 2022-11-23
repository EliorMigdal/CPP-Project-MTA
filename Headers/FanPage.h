#ifndef CPP_PROJECT_FANPAGE_H
#define CPP_PROJECT_FANPAGE_H
#include "GlobalVariables.h"
#include "Status.h"
class Member;

class FanPage {
private:
    string name = "";
    Member* members = nullptr;
    size_SI numOfMembers = 0;
    Status* bulletinBoard = nullptr;
    size_SI numOfStatuses = 0;

public:
    /////// Constructors
    FanPage() {} //Default constructor.

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

    /////// Methods
    string getName() const { return this->name; }
    size_SI getNumOfMembers() const { return this->numOfMembers; }
    size_SI getNumOfStatuses() const { return this->numOfStatuses; }
    void printStatuses() const;
    void printMembers() const; //How can we make it without inheritance?
};

#endif