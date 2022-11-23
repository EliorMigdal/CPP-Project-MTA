#include "../Headers/Status.h"
//----------------------------------------------------------
void Status::printDate(Date date, Time time)
{
    cout << date.day << "/" << date.month << "/" << date.year << endl;
    cout << time.hour << ":" << time.minutes << ":" << time.seconds << endl;
}
//----------------------------------------------------------
void Status::createStatus()
{
    string name;
    cout << "Creating a member: \nEnter name: " << flush;
    std::getline(cin, name);
    Date statusDate;
    /*cin.ignore();
    Member m1(name, Birthday);
    System::addMemberToArray(m1);*/
}