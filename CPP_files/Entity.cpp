#include "../Headers/Entity.h"

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
void Entity::printAllStatuses() //Prints all object's statuses.
{
    if(this->bulletinBoard.empty())
        cout << "EXCEPTION" << endl;

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