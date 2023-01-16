#ifndef CPP_PROJECT_ENTITY_H
#define CPP_PROJECT_ENTITY_H
#include "Status.h"

class Member;
class FanPage;

class Entity {
protected:
    string name;
    unordered_map<string, Member*> members{};
    vector<Status*> bulletinBoard{};
public:
    //Constructors & Destructor
    Entity() = default;
    explicit Entity(string _name):name(std::move(_name)){}
    Entity(Entity&) = delete;
    Entity(Entity&&) noexcept = delete;
    virtual ~Entity() = default;

    //Getters
    const string& getName() const {return name;}
    const unordered_map<string, Member*>& getMembers() const {return members;}
    size_t getNumOfMembers() const {return members.size();}
    const vector<Status*>& getBulletinBoard() const {return bulletinBoard;}
    size_t getNumOfStatuses() const {return bulletinBoard.size();}

    //Virtual Methods
    void saveToFile(ofstream& out);
    void loadFromFile(ifstream& in);
    virtual bool checkIfMember(const string&) const;
    virtual void addMember(Member&) noexcept(false);
    virtual void removeMember(Member&) noexcept(false);
    virtual void printAllStatuses() const noexcept(false);
    virtual void addStatus() noexcept(false);
    void addStatusFromFile(Date&, Time&, string&, STATUS_TYPE&, string = "");
    virtual void printMembers() const noexcept(false);

    //Operators
    friend ostream& operator<<(ostream&, Entity&);
    virtual Entity& operator=(const Entity&);
    virtual Entity& operator=(Entity&&) noexcept = default;
    virtual bool operator>(const Entity&) const;
    virtual bool operator>=(const Entity&) const;
    virtual bool operator<(const Entity&) const;
    virtual bool operator<=(const Entity&) const;
};

class EntityExceptions : public std::exception{
public:
    const char* what() const noexcept override { return "Error handling entity."; }
};

class entityHasNoStatuses : public EntityExceptions {
public:
    const char* what() const noexcept override { return "Entity hasn't posted any statuses."; }
};

class entityHasNoConnections : public EntityExceptions {
public:
    const char* what() const noexcept override { return "Entity has no connections yet."; }
};

class connectedEntities : public EntityExceptions {
public:
    const char* what() const noexcept override { return "Entities are already connected."; }
};

class addAFanException : public connectedEntities {
public:
    const char* what() const noexcept override { return "Member is already a fan of this page."; }
};

class removeAFanException : public EntityExceptions {
public:
    const char* what() const noexcept override { return "Member is already not a fan of this page."; }
};

class disconnectedEntities : public EntityExceptions {
public:
    const char* what() const noexcept override { return "Entities are already disconnected."; }
};
class addAFriendException : public EntityExceptions {
public:
    const char* what() const noexcept override { return "Members are already friends."; }
};

class removeAFriendException : public EntityExceptions {
public:
    const char* what() const noexcept override { return "Members are already not friends."; }
};

class invalidStatusType : public EntityExceptions {
public:
    const char* what() const noexcept override { return "Invalid status type."; }
};

#endif //CPP_PROJECT_ENTITY_H