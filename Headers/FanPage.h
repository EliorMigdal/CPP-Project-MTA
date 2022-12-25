#ifndef CPP_PROJECT_FANPAGE_H
#define CPP_PROJECT_FANPAGE_H
#include "Status.h"
class Member;

class FanPage {
private:
    string name;
    unordered_map<string, Member*> members{};
    vector<Status> bulletinBoard{};

public:
    //Constructors & Destructor
    FanPage() = default;
    FanPage(const FanPage& obj) = default;
    FanPage(FanPage&& fanPage) noexcept = default;
    explicit FanPage(const string& _name);
    ~FanPage() = default;

    //Getters
    const string& getName() const { return name; }
    size_t getNumOfMembers() const { return members.size(); }
    size_t  getNumOfStatuses() const { return bulletinBoard.size(); }
    const unordered_map<string, Member*>& getMemberArr() const { return members; }
    const vector<Status>& getStatusArr() const { return bulletinBoard; }

    //FanPage-to-Member Methods
    bool checkIfFan(const string&);
    void addFan(Member*) noexcept(false);
    void removeFan(Member*) noexcept(false);
    void printFans()const noexcept(false);

    //FanPage-to-Status Methods
    void printStatuses() const noexcept(false);
    void addStatus();
    void addStatus(const string&);

    //Operators Methods
    // << Operator
    friend ostream& operator<<(ostream&, FanPage*);
    // = Operator
    FanPage& operator=(const FanPage& fan_page) = default;
    FanPage& operator=(FanPage&& fan_page) = default;
    // += Operator
    const FanPage& operator+=(Member*) noexcept(false);
    // -= Operator
    const FanPage& operator-=(Member*) noexcept(false);
    //Boolean Operators
    bool operator<(FanPage&) const;
    bool operator<=(FanPage&) const;
    bool operator>(FanPage&) const;
    bool operator>=(FanPage&) const;
};

class fanPageExceptions : public std::exception {
public:
    const char* what() const noexcept override { return "Error handling fan page."; }
};

class addAFanException : public fanPageExceptions {
public:
    const char* what() const noexcept override { return "Member is already a fan of this page."; }
};

class removeAFanException : public fanPageExceptions {
public:
    const char* what() const noexcept override { return "Member is already not a fan of this fan page."; }
};

class fanPagePrintStatusesException : public fanPageExceptions {
public:
    const char* what() const noexcept override { return "Fan page has not posted any statuses yet."; }
};

class printFansException : public fanPageExceptions {
public:
    const char* what() const noexcept override { return "This fan page has no fans yet."; }
};

#endif