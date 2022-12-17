#include "../Headers/Status.h"

//Constructors

//------------------------------------------------------
Status::Status(const Date& _date) : statusDate(_date) {}
//------------------------------------------------------
Status::Status(const Date& _date, const Time& _time, const Byte& _status, const string& _content)
    :
    statusDate(_date),
    statusTime(_time),
    statusType((STATUS_TYPE)_status),
    statusContent(_content)
{
}
Status::Status(const Date& _date, const Time& _time, const string& _content) 
    :
    statusDate(_date),
    statusTime(_time),
    statusContent(_content)
{
}
//------------------------------------------------------
Status::Status(const string& statusContent) : statusContent(statusContent) //Constructor.
{
    setTimeAndDate(this->statusTime, this->statusDate);
}
//------------------------------------------------------
ostream& operator<<(ostream& os, const Status& obj)
{
    const Date& date = obj.getStatusDate();
    const Time& time = obj.getStatusTime();
    cout << "\tCreated in date: " << flush;
    cout << date.day << "/" << date.month << "/" << date.year << " " << flush;
    cout << time.hour << ":" << time.minutes << ":" << time.seconds << endl;
    cout << "\tStatus content: " << obj.getStatusContent();
    return os;
}

//General methods
//------------------------------------------------------
