#ifndef CPP_PROJECT_SYSTEM_H
#define CPP_PROJECT_SYSTEM_H
#include "Member.h"
#include "FanPage.h"
#include "Status.h"
#include "Data.h"

class System {
private:
    int userDecision = 0;
    Member* members = nullptr;
    int numOfMembers = 0;
    FanPage* pages = nullptr;
    int numOfPages = 0;

public:
    System(){} //Default constructor.
    inline void printMenu();
    void setDecision(int& _decision);
    int getDecision() const { return userDecision; }
    int findEntity(const char* name, const int entityType);
    void createMember();
    void createMember(const char* _name, const Date& _date); //Added (mostly for testing)
    void addMemberToArray(Member& member); // Added
    void transferMembers(); 
    void createFanPage();
    void newStatus();
    void printAllStatuses();
    void printTenLastStatuses();

   /* void showAllStatuses() const;*/
    void connectMembers();
};

#endif //CPP_PROJECT_SYSTEM_H