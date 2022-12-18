#include "../Headers/FanPage.h"

//Constructors & Destructor

//-----------------------------------------------------------

FanPage::FanPage(const string& _name): name(_name) //Constructor.
{}
//FanPage-to-Member Methods
//-----------------------------------------------------------
bool FanPage::checkIfFan(const string& member_name) //Checks whether member is a fan of the page.
{
    return members.find(member_name) != members.end();
}
bool FanPage::removeFan(const string& member_to_remove)
{
    if (FanPage::checkIfFan(member_to_remove))
    {
         members.erase(member_to_remove);
         return true;
    }
    return false;
}
//-----------------------------------------------------------
void FanPage::addFan( const Member& member) //Adds a new member to members array.
{

    this->members[member.getName()] = member;
}
//----------------------------------------------------------

// FanPage-to-Status Methods
//----------------------------------------------------------
void FanPage::printStatuses() const //Prints all fan page's statuses.
{
    size_t i = 0;
    if (this->bulletinBoard.empty())
        cout << this->FanPage::getName() << " has not posted any statuses." << endl;
    else
        cout << "-------------------------------------\n" << this->FanPage::getName() << " has posted " << this->bulletinBoard.size() << " statuses:" << endl;
    for (const auto& status: bulletinBoard)
    {
        cout << "------------------------------------\n\tStatus #" << ++i << "\n------------------------------------" << endl << status << endl;
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
    this->bulletinBoard.emplace_back((newDate,newTime,statusContent));
    cout << "Status uploaded successfully!" << endl;
}
//----------------------------------------------------------
void FanPage::addStatus(const string& statusContent) //For hard coded data.
{
    Date newDate;
    Time newTime;
    setTimeAndDate(newTime, newDate);
    this->bulletinBoard.emplace_back((newDate, newTime, statusContent));
}
