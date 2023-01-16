#ifndef CPP_PROJECT_SYSTEM_H
#define CPP_PROJECT_SYSTEM_H
#include "Entity.h"

class System {
private:
    size_SI userDecision = 0;
    unordered_map<std::type_index, unordered_map<string, Entity*>> Entities{}; //Managed container.

public:
    //Constructors & Destructor
    System() noexcept(false);
    ~System() = default;
    System(const System& sys) = delete;
    System(System&& sys) = delete;
    System& operator=(System&& sys) = delete;
    System& operator=(const System& sys) = delete;

    //Start Methods
    void Start() noexcept(false);

private:
    //System-to-user Methods
    static inline void printMenu();
    void setDecision(size_SI&) noexcept(false);
    inline size_SI getDecision() const { return userDecision; }
    static int memberOrFanPage() noexcept(false);

    //Member Methods
    void createMember() noexcept(false);
    void Connect_OR_DisconnectMember(bool connect) noexcept(false);
    void connectOrDisconnectMembers(Member* firstMember, Member* secondMember, bool connect) noexcept(false);

    //FanPage Methods
    void createFanPage() noexcept(false);
    void Add_OR_RemoveFAN(bool connect) noexcept(false);
    void addOrRemoveFanUtility(Member*, FanPage*, bool) noexcept(false);

    //Status Methods
    void newStatus() noexcept(false);
    
    //Global Methods
    static inline bool BirthdayCheck(const Date&);
   
    //Printers Methods
    void printAllStatuses() noexcept(false);
    void printTenLastStatuses() noexcept(false);
    void printAllEntities() noexcept(false);
    void printAllFriends() noexcept(false);

    //File methods
    void readData();
    void writeData();

    
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
public:
    const char* what() const noexcept override { return "Cannot add yourself to your friends list."; }
};

class removeSameMember : public systemExceptions {
public:
    const char* what() const noexcept override { return "Cannot remove yourself from your friends list."; }
};

class entityNotFound : public systemExceptions {
public:
    const char* what() const noexcept override { return "Entity was not found in our system."; }
};

class EmptyName : public systemExceptions {
public:
    const char* what() const noexcept override { return "Cannot enter an empty name."; }
};

class EmptySystemExceptions : public std::exception {
public:
    const char* what() const noexcept override { return "System is empty."; }
};

class noMembersInSystem : public EmptySystemExceptions {
public:
    const char* what() const noexcept override { return "System has no members yet."; }
};

class noPagesInSystem : public EmptySystemExceptions {
public:
    const char* what() const noexcept override { return "System has no pages yet."; }
};

class corruptFile : public systemExceptions {
public:
    const char* what() const noexcept override { return "File is corrupt."; }
};

#endif //CPP_PROJECT_SYSTEM_H