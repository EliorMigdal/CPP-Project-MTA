#ifndef CPP_PROJECT_SYSTEM_H
#define CPP_PROJECT_SYSTEM_H
#include "Member.h"
#include "FanPage.h"
#include "Status.h"
class System {
private:
    size_SI userDecision = 0;
    unordered_map<string, Member> members;
    unordered_map<string, FanPage*> pages ;

public:
    System() = default;
    ~System() = default;
    System(const System& sys) = delete;
    System(System&& sys) = delete;
    System& operator=(System&& sys) = delete;
    System& operator=(const System& sys) = delete;

    //System - System methods
    void Start();

    //System-to-user Methods
    inline void printMenu() const;
    void setDecision(size_SI&);
    inline size_SI getDecision() const { return userDecision; }

    //General Methods
    string InputOperation(const size_SI&,bool);

    //Member Methods
    void createMember();
    void createMember(const string&, Date&);
    void connectMembers(const Member& , const Member& );
    void disconnectMembers(const Member& member1, const Member& member2);
    
    //FanPage Methods
    void createFanPage();
    void createFanPage(const string&);
    void addFan();
    void addFan(const string&, const string&);
    void removeFan();
    void removeFan(const string&, const string&);
    void addFanPageToArray(FanPage*);

    //Status Methods
    void newStatus();
    void newStatus(const string&, const size_SI&, const string&);

private:
    //System Private Methods
   
    //Global methods
    inline bool BirthdayCheck(const Date&);
   
    //Printers methods 
    void printAllStatuses();
    void printTenLastStatuses();
    void printAllEntities() const;
    void printAllFriends();
    void printAllFans(FanPage* ) const;
    void printAllPages();

    //System-Member Methods
    void connectMembers();
    void disconnectMembers();
};

#endif //CPP_PROJECT_SYSTEM_H