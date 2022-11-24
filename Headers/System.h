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
    System() = default; //Default constructor.

    //System-to-user Methods
    static inline void printMenu();
    void setDecision(int& _decision);
    int getDecision() const { return userDecision; }

    //General Methods
    int findEntity(string& name, int entityType);
    void createMember();
    void createMember(string& _name, Date& _date); //Added (mostly for testing)
    void addMemberToArray(Member& member); // Added
    void transferMembers(); 
    void createFanPage();
    void addStatus();
    void printAllStatuses();
    void printTenLastStatuses();
    void newStatus();
    void connectMembers();
    void printFanPageMembers();
};

#endif //CPP_PROJECT_SYSTEM_H