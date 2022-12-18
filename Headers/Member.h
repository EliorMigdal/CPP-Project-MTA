#ifndef CPP_PROJECT_MEMBERS_H
#define CPP_PROJECT_MEMBERS_H
#include "GlobalVariables.h"
#include "Status.h"

class FanPage;
class Member {
public:

private:
    string name = "";
    Date birthday = {"0","0","0"};
    vector<Status> bulletinBoard;
    unordered_map<string, Member> friends{};
    unordered_map<string,FanPage*> pages{};

public:
    //Constructors & Destructor
    Member() = default;
    Member(const Member& object) = default;
    Member& operator=(Member&& mem) = default;
    Member& operator=(const Member& mem) = default;
    Member(Member&& mem) noexcept = default;
    explicit Member(const string& _name);
    Member(const string _name, Date& _birthday);
    ~Member() = default;

    //Getters
    string getName() const { return name; }
    Date getBirthday() const { return birthday; }
    vector<Status> getStatusArr() const { return bulletinBoard; }
    unordered_map<string, Member> getFriendsArr() const { return friends; }
    unordered_map<string, FanPage*> getPagesArr() const { return pages; }
   
    //Member-to-Member Methods
    void addFriend(const Member& );
    void removeFriend(const string&);
    bool checkIfFriend(const string&);
    void printFriendsArr() const;

    //Member-to-Status Methods
    void printStatuses(const size_t&) const;
    void addStatus();
    void addStatus(const string&);

    //Member-to-FanPage Methods
    void addPage(FanPage* , const string& );
    bool removePage(const string&);

private:
};


#endif