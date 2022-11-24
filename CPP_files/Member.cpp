#include "../Headers/Member.h"

//----------------------------------------------------------
Member::Member(std::string _name, Date &_birthday) //Constructor.
{
    setName(_name);
    setBirthday(_birthday);
}
//----------------------------------------------------------
Member::Member(std::string _name) //Constructor.
{
    setName(_name);
}
//----------------------------------------------------------
Member::Member(Member &object) //Copy Constructor. (#IS IT NEEDED?)
{
    setName(object.name);
    setBirthday(object.birthday);

    numOfFriends = object.numOfFriends;
    numOfPages = object.numOfPages;
    numOfStatuses = object.numOfStatuses;

    bulletinBoard = object.bulletinBoard; //Do we need to allocate new arrays in these 3 rows?
    friends = object.friends; //
    pages = object.pages; //
}
//----------------------------------------------------------
void Member::setName(std::string &_name) //Sets member's name.
{
    name = _name;
}
//----------------------------------------------------------
void Member::setBirthday(Date &_birthday) //Sets member's birthday.
{
    birthday = _birthday;
}
//----------------------------------------------------------
void Member::addFriend(Member& member) //Adds a new friends to the friends array.
{
    if (numOfFriends == 0)
        friends = new Member[numOfFriends];

    else
        transferFriends();

    friends[numOfFriends++] = member;
}
//----------------------------------------------------------
void Member::transferFriends() //Re-allocates memory for friends array.
{
    auto* output = new Member[numOfFriends + 1];

    for(int i = 0; i < numOfFriends; i++)
        output[i] = Member(friends[i]);

    delete[] friends;
    friends = output;
}
//----------------------------------------------------------
void Member::printStatus(int index) const
{
    cout << this->bulletinBoard[index].getStatus() << endl;
    this->bulletinBoard[index].printDate(this->bulletinBoard[index].getStatusDate(), this->bulletinBoard[index].getStatusTime());
}
//----------------------------------------------------------
void Member::printStatuses(int numToPrint) const //Prints member's statuses.
{
    int _numOfStatuses = this->getNumOfStatuses();
    int logicPrintSize;
    if (_numOfStatuses == 0)
        cout << this->getName() << " has not posted any statuses." << endl;

    if (numToPrint == PRINT_STATUS)
    {
        if (_numOfStatuses < PRINT_STATUS)
        {
            logicPrintSize = _numOfStatuses;
            cout << this->getName() << " has only posted " << numOfStatuses << " statuses:" << endl;
        }

        else
        {
            logicPrintSize = PRINT_STATUS;
            cout << this->getName() << "'s last " << PRINT_STATUS << " statuses:" << endl;
        }

        for (int i = _numOfStatuses - 1; i >= _numOfStatuses - logicPrintSize; i--)
        {
            cout << "Status #" << i + 1 << ":" << endl;
            this->printStatus(i);
        }
    }
}
//------------------------------------------------------------------------
void Member::transferStatuses() //Re-allocating memory for status arr.
{
    auto* output = new Status[numOfStatuses + 1];

    for(size_t i = 0; i < numOfStatuses; i++)
    {
        Status temp(output[i]);
        output[i] = temp;
    }

    delete[] bulletinBoard;
    bulletinBoard = output;
}
//----------------------------------------------------------
void Member::addStatus()
{
    Status status;
    status.createStatus();
    if (numOfStatuses == 0)
        bulletinBoard = new Status[numOfStatuses];

    else
        Member::transferStatuses();

    bulletinBoard[numOfStatuses++] = status;
}
//----------------------------------------------------------
//----------------------------------------------------------
//----------------------------------------------------------