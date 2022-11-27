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
    System();
    ~System();

    //System-to-user Methods
    inline void printMenu();
    void setDecision(int& _decision);
    int getDecision() const { return userDecision; }

    //General Methods
    int findEntity(const char* name, const size_SI& entityType) const;
    void printAllStatuses();
    void printAllEntities();
    void printAllFriends();

    //Members Methods
    void createMember();
    void createMember(const char* _name, Date& _date);
    void addMemberToArray(Member& member);
    void transferMembers();
    void printTenLastStatuses();
    void connectMembers();
    void disconnectMembers();

    //Fan Pages Methods
    void createFanPage();
    void addFan();
    void removeFan();
    void printAllFans(FanPage* fanpage) const;

    //Status Methods
    void newStatus();

private:
    inline bool BirthdayCheck(const Date& _birthday);
};

#endif //CPP_PROJECT_SYSTEM_H