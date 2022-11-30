#include "../Headers/Member.h"

//Constructors & Destructor
// ----------------------------------------------------------
Member::Member(const char* _name, Date &_birthday): birthday(_birthday) //Constructor.
{
    this->name = new char[strlen(_name) + 1];
    checkMem(this->name);
    this->friends = new Member * [1];
    checkMem(this->friends);
    this->bulletinBoard = new Status * [1];
    checkMem(this->bulletinBoard);
    this->pages = new FanPage * [1];
    checkMem(this->pages);
    strcpy(this->name, _name);
}
//----------------------------------------------------------
Member::Member(const char* _name) //Constructor.
{
    this->name = new char[strlen(_name) + 1];
    checkMem(this->name);
    this->friends = new Member * [1];
    checkMem(this->friends);
    this->bulletinBoard = new Status * [1];
    checkMem(this->bulletinBoard);
    this->pages = new FanPage * [1];
    checkMem(this->pages);
    strcpy(this->name, _name);

}
//----------------------------------------------------------
Member::Member(const Member& obj) : //Copy Constructor.
    birthday(obj.birthday),
    numOfFriends(obj.numOfFriends),
    numOfPages(obj.numOfPages),
    numOfStatuses(obj.numOfStatuses)
{
    this->name = new char[strlen(obj.name) + 1];
    checkMem(this->name);
    strcpy(this->name, obj.name);

    this->bulletinBoard = new Status * [numOfStatuses];
    checkMem(this->bulletinBoard);
    for (size_t i = 0; i < numOfStatuses; i++)
    {
        this->bulletinBoard[i] = new Status;
        checkMem(this->bulletinBoard[i]);
        this->bulletinBoard[i] = obj.bulletinBoard[i];
    }

    this->friends = new Member * [numOfFriends];
    checkMem(this->friends);
    for (size_t i = 0; i < numOfFriends; i++) //No need for allocation - Friends will be an array of pointers to objects from system.
    {
        this->friends[i] = obj.friends[i];
    }

    this->pages = new FanPage * [numOfPages];
    checkMem(this->pages);
    for (size_t i = 0; i < numOfPages; i++) //No need for allocation - Pages will be an array of pointers to objects from system.
    {
        this->pages[i] = obj.pages[i];
    }
}
//-------------------------------------------------------------
Member::~Member() //Destructor
{
    delete name;
    delete[] friends;
    delete[] pages;

    for (size_t i = 0; i < numOfStatuses; i++)
        delete bulletinBoard[i];

    delete[] bulletinBoard;
}
//----------------------------------------------------------


//Member-to-Member Methods
//----------------------------------------------------------
void Member::addFriend(Member* memberToAdd) //Adds a new friends to the friends array.
{
    if (numOfFriends > 0)
        Member::transferFriends();

        friends[numOfFriends++] = memberToAdd;
}
//----------------------------------------------------------
void Member::removeFriend(Member* memberToRemove) //Removes a friend from the friends array.
{
    auto* output = new Member * [this->numOfFriends - 1];
    size_SI index = 0;

    for (size_t i = 0; i < numOfFriends; i++)
    {
        if (this->friends[i] != memberToRemove)
        {
            output[index] = this->friends[i];
            index++;
        }
    }
    this->numOfFriends--;
    delete[] this->friends;
    this->friends = output;
}
//----------------------------------------------------------
bool Member::checkIfFriend(const Member *member) //Searches for a member in other member's friends array.
{
    bool found = false;

    for (size_t i = 0; i < numOfFriends && !found; i++)
    {
        if (friends[i] == member)
            found = true;
    }

    return found;
}
//----------------------------------------------------------
void Member::printFriendsArr() const //Prints friends's names.
{
    if (this->numOfFriends == 0)
        cout << this->getName() << " has no friends." << endl;

    else
        cout << this->getName() << "'s friends are:" << endl;

    for (size_t i = 0; i < numOfFriends; i++)
        cout << friends[i]->getName() << endl;
}
//----------------------------------------------------------


//Member-to-Status Methods
//----------------------------------------------------------
inline void Member::printStatus(const size_t& index) const //Prints a status.
{
    cout << "Created in date: " << flush;
    this->bulletinBoard[index - 1]->Status::printDate(
        this->bulletinBoard[index - 1]->Status::getStatusDate(),
            this->bulletinBoard[index - 1]->Status::getStatusTime());
    cout << "Status content: " << this->bulletinBoard[index - 1]->Status::getStatus() << endl;
}
//----------------------------------------------------------
void Member::printStatuses(const size_t& numToPrint) const //Prints member's statuses.
{
    size_t _numOfStatuses = this->Member::getNumOfStatuses();
    size_t logicPrintSize = 0;
    if (_numOfStatuses == 0)
        cout << this->Member::getName() << " has not posted any statuses." << endl;

    else if (numToPrint == PRINT_STATUS)
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

        for (size_t i = _numOfStatuses; i > _numOfStatuses - logicPrintSize; i--)
        {
            cout << "Status #" << i << ":" << endl;
            this->Member::printStatus(i);
        }
    }
}
//----------------------------------------------------------
void Member::addStatus() //Creates a new status.
{
    auto* newStatus = new Status;
    checkMem(newStatus);

    newStatus->Status::createStatus();
    if (numOfStatuses > 0)
        Member::transferStatuses();

    bulletinBoard[numOfStatuses++] = newStatus;
    cout << this->name << " Uploaded status successfully." << endl;
}
//----------------------------------------------------------
void Member::addStatus(const char *statusContent) //For hard-coded data.
{
    auto* newStatus = new Status(statusContent);
    checkMem(newStatus);

    if (numOfStatuses > 0)
        Member::transferStatuses();

    bulletinBoard[numOfStatuses++] = newStatus;
}


//Member-to-FanPage Methods
//----------------------------------------------------------
void Member::addPage(FanPage *fanPage) //Adds a new page to the pages array.
{
    if (numOfPages > 0)
        transferPages();

    pages[numOfPages++] = fanPage;
}
//----------------------------------------------------------
void Member::removePage(FanPage *fanPage) //Removes a page from the page array.
{
    auto* output = new FanPage * [numOfPages - 1];
    checkMem(output);
    size_t index = 0;

    for (size_t i = 0; i < numOfPages; i++)
        if (fanPage != pages[i])
        {
            output[index] = pages[i];
            index++;
        }

    delete[] pages;
    pages = output;
    numOfPages--;
}
//----------------------------------------------------------


//Private Methods
//----------------------------------------------------------
void Member::transferFriends() //Re-allocates memory for friends array.
{
    auto* output = new Member * [numOfFriends + 1];
    checkMem(output);

    for(size_t i = 0; i < numOfFriends; i++)
        output[i] = friends[i];

    delete[] friends;
    friends = output;
}
//----------------------------------------------------------
void Member::transferStatuses() //Re-allocating memory for status arr.
{
    auto* output = new Status * [numOfStatuses + 1];
    checkMem(output);

    for(size_t i = 0; i < numOfStatuses; i++)
        output[i] = bulletinBoard[i];

    delete[] bulletinBoard;
    bulletinBoard = output;
}
//----------------------------------------------------------
void Member::transferPages() //Re-allocating memory for pages arr.
{
    auto* output = new FanPage * [numOfPages + 1];
    checkMem(output);

    for (size_t i = 0; i < numOfPages; i++)
        output[i] = pages[i];

    delete[] pages;
    pages = output;
}
//----------------------------------------------------------