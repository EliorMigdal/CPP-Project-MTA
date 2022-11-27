#ifndef CPP_PROJECT_FANPAGE_H
#define CPP_PROJECT_FANPAGE_H
#include "GlobalVariables.h"
#include "Status.h"
class Member;

class FanPage {
private:
    char* name = nullptr;
    Member** members = nullptr;
    size_t numOfMembers = 0;
    Status** bulletinBoard = nullptr;
    size_t numOfStatuses = 0;

public:
    // Constructors
    FanPage() = default; //Default constructor.
    FanPage(const FanPage& obj); // Copy constructor
    explicit FanPage(const char* _name);

    // Methods
    char* getName() const { return this->name; }
    size_t getNumOfMembers() const { return this->numOfMembers; }
    size_t getNumOfStatuses() const { return this->numOfStatuses; }
    Member** getMemberArr() const { return this->members; }
    Status** getStatusArr() const { return this->bulletinBoard; }
    void printStatuses() const;
};

#endif