#include "../Headers/Member.h"

//Constructors
//----------------------------------------------------------
Member::Member(const string& _name, Date& _birthday):name(_name), birthday(_birthday){}
//----------------------------------------------------------
Member::Member(string& _name):name(_name){}
//----------------------------------------------------------

//Member-to-Member Methods
//----------------------------------------------------------
void Member::addFriend(const Member& memberToAdd) //Adds a new friends to the friends array.
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
void Member::printFriendsArr() const //Prints friends' names.
{
    if (this->friends.empty())
        cout << this->getName() << " has no friends." << endl;
    else
    {
        cout << "----------------------------------\n" << this->getName() << "'s friends are:\n----------------------------------" << endl;
        for (const auto& kv : this->friends)
        {
            cout <<"\t" << kv.first << endl;
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
        size_t logicPrintSize;
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
//----------------------------------------------------------

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

//Operators Methods
//----------------------------------------------------------
ostream& operator<<(ostream& out, const Member& _member) //Print operator.
{
    return out << _member.getName();
}
//----------------------------------------------------------
const Member &Member::operator+=(const Member & _member) //Member + Member operator.
{
    this->addFriend(_member);
    return *this;
}
//----------------------------------------------------------
const Member &Member::operator+=(const FanPage & _fanPage) //Member + FanPage operator.
{
    //Fix name issue.
}
//----------------------------------------------------------
const Member &Member::operator-=(const Member & _member) //Member - Member operator.
{
    this->removeFriend(_member.getName());
    return *this;
}
//----------------------------------------------------------
const Member &Member::operator-=(const FanPage & _fanPage) //Member - FanPage operator.
{
    //Fix name issue.
}
//----------------------------------------------------------
bool Member::operator<(const Member & _member) const //Member < Member operator.
{
    return this->getNumOfFriends() < _member.getNumOfFriends();
}
//----------------------------------------------------------
bool Member::operator<=(const Member & _member) const //Member <= Member operator.
{
    return this->getNumOfFriends() <= _member.getNumOfFriends();
}
//----------------------------------------------------------
bool Member::operator>(const Member & _member) const //Member > Member operator.
{
    return this->getNumOfFriends() > _member.getNumOfFriends();
}
//----------------------------------------------------------
bool Member::operator>=(const Member & _member) const //Member >= Member operator.
{
    return this->getNumOfFriends() >= _member.getNumOfFriends();
}
//----------------------------------------------------------