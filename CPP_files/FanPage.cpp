#include "../Headers/FanPage.h"


//Constructors:
//----------------------------------------------------------
//Copy constructor
FanPage::FanPage(const FanPage& obj): 
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
FanPage::FanPage(const char* _name)
{
    this->name = new char[strlen(_name) + 1];
    checkMem(this->name);
    strcpy(this->name, _name);
}
//-----------------------------------------------------------

// Methods: 
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
//void FanPage::printMembers() const
//{
//}
//----------------------------------------------------------