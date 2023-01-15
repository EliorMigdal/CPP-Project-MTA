#ifndef CPP_PROJECT_MEMBERS_H
#define CPP_PROJECT_MEMBERS_H
#include "Entity.h"
class FanPage;

class Member : public Entity {
private:
    Date birthday = {0, 0, 0};
    unordered_map<string, FanPage*> pages{};

public:
    //Constructors & Destructor
    Member() = default;
    Member(const Member&) = delete;
    Member(Member&&) noexcept = delete;
    Member(string&, Date&);
    Member& operator=(const Member& mem) = default;
    Member& operator=(Member&& mem) = default;
    ~Member() override = default;

    //Getters
    const Date& getBirthday() const {return birthday;}
    const unordered_map<string, FanPage*>& getPages() const {return pages;}
    size_t getNumOfPages() const {return pages.size();}

    //Member-to-FanPage Methods
    virtual void addFanPage(FanPage&) noexcept(false);
    virtual void removeFanPage(FanPage&) noexcept(false);
    bool isFan(FanPage&);

    //Printer Methods
    virtual void printTenLastStatuses() noexcept(false);
    virtual void printPages() noexcept(false);

    //Operators
    virtual const Member& operator+=(Member&) noexcept(false);
    virtual const Member& operator-=(Member&) noexcept(false);
    virtual const Member& operator+=(FanPage&) noexcept(false);
    virtual const Member& operator-=(FanPage&) noexcept(false);
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

class printPagesException : public memberExceptions { //Exception for unused Member::printPages() method.
public:
    const char* what() const noexcept override { return "Member is not a fan of any page."; }
};

#endif