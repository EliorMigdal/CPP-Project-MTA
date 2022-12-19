#include "../Headers/Member.h"

//Constructors & Destructor
// ----------------------------------------------------------
Member::Member(const string _name, Date &_birthday): name(_name),birthday(_birthday) //Constructor.
{
}

//----------------------------------------------------------
Member::Member(const string& _name) : name(_name) //Constructor.
{
}
//-------------------------------------------------------------

//Member-to-Member Methods
//----------------------------------------------------------
void Member::addFriend( const Member& memberToAdd) //Adds a new friends to the friends array.
{
    this->friends[memberToAdd.getName()] = memberToAdd;
}
//----------------------------------------------------------
void Member::removeFriend(const string& memberToRemove) //Removes a friend from the friends array.
{
    this->friends.erase(memberToRemove);
}
//----------------------------------------------------------
bool Member::checkIfFriend(const string& member_name) //Searches for a member in other member's friends array.
{
    return this->friends.find(member_name) != this->friends.end();
}
//----------------------------------------------------------
void Member::printFriendsArr() const //Prints friends's names.
{
    if (this->friends.empty())
        cout << this->getName() << " has no friends." << endl;
    else
    {
        cout << "----------------------------------\n" << this->getName() << "'s friends are:\n----------------------------------" << endl;
        for (const auto& key : this->friends)
        {
            cout <<"\t" << key.first << endl;
        }
    }
}
//----------------------------------------------------------

//Member-to-Status Methods
//----------------------------------------------------------
void Member::printStatuses(const size_t& numToPrint = PRINT_STATUS) const //Prints member's statuses.
{
    if (this->bulletinBoard.empty())
        cout << this->Member::getName() << " has not posted any statuses." << endl;

    else 
    {
        size_t _numOfStatuses = this->bulletinBoard.size();
        size_t logicPrintSize = 0;
        if (_numOfStatuses < PRINT_STATUS)
        {
            logicPrintSize = _numOfStatuses;
            cout << this->Member::getName() << " has only posted " << _numOfStatuses << " statuses:" << endl;
        }

        else
        {
            logicPrintSize = numToPrint;
            cout << this->Member::getName() << "'s last " << numToPrint << " statuses:" << endl;
        }
        size_t to_Run = _numOfStatuses - logicPrintSize;
        {
            using reverseStatusIter = vector<Status>::const_reverse_iterator;
            reverseStatusIter begin = this->bulletinBoard.rbegin();
            reverseStatusIter end = this->bulletinBoard.rend();
            for (reverseStatusIter rit = begin; rit != end && (to_Run < _numOfStatuses); ++rit)
            {
                cout << "------------------------------------\n\tStatus #" << _numOfStatuses-- << "\n------------------------------------" << endl <<
                    *rit << endl;
            }
        }
    }
}
//----------------------------------------------------------
void Member::addStatus() //Creates a new status.
{
    Date newDate;
    Time newTime;
    string statusContent;
    cout << "Please enter a your Status content:" << endl;
    getline(cin, statusContent);
    setTimeAndDate(newTime, newDate);
    this->bulletinBoard.emplace_back((newDate, newTime, statusContent));
    cout << "Status uploaded successfully!" << endl;
}
//----------------------------------------------------------
void Member::addStatus(const string& statusContent) //For hard-coded data.
{
    Date newDate;
    Time newTime;
    setTimeAndDate(newTime, newDate);
    this->bulletinBoard.emplace_back((newDate, newTime, statusContent));
}


//Member-to-FanPage Methods
//----------------------------------------------------------
void Member::addPage(FanPage* fanPage_obj, const string& page_name) //Adds a new page to the pages array.
{
    this->pages[page_name] = fanPage_obj;
}
//----------------------------------------------------------
bool Member::removePage(const string& fanPage_name) //Removes a page from the page array.
{
    if (this->pages.find(fanPage_name) != this->pages.end())
    {
        this->pages.erase(fanPage_name);
        return true;
    }
    return false;
}
//----------------------------------------------------------