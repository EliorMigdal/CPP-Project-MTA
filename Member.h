#ifndef CPP_ASSIGNMENT1_MEMBERS_H
#define CPP_ASSIGNMENT1_MEMBERS_H
#include "GlobalVariables.h"
#include "Status.h"
class Status;
class FanPage;

class Member {
private:
    char* name = nullptr;
    Date birthday = {0,0,0};
    Status* bulletinBoard = nullptr;
    int numOfStatuses = 0;
    Member* friends = nullptr;
    int numOfFriends = 0;
    FanPage* pages = nullptr;
    int numOfPages = 0;

public:
    void addFriend(Member& member)
    {
        if (numOfFriends + 1 < MEMBERS)
            friends[numOfFriends] = member;
        numOfFriends++;
    }
};

#endif