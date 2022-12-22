#include "../Headers/Status.h"

//Constructors
//------------------------------------------------------
Status::Status(Date& _date):statusDate(_date){}
//------------------------------------------------------
Status::Status(Date& _date, Time& _time, Byte& _statusType, const string& _content):
    statusDate(_date), statusTime(_time),
    statusType((STATUS_TYPE)_statusType), statusContent(_content){}
//------------------------------------------------------
Status::Status(Date& _date, Time& _time, const string& _content):statusDate(_date),
statusTime(_time), statusContent(_content){}
//------------------------------------------------------
Status::Status(const string& _statusContent):statusContent(_statusContent)
{
    setTimeAndDate(this->statusTime, this->statusDate);
}
//------------------------------------------------------

//Operators Methods
//------------------------------------------------------
ostream& operator<<(ostream& os, const Status& obj) //Print operator.
{
    const Date& date = obj.getStatusDate();
    const Time& time = obj.getStatusTime();
    cout << "\tCreated in date: " << flush;
    cout << date.day << "/" << date.month << "/" << date.year << " " << flush;
    cout << time.hour << ":" << time.minutes << ":" << time.seconds << endl;
    cout << "\tStatus content: " << obj.getStatusContent();
    return os;
}
//------------------------------------------------------
bool Status::operator==(Status & _status) const //Status == Status operator.
{
    return this->getStatusContent() == _status.getStatusContent();
}
//------------------------------------------------------
bool Status::operator!=(Status & _status) const //Status != Status operator.
{
    return this->getStatusContent() != _status.getStatusContent();
}
//------------------------------------------------------