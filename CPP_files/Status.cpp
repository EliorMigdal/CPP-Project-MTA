#include "../Headers/Status.h"

//Constructors
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
Status::~Status() //Destructor
{
    delete[] statusContent;
}
//------------------------------------------------------


//General methods
// ------------------------------------------------------------
void Status::printDate(const Date& date, const Time& time) const //Prints status's date.
{
    cout << date.day << "/" << date.month << "/" << date.year<< " "<< flush;
    cout << time.hour << ":" << time.minutes << ":" << time.seconds << endl;
}
//----------------------------------------------------------
void Status::createStatus() //Creates a new status.
{
   cout << "Please enter a your Status content:" << endl;
   this->statusContent = readString(DEFAULT_FLUSH);
   setTimeAndDate(this->statusTime, this->statusDate);
}
//----------------------------------------------------------