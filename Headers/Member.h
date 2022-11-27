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
    //Constructors & Destructor
    Member() = default;
    Member(const Member& object);
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

    //Member-to-Member Methods
    void addFriend(Member* memberToAdd);
    void removeFriend(Member* memberToRemove);
    bool checkIfFriend(Member* member);
    void printFriendsArr() const;

    //Member-to-Status Methods
    inline void printStatus(const int& index) const;
    void printStatuses(size_SI numToPrint = PRINT_STATUS) const;
    void addStatus();

    //Member-to-FanPage Methods
    void addPage(FanPage* fanPage);

private:
    //Private Re-allocators
    void transferStatuses();
    void transferFriends();
    void transferPages();
};

#endif