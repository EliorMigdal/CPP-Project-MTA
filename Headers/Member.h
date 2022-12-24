#ifndef CPP_PROJECT_MEMBERS_H
#define CPP_PROJECT_MEMBERS_H
#include "Status.h"
class FanPage;

class Member {
private:
    string name;
    Date birthday = {"0","0","0"};
    vector<Status> bulletinBoard;
    unordered_map<string, Member> friends{};
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
    const unordered_map<string, Member>& getFriendsArr() const { return friends; }
    const unordered_map<string, FanPage*>& getPagesArr() const { return pages; }
   
    //Member-to-Member Methods
    void addFriend(const Member&);
    void removeFriend(const string&);
    bool checkIfFriend(const string&);
    void printFriendsArr() const;

    //Member-to-Status Methods
    void printStatuses(const size_t& numToPrint = PRINT_STATUS) const;
    void addStatus();
    void addStatus(const string&);

    //Member-to-FanPage Methods
    void addPage(FanPage*, const string&);
    void removePage(const string&);
    void printAllPages() const;

    //Operators Methods
    // << Operator
    friend ostream& operator<<(ostream&, const Member&);
    // = Operator
    Member& operator=(Member&& mem) = default;
    Member& operator=(const Member& mem) = default;
    // += Operator
    const Member& operator+=(const Member&);
    const Member& operator+=(FanPage*);
    // -= Operator
    const Member& operator-=(const Member&);
    const Member& operator-=(FanPage*);
    // Boolean Operators
    bool operator>(const Member&) const;
    bool operator>=(const Member&) const;
    bool operator<(const Member&) const;
    bool operator<=(const Member&) const;
};

#endif