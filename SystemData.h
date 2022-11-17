#ifndef CPP_ASSIGNMENT1_SYSTEMDATA_H
#define CPP_ASSIGNMENT1_SYSTEMDATA_H
#include "GlobalVariables.h"
class Member;
class FanPage;

class SystemData {
protected:
    unsigned short int numOfMembers = 0, numOfPages = 0;
    Member* members = nullptr;
    FanPage* fanpages = nullptr;

public:
    void print() const
    {
        cout << "Members List: " << endl;
        for(unsigned short int i = 0; i < numOfMembers; i++)
        {
            //use gets
        }
        cout << "Fan Pages List: " << endl;
    }
};

#endif