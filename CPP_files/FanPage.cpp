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
FanPage::~FanPage() //Destructor.
{
    delete[] name;
    delete[] members;

    for (size_SI i = 0; i < numOfStatuses; i++)
        delete bulletinBoard[i];
    delete[] bulletinBoard;
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
bool FanPage::findIndexAndRemoveFAN(const Member * member) //Removes a member from a fanpage's members arr.
{
    auto* output = new Member * [this->numOfMembers - 1];
    size_t index = 0;
    bool deleted = false;

    for (size_t i = 0; i < this->numOfMembers; i++)
    {
        if (this->members[i] != member)
        {
            output[index] = this->members[i];
            index++;
        }

        else
            deleted = true;
    }

    this->numOfMembers--;
    delete[] this->members;
    this->members = output;
    return deleted;
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
void FanPage::addStatus() //Adds a status to a fanpage.
{
    auto* newStatus = new Status;
    checkMem(newStatus);

    newStatus->Status::createStatus();

    if (numOfStatuses > 0)
       FanPage::transferStatuses();

    bulletinBoard[numOfStatuses++] = newStatus;
}
//----------------------------------------------------------
void FanPage::addStatus(const char *statusContent) //For hard coded data.
{
    auto* newStatus = new Status(statusContent);
    checkMem(newStatus);

    if (numOfStatuses > 0)
        FanPage::transferStatuses();

    bulletinBoard[numOfStatuses++] = newStatus;
}


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