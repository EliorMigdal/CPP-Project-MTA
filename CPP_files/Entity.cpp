#include "../Headers/Entity.h"
#include "../Headers/Member.h"
#include "../Headers/FanPage.h"

//General Methods
//----------------------------------------------------------
bool Entity::checkIfMember(const std::string &_name) const //Checks whether _name is in object's members list.
{
    return this->members.find(_name) != this->members.end();
}
//----------------------------------------------------------
void Entity::addMember(Member &_member) //Adds a new member to object's members.
{
    if (checkIfMember(_member.getName()))
        throw connectedEntities();

    else
        this->members[_member.getName()] = &_member;
}
//----------------------------------------------------------
void Entity::removeMember(Member &_member) //Removes a member from object's members.
{
    if (!checkIfMember(_member.getName()))
        throw disconnectedEntities();

    else
        this->members.erase(_member.getName());
}
//----------------------------------------------------------
void Entity::addStatus() //Adds a new status to entity's bulletin board.
{
    Date newDate;
    Time newTime;
    STATUS_TYPE newType;
    string statusContent, fileName;
    int userInput;
    cout << "Please enter a status type:\n0 - Text Only\n1 - Text & Picture\n2 - Text & Video" << endl;
    cin >> userInput;

    if (userInput != 0 && userInput != 1 && userInput != 2)
        throw invalidStatusType();

    else
        newType = (STATUS_TYPE)userInput;

    cin.ignore();
    cout << "Please enter a your status content:" << endl;
    getline(cin, statusContent);

    if (!statusContent.empty())
    {
        setTimeAndDate(newTime, newDate);

        if (userInput != 0)
        {
            cout << "Please enter a your file's name:" << endl;
            getline(cin, fileName);

            if (fileName.empty())
                throw EmptyFileName();
        }

        switch (userInput){
            default: break;
            case static_cast<int>(STATUS_TYPE::TEXT): this->bulletinBoard.emplace_back(new Status
            (newDate, newTime, statusContent, newType)); break;
            case static_cast<int>(STATUS_TYPE::IMAGE): this->bulletinBoard.emplace_back(new ImageStatus
            (newDate, newTime, statusContent, newType, fileName)); break;
            case static_cast<int>(STATUS_TYPE::VIDEO): this->bulletinBoard.emplace_back(new VideoStatus
            (newDate, newTime, statusContent, newType, fileName)); break;
        }
    }

    else
        throw EmptyStatus();
}
//----------------------------------------------------------
void Entity::addStatusFromFile(Date& _date, Time& _time, string& _content, STATUS_TYPE& _type, string fileName) //Adds a new status to entity's bulletin board.
{
    if (fileName.empty())
        bulletinBoard.emplace_back(new Status(_date, _time, _content, _type));

    else
    {
        switch(static_cast<int>(_type)){
            default: break;
            case static_cast<int>(STATUS_TYPE::IMAGE): bulletinBoard.emplace_back(new ImageStatus
            (_date, _time, _content, _type, fileName)); break;
            case static_cast<int>(STATUS_TYPE::VIDEO): bulletinBoard.emplace_back(new VideoStatus
            (_date, _time, _content, _type, fileName)); break;
        }
    }
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
        using reverseStatusIter = vector<Status*>::const_reverse_iterator;
        reverseStatusIter begin = this->bulletinBoard.crbegin();
        reverseStatusIter end = this->bulletinBoard.crend();
        for (reverseStatusIter rit = begin; rit != end; ++rit)
        {
            cout << "------------------------------------\n\tStatus #"
                 << _numOfStatuses-- << "\n------------------------------------" << endl << **rit;
        }
    }
}
//----------------------------------------------------------
void Entity::printMembers() const //Print an entity's members list.
{
    if (this->members.empty())
        throw entityHasNoConnections();

    else
    {
        cout << "----------------------------------\n" << this->Entity::getName() <<
             "'s connected members are:\n----------------------------------" << endl;
        for (const auto& kv : this->members)
            cout <<"\t" << kv.first << endl;
    }
}
//----------------------------------------------------------

//Operators
//----------------------------------------------------------
ostream& operator<<(ostream& _os, Entity& _entity) //<< operator.
{
    return _os << _entity.Entity::getName();
}
//----------------------------------------------------------
Entity &Entity::operator=(const Entity &_entity) //= operator.
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
bool Entity::operator<(const Entity &_entity) const //< operator.
{
    return this->members.size() < _entity.members.size();
}
//----------------------------------------------------------
bool Entity::operator<=(const Entity &_entity) const //<= operator.
{
    return this->members.size() <= _entity.members.size();
}
//----------------------------------------------------------
bool Entity::operator>(const Entity &_entity) const //> operator.
{
    return this->members.size() > _entity.members.size();
}
//----------------------------------------------------------
bool Entity::operator>=(const Entity &_entity) const //>= operator.
{
    return this->members.size() >= _entity.members.size();
}
//----------------------------------------------------------