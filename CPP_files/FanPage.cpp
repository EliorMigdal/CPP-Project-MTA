#include "../Headers/FanPage.h"

//Constructors
//-----------------------------------------------------------
FanPage::FanPage(const string& _name):name(_name){}
//-----------------------------------------------------------

//FanPage-to-Member Methods
//-----------------------------------------------------------
bool FanPage::checkIfFan(const string& member_name) //Checks whether member is a fan of the page.
{
    return members.find(member_name) != members.end();
}
//-----------------------------------------------------------
void FanPage::removeFan(const Member& _member) //Removes a fan from members array.
{
    this->members.erase(_member.getName());
}
//-----------------------------------------------------------
void FanPage::addFan(const Member& member) //Adds a new member to members array.
{
    this->members[member.getName()] = member;
}
//----------------------------------------------------------

//FanPage-to-Status Methods
//----------------------------------------------------------
void FanPage::printStatuses() const //Prints all fan page's statuses.
{
    size_t i = 0;
    if (this->bulletinBoard.empty())
        throw std::invalid_argument("Fan page has not posted any statuses.");

    else
        cout << "-------------------------------------\n" << this->FanPage::getName()
        << " has posted " << this->bulletinBoard.size() << " statuses:" << endl;

    for (const auto& status: this->bulletinBoard)
    {
        cout << "------------------------------------\n\tStatus #" << ++i <<
        "\n------------------------------------" << endl << status << endl;
    }
}
//---------------------------------------------------------- 
void FanPage::addStatus() //Adds a status to a fan page.
{
    Date newDate;
    Time newTime;
    string statusContent;
    cout << "Please enter a your Status content:" << endl;
    getline(cin, statusContent);
    setTimeAndDate(newTime, newDate);
    this->bulletinBoard.emplace_back((newDate, newTime, statusContent));
}
//----------------------------------------------------------
void FanPage::addStatus(const string& statusContent) //For hard coded data.
{
    Date newDate;
    Time newTime;
    setTimeAndDate(newTime, newDate);
    this->bulletinBoard.emplace_back((newDate, newTime, statusContent));
}
//----------------------------------------------------------

//Operators Methods
//-----------------------------------------------------------
ostream& operator<<(ostream& _out, FanPage& _fanPage) //Print method.
{
    return _out << _fanPage.FanPage::getName();
}
//-----------------------------------------------------------
const FanPage& FanPage::operator+=(const Member& _member) //FanPage += Member method.
{
    this->FanPage::addFan(_member);
    return *this;
}
//-----------------------------------------------------------
const FanPage &FanPage::operator-=(const Member & _member) //FanPage -= Member method.
{
    this->FanPage::removeFan(_member);
    return *this;
}
//-----------------------------------------------------------
bool FanPage::operator<(FanPage & _fanPage) const //FanPage < FanPage operator.
{
    return this->FanPage::getNumOfMembers() < _fanPage.FanPage::getNumOfMembers();
}
//-----------------------------------------------------------
bool FanPage::operator<=(FanPage & _fanPage) const //FanPage <= FanPage operator.
{
    return this->FanPage::getNumOfMembers() <= _fanPage.FanPage::getNumOfMembers();
}
//-----------------------------------------------------------
bool FanPage::operator>(FanPage & _fanPage) const //FanPage > FanPage operator.
{
    return this->FanPage::getNumOfMembers() > _fanPage.FanPage::getNumOfMembers();
}
//-----------------------------------------------------------
bool FanPage::operator>=(FanPage & _fanPage) const //FanPage >= FanPage operator.
{
    return this->FanPage::getNumOfMembers() >= _fanPage.FanPage::getNumOfMembers();
}
//-----------------------------------------------------------