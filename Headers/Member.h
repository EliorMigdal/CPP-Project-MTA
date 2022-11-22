#ifndef CPP_PROJECT_MEMBERS_H
#define CPP_PROJECT_MEMBERS_H
#include "GlobalVariables.h"
#include "Status.h"
class Status;
class FanPage;

class Member : public Status {
private:
    string name = "";
    Date birthday = {0,0,0};
    Status* bulletinBoard = nullptr;
    size_t numOfStatuses = 0;
    Member* friends = nullptr;
    size_t numOfFriends = 0;
    FanPage* pages = nullptr;
    size_t numOfPages = 0;

public:
    Member() {};
    Member(const Member& obj)
    {
        this->name = obj.name;
        this->birthday = obj.birthday;
        this->bulletinBoard = obj.bulletinBoard;
        this->friends = obj.friends;
        this->pages = obj.pages;
        this->numOfFriends = obj.numOfFriends;
        this->numOfPages = obj.numOfPages;
        this->numOfStatuses = obj.numOfStatuses;
    }//Copy constructor.
    Member(const string _name)
    {
       name = _name;
    }
    Member(const string _name, const Date& _birthday)
    {
        name =_name;
        
        birthday = _birthday;
    }
    inline void addFriend(Member& member);
    string getName() const {return this->name;}
    int getNumOfStatuses() const {return this->numOfStatuses;}
    inline void printStatus(int index);
    void printAllStatuses();
    void printTenLastStatuses(Member& member);
};

#endif