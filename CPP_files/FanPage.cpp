#include "../Headers/FanPage.h"

//Constructors & Destructor
//----------------------------------------------------------
FanPage::FanPage(const FanPage& obj): //Copy Constructor.
   numOfMembers(obj.numOfMembers),
   numOfStatuses(obj.numOfStatuses)
{  
    this->name = new char[strlen(obj.name) + 1];
    checkMem(this->name);
    strcpy(this->name, obj.name);
    
    this->members = new Member * [numOfMembers];
    checkMem(this->members);
    for (size_t i = 0; i < numOfMembers; i++)
    {
        this->members[i] = obj.members[i];
    }

    this->bulletinBoard = new Status * [numOfStatuses];
    checkMem(this->bulletinBoard);
    for (size_t i = 0; i < numOfStatuses; i++)
    {
        this->bulletinBoard[i] = obj.bulletinBoard[i];
    }
}
//-----------------------------------------------------------
FanPage::FanPage(const char* _name) //Constructor.
{
    this->name = new char[strlen(_name) + 1];
    checkMem(this->name);
    strcpy(this->name, _name);
    this->members = new Member * [1];
    checkMem(this->members);
    this->bulletinBoard = new Status * [1];
    checkMem(this->bulletinBoard);
}
//-----------------------------------------------------------


//FanPage-to-FanPage Methods
//-----------------------------------------------------------
bool FanPage::findIndexAndRemoveFAN(Member * member)
{
   
    bool deleted = false;
    for (size_t i = 0; i < this->numOfMembers && !deleted; i++)
    {
        if (members[i] == member)
        {
            delete members[i];
            members[i] = members[this->numOfMembers - 1];
            this->numOfMembers--;
            deleted = true;
        }
    }
    return deleted;
}

//-----------------------------------------------------------
//FanPage-to-Member Methods
//-----------------------------------------------------------
bool FanPage::checkIfFan(Member *member) //Checks whether member is a fan of the page.
{
    bool output = false;

    for (size_t i = 0; i < numOfMembers && !output; i++)
        if (members[i] == member)
            output = true;

    return output;
}
//-----------------------------------------------------------
void FanPage::addMember(Member *member) //Adds a new member to members array.
{
    if (numOfMembers > 0)
        transferMembers();

    members[numOfMembers++] = member;
}
//-----------------------------------------------------------


// FanPage-to-Status Methods
//----------------------------------------------------------
void FanPage::printStatuses() const //Prints all fan page's statuses.
{
    size_t _numOfStatuses = this->getNumOfStatuses();

    for (size_t i = 0; i < _numOfStatuses; i++)
    {
        cout << "Status #" << i + 1 << ":" << endl;
        cout << this->bulletinBoard[i]->getStatus() << endl;
        this->bulletinBoard[i]->printDate(
            this->bulletinBoard[i]->getStatusDate(),
                this->bulletinBoard[i]->getStatusTime());
    }
}
//----------------------------------------------------------
void FanPage::addStatus()
{
    auto* newStatus = new Status;
    newStatus->Status::createStatus();
    if (numOfStatuses > 0)
       FanPage::transferStatuses();

    bulletinBoard[numOfStatuses++] = newStatus;
}
//----------------------------------------------------------


//Private Methods
//----------------------------------------------------------
void FanPage::transferMembers() //Re-allocates memory for members array.
{
    auto* output = new Member * [numOfMembers + 1];
    checkMem(output);

    for (size_t i = 0; i < numOfMembers; i++)
        output[i] = members[i];

    delete[] members;
    members = output;
}
//----------------------------------------------------------
void FanPage::transferStatuses() //Re-allocating memory for status arr.
{
    auto* output = new Status * [numOfStatuses + 1];
    checkMem(output);

    for (size_t i = 0; i < numOfStatuses; i++)
        output[i] = bulletinBoard[i];

    delete[] bulletinBoard;
    bulletinBoard = output;
}
//----------------------------------------------------------