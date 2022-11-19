#ifndef CPP_PROJECT_SYSTEM_H
#define CPP_PROJECT_SYSTEM_H
#include "Member.h"
#include "FanPage.h"
#include "Status.h"
#include "Data.h"
class System : public Member, public FanPage, public Status ,public Data{
private:
    int userDecision = 0;

public:
    System(){}
    inline void printMenu();
    void setDecision(int& _decision);
    void createMember();
    void createFanPage();
    void addStatus();
    void showAllStatuses() const;
    inline void tenLastStatuses() const;
    void connectMembers();
    int getDecision() const { return userDecision; }

};


#endif //CPP_PROJECT_SYSTEM_H
