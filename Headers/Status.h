#ifndef CPP_PROJECT_STATUS_H
#define CPP_PROJECT_STATUS_H
#include "GlobalVariables.h"

class Status {
private:
    Date statusDate = { "0","0","0" };
    Time statusTime = { "0","0","0" };
    STATUS_TYPE statusType = STATUS_TYPE::TEXT;
    string statusContent = "";

public:
    //Constructors
    Status() = default;
    Status(const Status& obj) = default;
    Status& operator=(Status&& status) = default;
    Status& operator=(const Status& status) = default;
    Status(Status&& status) = default;
    //-
    explicit Status(const Date&);
    Status(const Date&, const Time&, const string&);
    Status(const Date&, const Time&, const Byte&, const string&);
    explicit Status(const string&);
    ~Status() = default;

    //Getters
    const string getStatusContent() const { return statusContent; }
    const Date getStatusDate() const { return statusDate; }
    const Time getStatusTime() const { return statusTime; }

    //General Methods
    friend ostream& operator<<(ostream& os, const Status& obj);
};

#endif