#include "../Headers/Status.h"

//Constructors
//------------------------------------------------------
Status::Status(Date& _date):statusDate(_date){}
//------------------------------------------------------
Status::Status(const string& _statusContent):statusContent(_statusContent)
{
    setTimeAndDate(this->statusTime, this->statusDate);
}
//------------------------------------------------------
Status::Status(Date& _date, Time& _time, string& _content, STATUS_TYPE& _type) :
    statusDate(_date), statusTime(_time), statusContent(_content), statusType(_type) {}
//------------------------------------------------------
VideoStatus::VideoStatus(Date &_date, Time &_time, std::string &_content, STATUS_TYPE &_type, std::string &_fileName)
:Status(_date, _time, _content, _type), fileName(_fileName){}
//------------------------------------------------------
ImageStatus::ImageStatus(Date &_date, Time &_time, std::string &_content, STATUS_TYPE &_type, std::string &_fileName)
        :Status(_date, _time, _content, _type), fileName(_fileName){}
//------------------------------------------------------

//General Methods
//------------------------------------------------------
void VideoStatus::showContent(ostream& _out) const
{
    _out << "\tFile name: " << fileName << endl;
}
//------------------------------------------------------
void ImageStatus::showContent(ostream& _out) const
{
    _out << "\tFile name: " << fileName << endl;
}
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
    cout << "\tStatus content: " << obj.Status::getStatusContent() << endl;

    if (obj.getStatusType() != STATUS_TYPE::TEXT)
        obj.showContent(os);

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