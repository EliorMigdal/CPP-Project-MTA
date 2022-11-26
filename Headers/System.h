#ifndef CPP_PROJECT_SYSTEM_H
#define CPP_PROJECT_SYSTEM_H
#include "Member.h"
#include "FanPage.h"
#include "Status.h"
#include "Data.h"

class System {
private:
    int userDecision = 0;
    Member** members = nullptr;
    int numOfMembers = 0;
    FanPage** pages = nullptr;
    int numOfPages = 0;

public:
    System() = default; //Default constructor.
    //System-to-user Methods
    inline void printMenu();
    void setDecision(int& _decision);
    int getDecision() const { return userDecision; }

    //General Methods
    int findEntity(const char* name, const size_SI& entityType) const;
    void createMember();
    void createMember(const char* _name, Date& _date); //Added (mostly for testing)
    void addMemberToArray(Member* member); // Added
    void transferMembers(); 
    void createFanPage();
    void printAllStatuses();
    void printTenLastStatuses();
    void newStatus();
    void connectMembers();
    void printFanPageMembers();
private:
    inline bool BirthdayCheck(const Date& _birthday);
};

#endif //CPP_PROJECT_SYSTEM_H