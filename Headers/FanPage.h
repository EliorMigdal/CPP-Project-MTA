#ifndef CPP_PROJECT_FANPAGE_H
#define CPP_PROJECT_FANPAGE_H
#include "GlobalVariables.h"
#include "Status.h"
#include "Member.h"

class FanPage {
private:
    string name = "";
    unordered_map<string, Member> members{};
    vector<Status> bulletinBoard{};
public:
    //Constructors & Destructor
    FanPage() = default;
    FanPage(const FanPage& obj) = default;
    FanPage& operator=(FanPage&& fanpage) = default;
    FanPage& operator=(const FanPage& fanpage) = default;
    FanPage(FanPage&& fanpage) = default;
    explicit FanPage(const string& _name);
    ~FanPage() = default;
    //Getters
    string getName() const { return name; }
    size_t getNumOfMembers() const { return members.size(); }
    size_t getNumOfStatuses() const { return bulletinBoard.size(); }
    unordered_map<string, Member> getMemberArr() const { return members; }
    vector<Status> getStatusArr() const { return bulletinBoard; }

    //FanPage-to-Member Methods
    bool checkIfFan(const string& member_name);
    bool removeFan(const string&);
    void addMember(const Member& );

    //FanPage-to-Status Methods
    void printStatuses() const;
    void addStatus();
    void addStatus(const string&);
    //Private Methods

};

#endif