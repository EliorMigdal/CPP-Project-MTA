#ifndef CPP_PROJECT_STATUS_H
#define CPP_PROJECT_STATUS_H
#include "GlobalVariables.h"

class Status {
private:
    Date statusDate = { "0","0","0" };
    Time statusTime = { "0","0","0" };
    STATUS_TYPE statusType = STATUS_TYPE::TEXT;
    string statusContent;

public:
    //Constructors
    Status() = default;
    Status(const Status&) = default;
    Status(Status&&) = default;
    explicit Status(Date&);
    Status(Date&, Time&, const string&);
    Status(Date&, Time&, Byte&, const string&);
    explicit Status(const string&);
    ~Status() = default;

    //Getters
    const string& getStatusContent() const { return statusContent; }
    const Date& getStatusDate() const { return statusDate; }
    const Time& getStatusTime() const { return statusTime; }

    //Operators Methods
    // << Operator
    friend ostream& operator<<(ostream&, const Status&);
    // = Operator
    Status& operator=(Status&& status) = default;
    Status& operator=(const Status& status) = default;
    // Boolean Operators
    bool operator==(const Status&) const;
    bool operator!=(const Status&) const;
};

#endif