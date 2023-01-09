#ifndef CPP_PROJECT_MEMBERS_H
#define CPP_PROJECT_MEMBERS_H
#include "Status.h"
class FanPage;

class Member {
private:
    string name;
    vector<Status> bulletinBoard{};
    unordered_map<string, Member*> friends{};
    Date birthday = {0, 0, 0};
    unordered_map<string, FanPage*> pages{};

public:
    //Constructors & Destructor
    Member() = default;
    Member(const Member&) = default;
    Member(Member&&) noexcept = default;
    explicit Member(string&);
    Member(const string&, Date&);
    ~Member() = default;

    //Getters
    const string& getName() const { return name; }
    const Date& getBirthday() const { return birthday; }
    size_t getNumOfFriends() const { return friends.size(); }
    size_t getNumOfStatuses() const { return bulletinBoard.size(); }
    const vector<Status>& getStatusArr() const { return bulletinBoard; }
    const unordered_map<string, Member*>& getFriendsArr() const { return friends; }
    const unordered_map<string, FanPage*>& getPagesArr() const { return pages; }
   
    //Member-to-Member Methods
    void addFriend(Member*) noexcept(false);
    void removeFriend(const string&) noexcept(false);
    bool isFriend(const string&);
    void printFriendsArr() const noexcept(false);

    //Member-to-Status Methods
    void printStatuses(const size_t& numToPrint = PRINT_STATUS) const noexcept(false);
    void addStatus();
    void addStatus(const string&);

    //Member-to-FanPage Methods
    void addPage(FanPage*);
    void removePage(const string&);
    bool isFan(const string&);
    void printAllPages() const noexcept(false);

    //Operators Methods
    // << Operator
    friend ostream& operator<<(ostream&, Member*);
    // = Operator
    Member& operator=(Member&& mem) = default;
    Member& operator=(const Member& mem) = default;
    // += Operator
    const Member& operator+=(Member*);
    const Member& operator+=(FanPage*);
    // -= Operator
    const Member& operator-=(Member*);
    const Member& operator-=(FanPage*);
    // Boolean Operators
    bool operator>(const Member&) const;
    bool operator>=(const Member&) const;
    bool operator<(const Member&) const;
    bool operator<=(const Member&) const;
};

class memberExceptions : public std::exception {
public:
    const char* what() const noexcept override { return "Error handling member."; }
};

class addAFriendException : public memberExceptions {
public:
    const char* what() const noexcept override { return "Members are already friends."; }
};

class removeAFriendException : public memberExceptions {
public:
    const char* what() const noexcept override { return "Members are already not friends."; }
};

class printFriendsException : public memberExceptions {
public:
    const char* what() const noexcept override { return "Member has no friends yet."; }
};

class memberPrintStatusesException : public memberExceptions {
public:
    const char* what() const noexcept override { return "Member has not posted any statuses yet."; }
};

class printPagesException : public memberExceptions { //exception for the implemented uncategorized function.
public:
    const char* what() const noexcept override { return "Member is not a fan of any page."; }
};

#endif