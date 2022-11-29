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
    char* InputOperation(const size_SI& type, int* foundedIndex);
    //Members Methods
    void createMember();
    void createMember(const char* _name, Date& _date); // Temp function for testings
    void addMemberToArray(Member* member);
    
    //Fan Pages Methods
    void createFanPage();
    void addFan();
    void removeFan();
    void addFanPageToArray(FanPage* member);

    //Status Methods
    void newStatus();

private:
    /*System private Methods*/
    
    //--Global function
    inline bool BirthdayCheck(const Date& _birthday);
   
    //--Printers functions
    void printAllStatuses();
    void printAllEntities() const;
    void printAllFriends(); 
    void printTenLastStatuses();
    
    //--Reallocation functions
    void transferMembers();
    void transferFanPages();
    
    //System-Fan Page- private Methods
    void printAllFans(FanPage* fanpage) const;
    
    //System-members private Methods
    void connectMembers();
    void disconnectMembers();
};

#endif //CPP_PROJECT_SYSTEM_H