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
    size_t numOfStatuses = 0;
    Member** friends = nullptr;
    size_t numOfFriends = 0;
    FanPage** pages = nullptr;
    size_t numOfPages = 0;

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
    size_t getNumOfStatuses() const { return this->numOfStatuses; }
    Member** getFriendsArr() const { return this->friends; }
    size_t getNumOfFriends() const { return this->numOfFriends; }
    FanPage** getPagesArr() const { return this->pages; }
    size_t getNumOfPages() const { return this->numOfPages; }
   
    //Member-to-Member Methods
    void addFriend(Member* memberToAdd);
    void removeFriend(Member* memberToRemove);
    bool checkIfFriend(const Member* member);
    void printFriendsArr() const;
    

    //Member-to-Status Methods
    inline void printStatus(const size_t& index) const;
    void printStatuses(const size_t& numToPrint = PRINT_STATUS) const;
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