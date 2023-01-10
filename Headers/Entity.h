#ifndef CPP_PROJECT_ENTITY_H
#define CPP_PROJECT_ENTITY_H
#include "Status.h"

class Member;
class FanPage;

class Entity {
protected:
    string name;
    unordered_map<string, Member*> members{};
    vector<Status> bulletinBoard{};
public:
    Entity() = default;
    explicit Entity(string _name):name(std::move(_name)){}
    virtual ~Entity() = default;

    const string& getName() const {return name;}
    const unordered_map<string, Member*>& getMembers() const {return members;}
    size_t getNumOfMembers() const {return members.size();}
    const vector<Status>& getBulletinBoard() const {return bulletinBoard;}
    size_t getNumOfStatuses() const {return bulletinBoard.size();}

    virtual bool checkIfMember(const string&) const;
    virtual void addMember(Member&) noexcept(false);
    virtual void removeMember(Member&) noexcept(false);
    virtual void printAllStatuses() const noexcept(false);
    virtual void addStatus() noexcept(false);
    virtual void printMembers() const noexcept(false);

    friend ostream& operator<<(ostream&, Entity&);
    virtual Entity& operator=(const Entity&);
    virtual Entity& operator=(Entity&&) noexcept = default;
    virtual bool operator>(const Entity&) const;
    virtual bool operator>=(const Entity&) const;
    virtual bool operator<(const Entity&) const;
    virtual bool operator<=(const Entity&) const;
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

class invalidStatusType : public EntityExceptions {
public:
    const char* what() const noexcept override { return "Invalid status type."; }
};

class entityHasNoMembers : public EntityExceptions {
public:
    const char* what() const noexcept override { return "Entity has no connections yet."; }
};

#endif //CPP_PROJECT_ENTITY_H