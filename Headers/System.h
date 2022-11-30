#ifndef CPP_PROJECT_SYSTEM_H
#define CPP_PROJECT_SYSTEM_H
#include "Member.h"
#include "FanPage.h"
#include "Status.h"
#include "Data.h"

class System {
private:
    size_SI userDecision = 0;
    Member** members = nullptr;
    size_t numOfMembers = 0;
    FanPage** pages = nullptr;
    size_t numOfPages = 0;

public:
    System();
    ~System();
    System(const System& sys) = delete;
    System(System&& sys) = delete;
    System& operator=(System&& sys) = delete;
    System& operator=(const System& sys) = delete;

    //System - System methods
    void Start();
    //System-to-user Methods
    inline void printMenu() const;
    void setDecision(size_SI& _decision);
    inline size_SI getDecision() const { return userDecision; }

    //General Methods
    int findEntity(const char* name, const size_SI& entityType) const;
    char* InputOperation(const size_SI& type, int* foundedIndex, const bool& readAfter);

    //Member Methods
    void createMember();
    void createMember(const char* _name, Date& _date);
    void addMemberToArray(Member* member);
    void connectMembers(const char* name1, const char* name2);
    void disconnectMembers(const char* name1, const char* name2);
    
    //FanPage Methods
    void createFanPage();
    void createFanPage(const char* _name);
    void addFan();
    void addFan(const char* pageName, const char* fanName);
    void removeFan();
    void removeFan(const char* pageName, const char* fanName);
    void addFanPageToArray(FanPage* member);

    //Status Methods
    void newStatus();
    void newStatus(const char* name, const size_SI& type, const char* statusContent);

private:
    //System Private Methods
   
    //Global methods
    inline bool BirthdayCheck(const Date& _birthday);
   
    //Printers methods //Why private?
    void printAllStatuses();
    void printTenLastStatuses();
    void printAllEntities() const;
    void printAllFriends();
    void printAllFans(FanPage* fanpage) const;
    void printAllPages();

    //System-Member Methods //Why private?
    void connectMembers();
    void disconnectMembers();

    //Reallocation methods
    void transferMembers();
    void transferFanPages();
};

#endif //CPP_PROJECT_SYSTEM_H