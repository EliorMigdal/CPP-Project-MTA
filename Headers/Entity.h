#ifndef CPP_PROJECT_ENTITY_H
#define CPP_PROJECT_ENTITY_H
#include "../Headers/Member.h"
#include "../Headers/FanPage.h"

class Entity {
protected:
    string name;
    unordered_map<string, Member*> members{};
    vector<Status> bulletinBoard{};
public:
    Entity() = default;
    explicit Entity(string _name):name(_name){}

    string& getName() {return name;}
    unordered_map<string, Member*>

    //getName;
    //getMembers;
    //getBulletinBoard;
    //checkIfMember(const string&);
    //addMember
    //removeMember
    //addFanPage = 0;
    //removeFanPage = 0;
    //printAllStatuses
    //printTenLastStatuses = 0;
    //addStatus;
    //printMembers;
    //printPages = 0;

    //operator <<
    //operators += and -= to member
    //operators += and -= to fanpage(override)
    //boolean operators

};

#endif //CPP_PROJECT_ENTITY_H