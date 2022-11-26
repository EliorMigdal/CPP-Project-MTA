#include "../Headers/Member.h"
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//Constructors
//----------------------------------------------------------
Member::Member(const char* _name, Date &_birthday): birthday(_birthday)
{
    this->name = new char[strlen(_name) + 1];
    checkMem(this->name);
    strcpy(this->name, _name);
}
//----------------------------------------------------------
Member::Member(const char* _name) //Constructor.
{
    this->name = new char[strlen(_name) + 1];
    checkMem(this->name);
    strcpy(this->name, _name);
}
//----------------------------------------------------------
//Copy Constructor.
Member::Member(const Member& obj) :
    birthday(obj.birthday),
    numOfFriends(obj.numOfFriends),
    numOfPages(obj.numOfPages),
    numOfStatuses(obj.numOfStatuses)
{
    this->name = new char[strlen(obj.name) + 1];
    checkMem(this->name);
    strcpy(this->name, obj.name);
 
    this->bulletinBoard = obj.bulletinBoard;//Goes to the copy constructor of Statuses 
    //--- 
    //reallocating memory to copy to
    this->friends = new Member * [numOfFriends];
    checkMem(this->friends);
    for (size_t i = 0; i < numOfFriends; i++)
    {
        this->friends[i] = obj.friends[i];
    }
    //---
    pages = obj.pages; //Goes to the copy constructor of FanPage    
}
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//Destructor
//-------------------------------------------------------------
Member::~Member() {
    delete name;
}
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// Methods: 
//--------------------------------------------------------------------------------------
void Member::addFriend(Member* member) //Adds a new friends to the friends array.
{ 
    if (numOfFriends == 0)
        friends = new Member * [numOfFriends];

    else
        transferFriends();

    friends[numOfFriends++] = member;
}
//----------------------------------------------------------
void Member::transferFriends() //Re-allocates memory for friends array.
{
    auto* output = new Member * [numOfFriends + 1];

    for(int i = 0; i < numOfFriends; i++)
        output[i] = friends[i];

    delete[] friends;
    friends = output;
}
////----------------------------------------------------------
void Member::printStatus(const int& index) const
{
    cout << this->bulletinBoard[index]->Status::getStatus() << endl;
    this->bulletinBoard[index]->Status::printDate(
        this->bulletinBoard[index]->Status::getStatusDate(),
            this->bulletinBoard[index]->Status::getStatusTime());
}
////----------------------------------------------------------
void Member::printStatuses(size_SI numToPrint) const //Prints member's statuses.
{
    int _numOfStatuses = this->Member::getNumOfStatuses();
    int logicPrintSize = 0;
    if (_numOfStatuses == 0)
        cout << this->Member::getName() << " has not posted any statuses." << endl;

    if (numToPrint == PRINT_STATUS)
    {
        if (_numOfStatuses < PRINT_STATUS)
        {
            logicPrintSize = _numOfStatuses;
            cout << this->Member::getName() << " has only posted " << numOfStatuses << " statuses:" << endl;
        }

        else
        {
            logicPrintSize = PRINT_STATUS;
            cout << this->Member::getName() << "'s last " << PRINT_STATUS << " statuses:" << endl;
        }

        for (int i = _numOfStatuses - 1; i >= _numOfStatuses - logicPrintSize; i--)
        {
            cout << "Status #" << i + 1 << ":" << endl;
            this->Member::printStatus(i);
        }
    }
}
////------------------------------------------------------------------------
void Member::transferStatuses() //Re-allocating memory for status arr.
{
    auto* output = new Status * [numOfStatuses + 1];

    for(size_t i = 0; i < numOfStatuses; i++)
    {
       
        output[i] = bulletinBoard[i];
    }

    delete[] bulletinBoard;
    bulletinBoard = output;
}
////----------------------------------------------------------
void Member::addStatus()
{
    Status status;
    status.createStatus();
    if (numOfStatuses == 0)
        bulletinBoard = new Status * [numOfStatuses];

    else
        Member::transferStatuses();

    bulletinBoard[numOfStatuses++] = &status;
}
//----------------------------------------------------------
//----------------------------------------------------------
//----------------------------------------------------------