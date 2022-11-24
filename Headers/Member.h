#ifndef CPP_PROJECT_MEMBERS_H
#define CPP_PROJECT_MEMBERS_H
#include "GlobalVariables.h"
#include "Status.h"
class FanPage;

class Member {
private:
    string name = "";
    Date birthday = {0,0,0};
    Status* bulletinBoard = nullptr;
    size_SI numOfStatuses = 0;
    Member* friends = nullptr;
    size_SI numOfFriends = 0;
    FanPage* pages = nullptr;
    size_SI numOfPages = 0;

public:
    //Constructors
    Member() = default; //Default constructor.
    Member(Member& object); //Copy constructor.
    explicit Member(string _name);
    Member(string _name, Date& _birthday);

    //Setters
    void setName(string& _name);
    void setBirthday(Date& _birthday);

    //Getters
    string getName() const { return this->name; }
    Date getBirthday() const { return this->birthday; }
    Status* getStatusArr() const { return this->bulletinBoard; }
    int getNumOfStatuses() const { return this->numOfStatuses; }
    Member* getFriendsArr() const { return this->friends; }
    int getNumOfFriends() const { return this->numOfFriends; }
    FanPage* getPagesArr() const { return this->pages; }
    int getNumOfPages() const { return this->numOfPages; }

    //General Methods
    inline void addFriend(Member& member);
    void transferFriends();
    inline void printStatus(int index) const;
    void printStatuses(int numToPrint = PRINT_STATUS) const;
    void addStatus();

private:
    void transferStatuses();

};

#endif