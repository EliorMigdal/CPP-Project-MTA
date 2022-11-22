#ifndef CPP_PROJECT_SYSTEM_H
#define CPP_PROJECT_SYSTEM_H
#include "Member.h"
#include "FanPage.h"
#include "Status.h"
#include "Data.h"

class System : public Member, public FanPage ,public Data{
private:
    int userDecision = 0;
    Member* members = nullptr;
    int numOfMembers = 0;
    FanPage* pages = nullptr;
    int numOfPages = 0;

public:
    System(){}
    inline void printMenu();
    void setDecision(int& _decision);
    int findMember(string& name);
    void createMember(); //Add a few more constructors?
    void createMember(const string _name, const Date& _date); //Added (mostly for testing)
    void addMemberToArray(Member& member); // Added
    void transferMembers(); // Added (Like realloc)
    void createFanPage();
    void addStatus();
   /* void showAllStatuses() const;*/
    void tenLastStatuses();
    void connectMembers();
    int getDecision() const { return userDecision; }
};

#endif //CPP_PROJECT_SYSTEM_H