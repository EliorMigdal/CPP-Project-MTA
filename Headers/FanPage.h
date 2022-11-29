#ifndef CPP_PROJECT_FANPAGE_H
#define CPP_PROJECT_FANPAGE_H
#include "GlobalVariables.h"
#include "Status.h"
#include "Member.h"

class FanPage {
private:
    char* name = nullptr;
    Member** members = nullptr;
    size_t numOfMembers = 0;
    Status** bulletinBoard = nullptr;
    size_t numOfStatuses = 0;

public:
    //Constructors & Destructor
    FanPage() = default;
    FanPage(const FanPage& obj);
    explicit FanPage(const char* _name);

    //Getters
    char* getName() const { return name; }
    size_t getNumOfMembers() const { return numOfMembers; }
    size_t getNumOfStatuses() const { return numOfStatuses; }
    Member** getMemberArr() const { return members; }
    Status** getStatusArr() const { return bulletinBoard; }

    //FanPage-to-FanPage Methods


    //FanPage-to-Member Methods
    bool checkIfFan(Member* member);
    bool findIndexAndRemoveFAN(Member* member);
    void addMember(Member* member);
    
    //FanPage-to-Status Methods
    void printStatuses() const;
    void addStatus();

    //Private Methods
private:
    
    void transferMembers();
    void transferStatuses();
};

#endif