#ifndef CPP_PROJECT_SYSTEM_H
#define CPP_PROJECT_SYSTEM_H
#include "Member.h"
#include "FanPage.h"
#include "Status.h"
#include "Data.h"

class System {
private:
    Byte userDecision = 0;
    Member** members = nullptr;
    size_t numOfMembers = 0;
    FanPage** pages = nullptr;
    size_t numOfPages = 0;

public:
    System();
    ~System();

    //System-to-user Methods
    inline void printMenu() const;
    void setDecision(Byte& _decision);
    inline Byte getDecision() const { return this->userDecision; }

    //General Methods
    int findEntity(const char* name, const size_SI& entityType) const;
    
    //Members Methods
    void createMember();
    void createMember(const char* _name, Date& _date); // Temp function for testings
    void addMemberToArray(Member* member);
    
    //Fan Pages Methods
    void createFanPage();//****************** need to implement
    void addFan();
    void removeFan(); //****************** need to implement
    void printAllFans(FanPage* fanpage) const;

    //Status Methods
    void newStatus(); //****************** need to implement

private:
    //System private Methods
    inline bool BirthdayCheck(const Date& _birthday);
    void printAllStatuses() const;
    void printAllEntities() const;
    void printAllFriends() const; 
    void transferMembers();
    void printTenLastStatuses() const;
    
    //System members private Methods
    void connectMembers();
    void disconnectMembers();
};

#endif //CPP_PROJECT_SYSTEM_H