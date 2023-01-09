#ifndef CPP_PROJECT_ENTITY_H
#define CPP_PROJECT_ENTITY_H
#include "Member.h"
#include "FanPage.h"

class Entity {
protected:
    string name;
    unordered_map<string, Member*> members{};
    vector<Status> bulletinBoard{};
public:
    Entity() = default;
    explicit Entity(string _name):name(_name){}

    string& getName() {return name;}
    unordered_map<string, Member*>& getMembers() {return members;}
    vector<Status>& getBulletinBoard() {return bulletinBoard;}

    virtual bool checkIfMember(const string&) const;
    virtual void addMember(Member&) noexcept(false);
    virtual void removeMember(Member&) noexcept(false);
    virtual void addFanPage() = 0;
    virtual void removeFanPage() = 0;
    virtual void printAllStatuses() noexcept(false);
    virtual void printTenLastStatuses() = 0;
    virtual void addStatus();
    virtual void printMembers();
    virtual void printPages() = 0;

    //operator <<
    //operators += and -= to member
    //operators += and -= to fanpage(override)
    //boolean operators

};

class EntityExceptions : public std::exception {
public:
    const char* what() const noexcept override { return "Error handling entity."; }
};

class memberAlreadyExists : public EntityExceptions {
public:
    const char* what() const noexcept override { return "Member is already connected to entity."; }
};

class memberAlreadyDoesntExists : public EntityExceptions {
public:
    const char* what() const noexcept override { return "Member is already not connected to entity."; }
};

class entityHasNoStatuses : public EntityExceptions {
public:
    const char* what() const noexcept override { return "Entity hasn't posted any statuses."; }
};

#endif //CPP_PROJECT_ENTITY_H