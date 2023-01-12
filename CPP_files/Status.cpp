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
Status::Status(Date &_date, Time &_time, const string &_content, STATUS_TYPE &_type):
statusDate(_date), statusTime(_time), statusContent(_content), statusType(_type){}
//------------------------------------------------------

//Operators Methods
//------------------------------------------------------
ostream& operator<<(ostream& os, const Status& obj) //Print operator.
{
    const Date& date = obj.Status::getStatusDate();
    const Time& time = obj.Status::getStatusTime();
    cout << "\tCreated in date: " << flush;
    cout << date.day << "/" << date.month << "/" << date.year << " " << flush;
    cout << time.hour << ":" << time.minutes << ":" << time.seconds << endl;
    cout << "\tStatus content: " << obj.Status::getStatusContent();
    return os;
}
//------------------------------------------------------
bool Status::operator==(const Status& _status) const //Status == Status operator.
{
    return this->Status::getStatusContent() == _status.Status::getStatusContent();
}
//------------------------------------------------------
bool Status::operator!=(const Status& _status) const //Status != Status operator.
{
    return this->Status::getStatusContent() != _status.Status::getStatusContent();
}
//------------------------------------------------------
//
//void VideoStatus::showContent() const
//{
//   
//}
