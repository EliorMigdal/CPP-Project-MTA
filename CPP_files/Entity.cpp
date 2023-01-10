#include "../Headers/Entity.h"
#include "../Headers/Member.h"
#include "../Headers/FanPage.h"

//----------------------------------------------------------
bool Entity::checkIfMember(const std::string &_name) const //Checks whether _name is in object's members list.
{
    return this->members.find(_name) != this->members.end();
}
//----------------------------------------------------------
void Entity::addMember(Member &_member) //Adds a new member to object's members.
{
    if (checkIfMember(_member.getName()))
        throw memberAlreadyExists();

    else
        this->members[_member.getName()] = &_member;
}
//----------------------------------------------------------
void Entity::removeMember(Member &_member) //Removes a member from object's members.
{
    if (!checkIfMember(_member.getName()))
        throw memberAlreadyDoesntExists();

    else
        this->members.erase(_member.getName());
}
//----------------------------------------------------------
void Entity::printAllStatuses() const //Prints all object's statuses.
{
    if (this->bulletinBoard.empty())
        throw entityHasNoStatuses();

    else
    {
        cout << this->getName() << " has posted " << this->bulletinBoard.size() << " statuses:" << endl;
        size_t _numOfStatuses = this->bulletinBoard.size();
        using reverseStatusIter = vector<Status>::const_reverse_iterator;
        reverseStatusIter begin = this->bulletinBoard.rbegin();
        reverseStatusIter end = this->bulletinBoard.rend();
        for (reverseStatusIter rit = begin; rit != end; ++rit)
        {
            cout << "------------------------------------\n\tStatus #"
                 << _numOfStatuses-- << "\n------------------------------------" << endl << *rit << endl;
        }
    }
}
//----------------------------------------------------------
void Entity::addStatus() //Adds a new status to entity's bulletin board.
{
    Date newDate;
    Time newTime;
    STATUS_TYPE newType;
    string statusContent;
    int userInput;
    cout << "Please enter a status type:\n1 - Text & Picture\n2 - Text & Video" << endl;
    cin >> userInput;

    if (userInput != 1 && userInput != 2)
        throw invalidStatusType();

    else
        newType = (STATUS_TYPE)userInput;

    cout << "Please enter a your status content:" << endl;
    getline(cin, statusContent);

    if (!statusContent.empty())
    {
        setTimeAndDate(newTime, newDate);
        this->bulletinBoard.emplace_back(Status(newDate, newTime, statusContent, newType));
    }

    else
        throw EmptyStatus();
}
//----------------------------------------------------------
void Entity::printMembers() const //Print an entity's members list.
{
    if (this->members.empty())
        throw entityHasNoMembers();

    else
    {
        cout << "----------------------------------\n" << this->Entity::getName() <<
             "'s connected members are:\n----------------------------------" << endl;
        for (const auto& kv : this->members)
            cout <<"\t" << kv.first << endl;
    }
}
//----------------------------------------------------------
ostream& operator<<(ostream& _os, Entity& _entity)
{
    return _os << _entity.getName();
}
//----------------------------------------------------------
bool Entity::operator<(const Entity &_entity) const
{
    return this->members.size() < _entity.members.size();
}
//----------------------------------------------------------
bool Entity::operator<=(const Entity &_entity) const
{
    return this->members.size() <= _entity.members.size();
}
//----------------------------------------------------------
bool Entity::operator>(const Entity &_entity) const
{
    return this->members.size() > _entity.members.size();
}
//----------------------------------------------------------
bool Entity::operator>=(const Entity &_entity) const
{
    return this->members.size() >= _entity.members.size();
}
//----------------------------------------------------------
Entity &Entity::operator=(const Entity &_entity)
{
    if (this != &_entity)
    {
        this->name = _entity.getName();
        this->members = _entity.getMembers();
        this->bulletinBoard = _entity.getBulletinBoard();
    }

    return *this;
}
//----------------------------------------------------------