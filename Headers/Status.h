#ifndef CPP_PROJECT_STATUS_H
#define CPP_PROJECT_STATUS_H
#include "GlobalVariables.h"

class Status {
private:
    Date statusDate;
    Time statusTime;
    STATUS_TYPE statusType = STATUS_TYPE::TEXT;
    string statusContent;

public:
    //Constructors
    Status() = default;
    Status(const Status&) = default;
    Status(Status&&) noexcept = default;
    explicit Status(Date&);
    Status(Date&, Time&, const string&);
    Status(Date&, Time&, const string&, STATUS_TYPE&);
    Status(Date&, Time&, Byte&, const string&);
    explicit Status(const string&);
    virtual ~Status() = default;

    //Getters
    const string& getStatusContent() const { return statusContent; }
    const Date& getStatusDate() const { return statusDate; }
    const Time& getStatusTime() const { return statusTime; }

   /* virtual void showContent() const;*/
    //Operators Methods
    // << Operator
    friend ostream& operator<<(ostream&, const Status&);
    // = Operator
    Status& operator=(Status&& status) = default;
    Status& operator=(const Status& status) = default;
    // Boolean Operators
    virtual bool operator==(const Status&) const;
    virtual bool operator!=(const Status&) const;
};
//class VideoStatus :public Status {
//
//public:
//    VideoStatus() = default;
//    ~VideoStatus() override = default;
//    virtual void showContent() const override;
//
//
//
//};
//class ImageStatus :public Status {
//
//public:
//    ImageStatus() = default;
//    ~ImageStatus() override = default;
//
//
//
//
//};

class StatusExceptions : public std::exception {
public:
    const char* what() const noexcept override { return "Status error."; }
};
class EmptyStatus :public StatusExceptions {
public:
    const char* what() const noexcept override { return "Cannot enter an empty status."; }
};
#endif