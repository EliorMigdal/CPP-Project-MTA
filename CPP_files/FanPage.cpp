#include "../Headers/FanPage.h"
#include "../Headers/Member.h"

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
void FanPage::addFan(Member* _member) //Adds a new member to members array.
{
    if (!this->FanPage::checkIfFan(_member->getName()))
        this->members[_member->getName()] = _member;

    else
        throw addAFanException();
}
//----------------------------------------------------------
void FanPage::removeFan(Member* _member) //Removes a fan from members array.
{
    if (this->FanPage::checkIfFan(_member->getName()))
        this->members.erase(_member->getName());

    else
        throw removeAFanException();
}
//-----------------------------------------------------------
void FanPage::printFans() const //Prints a fan page's fans.
{
    if (this->members.empty())
        throw printFansException();

    else
    {
        cout << "------------------------------------\n"
             << this->getName() << "'s fans list:\n------------------------------------" << endl;
        for (const auto& kv : this->members)
        {
            const auto& key = kv.first;
            cout << "\t" << key << endl;
        }
    }
}
//-----------------------------------------------------------
//FanPage-to-Status Methods
//----------------------------------------------------------
void FanPage::printStatuses() const //Prints all fan page's statuses.
{
    size_t i = 0;
    if (this->bulletinBoard.empty())
        throw fanPagePrintStatusesException();

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
    if (!statusContent.empty())
    {
        setTimeAndDate(newTime, newDate);
        this->bulletinBoard.emplace_back((newDate, newTime, statusContent));
    }
    else
        throw EmptyStatus();
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
ostream& operator<<(ostream& _out, FanPage* _fanPage) //Print method.
{
    return _out << _fanPage->FanPage::getName();
}
//-----------------------------------------------------------
const FanPage& FanPage::operator+=(Member* _member) //FanPage += Member method.
{
    try{this->FanPage::addFan(_member);}
    catch(addAFanException& error) {throw addAFanException(error);}
    catch(...) {throw GlobalExceptions();}
    return *this;
}
//-----------------------------------------------------------
const FanPage &FanPage::operator-=(Member* _member) //FanPage -= Member method.
{
    try{ this->FanPage::removeFan(_member); }
    catch (removeAFanException& error) { throw removeAFanException(error);}
    catch (...) {throw GlobalExceptions();}
    return *this;
}
//-----------------------------------------------------------
bool FanPage::operator<(FanPage& _fanPage) const //FanPage < FanPage operator.
{
    return this->FanPage::getNumOfMembers() < _fanPage.FanPage::getNumOfMembers();
}
//-----------------------------------------------------------
bool FanPage::operator<=(FanPage& _fanPage) const //FanPage <= FanPage operator.
{
    return this->FanPage::getNumOfMembers() <= _fanPage.FanPage::getNumOfMembers();
}
//-----------------------------------------------------------
bool FanPage::operator>(FanPage& _fanPage) const //FanPage > FanPage operator.
{
    return this->FanPage::getNumOfMembers() > _fanPage.FanPage::getNumOfMembers();
}
//-----------------------------------------------------------
bool FanPage::operator>=(FanPage& _fanPage) const //FanPage >= FanPage operator.
{
    return this->FanPage::getNumOfMembers() >= _fanPage.FanPage::getNumOfMembers();
}
//-----------------------------------------------------------