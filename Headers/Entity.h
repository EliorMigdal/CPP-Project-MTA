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

    //General Methods
    virtual bool checkIfMember(const string&) const;
    virtual void addMember(Member&) noexcept(false);
    virtual void removeMember(Member&) noexcept(false);
    virtual void addStatus() noexcept(false);
<<<<<<< HEAD
    virtual void addStatusFromFile(Date& _date, Time& _time, string& _content, STATUS_TYPE& _type);
=======
    virtual void printAllStatuses() const noexcept(false);
>>>>>>> ca0bba83977dbc9795fb915806ad0d2645eafe33
    virtual void printMembers() const noexcept(false);

    //Operators
    friend ostream& operator<<(ostream&, Entity&);
    Entity& operator=(const Entity&);
    Entity& operator=(Entity&&) noexcept = default;
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

#endif //CPP_PROJECT_ENTITY_H