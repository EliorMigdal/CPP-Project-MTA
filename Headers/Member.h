#ifndef CPP_PROJECT_MEMBERS_H
#define CPP_PROJECT_MEMBERS_H
#include "GlobalVariables.h"
#include "Status.h"
class Status;
class FanPage;

class Member : public Status {
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
    Member() {};
    Member(Member& obj)
    {
        name = strdup(obj.name);
        birthday = obj.birthday;
        bulletinBoard = obj.bulletinBoard;
        friends = obj.friends;
        pages = obj.pages;
        numOfFriends = obj.numOfFriends;
        numOfPages = obj.numOfPages;
        numOfStatuses = obj.numOfStatuses;
    }//Copy constructor.
    Member(const char* _name)
    {
       name = strdup(_name);
    }
    Member(const char* _name, const Date& _birthday)
    {
        name = strdup(_name);
        
        birthday = _birthday;
    }
    inline void addFriend(Member& member);
    char* getName() const {return this->name;}
    int getNumOfStatuses() const {return this->numOfStatuses;}
    inline void printStatus(int index) const;
    inline void printAllStatuses() const;
    inline void printTenLastStatuses(Member& member) const;
};

#endif