#include "../Headers/Status.h"

//Constructors
//------------------------------------------------------
Status::Status(Date& _date, Time& _time, string& _content, STATUS_TYPE& _type) :
    statusDate(_date), statusTime(_time), statusContent(_content), statusType(_type) {}
//------------------------------------------------------
VideoStatus::VideoStatus(Date &_date, Time &_time, std::string &_content, STATUS_TYPE &_type, std::string &_fileName)
:Status(_date, _time, _content, _type), fileName(_fileName){}
void VideoStatus::saveFileNameToFile(ofstream& out)
{
    out.write(fileName.c_str(), fileName.size() + 1);
}
void VideoStatus::loadFileNameFromFile(ifstream& in)
{
    getline(in, fileName, '\0');
}
//------------------------------------------------------
ImageStatus::ImageStatus(Date &_date, Time &_time, std::string &_content, STATUS_TYPE &_type, std::string &_fileName)
        :Status(_date, _time, _content, _type), fileName(_fileName){}
void ImageStatus::saveFileNameToFile(ofstream& out)
{
    out.write(fileName.c_str(), fileName.size() + 1);
}
void ImageStatus::loadFileNameFromFile(ifstream& in)
{
    getline(in, fileName, '\0');
}
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
void Status::saveStatusToFile(ofstream& out)
{
    out.write(reinterpret_cast<const char*>(&statusType), sizeof(statusType));
    out.write(reinterpret_cast<const char*>(&statusDate), sizeof(statusDate));
    out.write(reinterpret_cast<const char*>(&statusTime), sizeof(statusTime));
    out.write(reinterpret_cast<const char*>(&statusType), sizeof(statusType));
    out.write(statusContent.c_str(), statusContent.size() + 1);
    if (statusType == STATUS_TYPE::IMAGE)
    {
        dynamic_cast<ImageStatus*>(this)->saveFileNameToFile(out);
    }

    else if (statusType == STATUS_TYPE::VIDEO)
    {
        dynamic_cast<VideoStatus*>(this)->saveFileNameToFile(out);
    }   
}
void Status::readStatusFromFile(ifstream& in)
{
    in.read(reinterpret_cast<char*>(&statusDate), sizeof(statusDate));
    in.read(reinterpret_cast<char*>(&statusTime), sizeof(statusTime));
    in.read(reinterpret_cast<char*>(&statusType), sizeof(statusType));
    getline(in, statusContent, '\0');

    if (statusType == STATUS_TYPE::IMAGE)
    {
        dynamic_cast<ImageStatus*>(this)->loadFileNameFromFile(in);
    }

    else if (statusType == STATUS_TYPE::VIDEO)
        dynamic_cast<VideoStatus*>(this)->loadFileNameFromFile(in);

}
//------------------------------------------------------
bool Status::operator==(const Status& _status) const //Status == Status operator.
{
    return (this->Status::getStatusContent() == _status.Status::getStatusContent())
    && (this->Status::getStatusType() == _status.Status::getStatusType());
}
//------------------------------------------------------
bool Status::operator!=(const Status& _status) const //Status != Status operator.
{
    return (this->Status::getStatusContent() != _status.Status::getStatusContent())
           && (this->Status::getStatusType() != _status.Status::getStatusType());
}
//------------------------------------------------------