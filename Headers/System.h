#ifndef CPP_PROJECT_SYSTEM_H
#define CPP_PROJECT_SYSTEM_H
#include "FanPage.h"

class System {
private:
    size_SI userDecision = 0;
    unordered_map<string, Member> members{};
    unordered_map<string, FanPage*> pages{};

public:
    System() = default;
    ~System() = default;
    System(const System& sys) = delete;
    System(System&& sys) = delete;
    System& operator=(System&& sys) = delete;
    System& operator=(const System& sys) = delete;

    //System - System methods
    void Start();
    void initialData();

    //System-to-user Methods
    inline void printMenu() const;
    void setDecision(size_SI&);
    inline size_SI getDecision() const { return userDecision; }

    //General Methods
    string InputOperation(const size_SI&, bool);

    //Member Methods
    void createMember();
    void createMember(const string&, Date&);
    void connectMembersHardCoded(const Member& , const Member&);
    void disconnectMembersHardCoded(const Member& , const Member&);
    
    //FanPage Methods
    void createFanPage();
    void Add_OR_RemoveFAN(void(System::* operation)(const string&, const string&));
    void createFanPage(const string&);
    void addFanHardCoded(const string&, const string&);
    void addFan(const string&, const string&);
    void removeFanHardCoded(const string&, const string&);
    void removeFan(const string&, const string&);

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
    void printAllFans(FanPage*) const;
    void printAllPages();

    //System-Member Methods
    void connectMembers(const string&, const string& );
    void disconnectMembers(const string&, const string& );
    void Connect_OR_DisconnectMember(void(System::* operation)(const string&, const string&));
};

#endif //CPP_PROJECT_SYSTEM_H