#ifndef CPP_PROJECT_MEMBERS_H
#define CPP_PROJECT_MEMBERS_H
#include "GlobalVariables.h"
#include "Status.h"
class FanPage;

class Member {
private:
    char* name = nullptr;
    Date birthday = {0,0,0};
    Status** bulletinBoard = nullptr;
    size_SI numOfStatuses = 0;
    Member** friends = nullptr;
    size_SI numOfFriends = 0;
    FanPage** pages = nullptr;
    size_SI numOfPages = 0;

public:
    //Constructors
    Member() = default; //Default constructor.
    Member(const Member& object); //Copy constructor.
    explicit Member(const char* _name);
    Member(const char* _name, Date& _birthday);
    ~Member();

    //Getters
    char* getName() const { return this->name; }
    Date getBirthday() const { return this->birthday; }
    Status** getStatusArr() const { return this->bulletinBoard; }
    int getNumOfStatuses() const { return this->numOfStatuses; }
    Member** getFriendsArr() const { return this->friends; }
    int getNumOfFriends() const { return this->numOfFriends; }
    FanPage** getPagesArr() const { return this->pages; }
    int getNumOfPages() const { return this->numOfPages; }

    ////Methods
    void addFriend(Member* member);
    inline void printStatus(const int& index) const;
    void printStatuses(size_SI numToPrint = PRINT_STATUS) const;
    void addStatus();

private:
    //Private reallocators
    void transferStatuses();
    void transferFriends();

};

#endif