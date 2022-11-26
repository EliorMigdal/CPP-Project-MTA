#ifndef CPP_PROJECT_MEMBERS_H
#define CPP_PROJECT_MEMBERS_H
#include "GlobalVariables.h"
#include "Status.h"
class FanPage;

class Member {
private:
    char* name = nullptr;
    Date birthday = {0,0,0};
    Status* bulletinBoard = nullptr;
    size_t numOfStatuses = 0;
    Member* friends = nullptr;
    size_t numOfFriends = 0;
    FanPage* pages = nullptr;
    size_t numOfPages = 0;

public:
    /////// Constructors
    Member() {} //Default constructor.

    Member(const Member& obj) //Copy constructor.
    {
        this->name = obj.name;
        this->birthday = obj.birthday;
        this->bulletinBoard = obj.bulletinBoard;
        this->friends = obj.friends;
        this->pages = obj.pages;
        this->numOfFriends = obj.numOfFriends;
        this->numOfPages = obj.numOfPages;
        this->numOfStatuses = obj.numOfStatuses;
    }

    Member(const char* _name)
    {
        name = new char[strlen(_name)+1];
        strcpy(name, _name);
    }

    Member(const char* _name, const Date& _birthday)
    {
        name = new char[strlen(_name) + 1];
        strcpy(name, _name);
        birthday = _birthday;
    }
  
    /////// Methods
    char* getName() const {return this->name;}
    int getNumOfStatuses() const {return this->numOfStatuses;}
    int findFriend(char* friendName);
    inline void addFriend(Member& member);
    inline void printStatus(int index);
    void printStatuses(int numToPrint = PRINT_STATUS);
    void addStatus();
private:
    void transferStatuses();

};

#endif