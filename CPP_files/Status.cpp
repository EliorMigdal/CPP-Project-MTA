#include "../Headers/Status.h"

//constructors
//------------------------------------------------------
Status::Status(const Status& obj) :
    statusDate(obj.statusDate),
    statusTime(obj.statusTime),
    statusType(obj.statusType)                           
{
    this->statusContent = new char[strlen(obj.statusContent) + 1];
    checkMem(this->statusContent);
    strcpy(this->statusContent, obj.statusContent);
}
//------------------------------------------------------
Status::Status(const Date& _date) : statusDate(_date) {}
//------------------------------------------------------
Status::Status(const Date& _date, const Time& _time) :
 statusDate(_date),
 statusTime(_time)
 {
    this->statusContent = new char[0];
 }
//------------------------------------------------------
Status::Status(const Date& _date, const Time& _time, const Byte& _status)
    :
    statusDate(_date),
    statusTime(_time),
    statusType((STATUS_TYPE)_status)
    {
        this->statusContent = new char[0];
    }
//------------------------------------------------------
Status::Status(const Date& _date, const Time& _time, const Byte& _status, const char* _content)
    :
    statusDate(_date),
    statusTime(_time),
    statusType((STATUS_TYPE)_status)
{
    this->statusContent = new char[strlen(_content) + 1];
    checkMem(this->statusContent);
    strcpy(this->statusContent, _content);
}
//------------------------------------------------------
// 
//Public methods.
// ------------------------------------------------------------
void Status::printDate(const Date& date, const Time& time) const
{
    cout << date.day << "/" << date.month << "/" << date.year << endl;
    cout << time.hour << ":" << time.minutes << ":" << time.seconds << endl;
}
//----------------------------------------------------------
void Status::createStatus()// not yet modified
{
    char* name = nullptr;
    
    //name = readName();
    Date statusDate;
    /*cin.ignore();
    Member m1(name, Birthday);
    System::addMemberToArray(m1);*/
}
//----------------------------------------------------------