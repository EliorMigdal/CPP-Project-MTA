#ifndef CPP_PROJECT_DATA_H
#define CPP_PROJECT_DATA_H
#include "GlobalVariables.h"
class Member;
class FanPage;

class Data {
protected:
    size_SI numOfMembers = 0, numOfPages = 0;
    Member* members = nullptr;
    FanPage* fanpages = nullptr;

public:
   
};

#endif