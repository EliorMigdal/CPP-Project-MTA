#ifndef CPP_PROJECT_SYSTEM_H
#define CPP_PROJECT_SYSTEM_H
#include "FanPage.h"
#include "Member.h"

class System {
private:
    size_SI userDecision = 0;
    unordered_map<string, Member> members{};
    unordered_map<string, FanPage> pages{};

public:
    //Constructors & Destructor
    System() = default;
    ~System() = default;
    System(const System& sys) = delete;
    System(System&& sys) = delete;
    System& operator=(System&& sys) = delete;
    System& operator=(const System& sys) = delete;

    //Start Methods
    void Start() noexcept(false);
private:
    void initialData();

    //System-to-user Methods
    static inline void printMenu();
    void setDecision(size_SI&) noexcept(false);
    inline size_SI getDecision() const { return userDecision; }
    static int memberOrFanPage() noexcept(false);

    //Member Methods
    void createMember() noexcept(false);
    void createMember(const string&, Date&);
    void Connect_OR_DisconnectMember(void(System::* operation)(const string&, const string&)) noexcept(false);
    void connectMembers(const string&, const string&) noexcept(false);
    void disconnectMembers(const string&, const string&) noexcept(false);
    void connectMembersHardCoded(Member*, Member*);
    void disconnectMembersHardCoded(Member*, Member*);
    
    //FanPage Methods
    void createFanPage() noexcept(false);
    void createFanPage(const string&);
    void Add_OR_RemoveFAN(void(System::* operation)(const string&, const string&)) noexcept(false);
    void addFan(const string&, const string&) noexcept(false);
    void removeFan(const string&, const string&) noexcept(false);
    void addFanHardCoded(const string&, const string&);
    void removeFanHardCoded(const string&, const string&);

    //Status Methods
    void newStatus() noexcept(false);
    void newStatus(const string&, const size_SI&, const string&);
    
    //Global Methods
    static inline bool BirthdayCheck(const Date&);
   
    //Printers Methods
    void printAllStatuses() const noexcept(false);
    void printTenLastStatuses() const noexcept(false);
    void printAllEntities() const noexcept(false);
    void printAllFriends() const noexcept(false);
};

class systemExceptions : public std::exception {
public:
    const char* what() const noexcept override { return "System error."; }
};

class invalidUserDecision : public systemExceptions {
public:
    const char* what() const noexcept override { return "Invalid user decision."; }
};

class userAlreadyExists : public systemExceptions {
public:
    const char* what() const noexcept override { return "User already exists in our system."; }
};

class pageAlreadyExists : public systemExceptions {
public:
    const char* what() const noexcept override { return "Page already exists in our system."; }
};

class invalidBirthday : public systemExceptions {
public:
    const char* what() const noexcept override { return "Invalid birthday input."; }
};

class memberNotFound : public systemExceptions {
public:
    const char* what() const noexcept override { return "At least one member was not found in our system."; }
};

class connectSameMember : public systemExceptions {
    const char* what() const noexcept override { return "Cannot add yourself to your friends list."; }
};

class removeSameMember : public systemExceptions {
    const char* what() const noexcept override { return "Cannot remove yourself from your friends list."; }
};

class entityNotFound : public systemExceptions {
    const char* what() const noexcept override { return "Entity was not found in our system."; }
};

class EmptyName : public systemExceptions {

    const char* what() const noexcept override { return "Cannot enter an empty name."; }
};



class EmptySystemExceptions : public std::exception {
public:
    const char* what() const noexcept override { return "System is empty."; }
};

class noMembersInSystem : public EmptySystemExceptions {
    const char* what() const noexcept override { return "System has no members yet."; }
};

class noPagesInSystem : public EmptySystemExceptions {
    const char* what() const noexcept override { return "System has no pages yet."; }
};


#endif //CPP_PROJECT_SYSTEM_H