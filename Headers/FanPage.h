#ifndef CPP_PROJECT_FANPAGE_H
#define CPP_PROJECT_FANPAGE_H
#include "Member.h"

/*class FanPageException : public std::exception
{
public:
    virtual const char* what() const override { return "Failed creating a Page, Already exists\n"; }
};
class RemoveAFanException : public FanPageException
{
public:
    virtual const char* what() const override { return "Failed because member doesn't exist!\n"; }
};
class AddAFanException : public FanPageException
{
public:
    virtual const char* what() const override { return "Failed because member Already exists"; }
};
class CheckIfFanException : public FanPageException
{
public:
    virtual const char* what() const override { return "Failed because member_name is empty!\n"; }
};*/

class FanPage {
private:
    string name;
    unordered_map<string, Member> members{};
    vector<Status> bulletinBoard{};

public:
    //Constructors & Destructor
    FanPage() = default;
    FanPage(const FanPage& obj) = default;
    FanPage(FanPage&& fanpage) noexcept = default;
    explicit FanPage(const string& _name);
    ~FanPage() = default;

    //Getters
    const string& getName() const { return name; }
    size_t getNumOfMembers() const { return members.size(); }
    size_t getNumOfStatuses() const { return bulletinBoard.size(); }
    const unordered_map<string, Member>& getMemberArr() const { return members; }
    const vector<Status>& getStatusArr() const { return bulletinBoard; }

    //FanPage-to-Member Methods
    bool checkIfFan(const string&);
    bool removeFan(const Member&);
    void addFan(const Member&);

    //FanPage-to-Status Methods
    void printStatuses() const;
    void addStatus();
    void addStatus(const string&);

    //Operators Methods
    // << Operator
    friend ostream& operator<<(ostream&, FanPage&);
    // = Operator
    FanPage& operator=(const FanPage& fan_page) = default;
    FanPage& operator=(FanPage&& fan_page) = default;
    // += Operator
    const FanPage& operator+=(Member&);
    // -= Operator
    const FanPage& operator-=(Member&);
    //Boolean Operators
    bool operator<(FanPage&) const;
    bool operator<=(FanPage&) const;
    bool operator>(FanPage&) const;
    bool operator>=(FanPage&) const;
};

#endif