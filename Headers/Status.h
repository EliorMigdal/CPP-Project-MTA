#ifndef CPP_PROJECT_STATUS_H
#define CPP_PROJECT_STATUS_H
#include "GlobalVariables.h"

class Status {
private:
    Date statusDate = {0,0,0};
    Time statusTime = {0,0,0};
    STATUS_TYPE statusType = STATUS_TYPE::TEXT;
    char* statusContent = nullptr;

public:
    Status() {} //Default constructor.

    Status(Status& obj) //Copy constructor
    {
        this->statusDate = obj.statusDate;
        this->statusTime = obj.statusTime;
        this->statusType = obj.statusType;
        this->statusContent = obj.statusContent;
    }

    Status(const Date& _date)
    {
        statusDate = _date;
    }

    Status(const Date& _date, const Time& _time)
    {
        statusDate = _date;
        statusTime = _time;
    }

    Status(const Date& _date, const Time& _time, const Byte& _status)
    {
        statusDate = _date;
        statusTime = _time;
        statusType = (STATUS_TYPE)_status;
    }

    Status(const Date& _date,const Time& _time, const Byte& _status, const char*& _content)
    {
        statusDate = _date;
        statusTime = _time;
        statusType = (STATUS_TYPE)_status;
       /* statusContent = _content;*/
    }

    char* getStatus() const { return this->statusContent; }
    Date getStatusDate() const { return this->statusDate; }
    Time getStatusTime() const { return this->statusTime; }
    void printDate(Date date, Time time);
    void createStatus();
};

#endif