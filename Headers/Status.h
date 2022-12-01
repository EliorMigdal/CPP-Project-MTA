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
    //Constructors
    Status() = default;
    Status(const Status& obj) = delete;
    explicit Status(const Date& _date);
    Status(const Date& _date, const Time& _time, const Byte& _status, const char* _content);
    explicit Status(const char* statusContent);
    ~Status();


    //Getters
    char* getStatus() const { return statusContent; }
    Date getStatusDate() const { return statusDate; }
    Time getStatusTime() const { return statusTime; }

    //General Methods
    void printDate(const Date& date, const Time& time) const;
    void createStatus();
};

#endif