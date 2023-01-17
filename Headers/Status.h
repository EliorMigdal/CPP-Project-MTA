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
    Status(Date&, Time&, string&, STATUS_TYPE&);
    virtual ~Status() = default;

    //Setters
    void setStatusContent(string& str) {statusContent = str;}

    //Getters
    const string& getStatusContent() const { return statusContent; }
    const Date& getStatusDate() const { return statusDate; }
    const Time& getStatusTime() const { return statusTime; }
    const STATUS_TYPE& getStatusType() const { return statusType; }

    //General Methods
    virtual void showContent(ostream&) const {cout << *this;}

    //Operators
    friend ostream& operator<<(ostream&, const Status&);
    Status& operator=(Status&& status) = default;
    Status& operator=(const Status& status) = default;
    virtual bool operator==(const Status&) const;
    virtual bool operator!=(const Status&) const;
};

class VideoStatus : public Status {
    string fileName;
public:
    VideoStatus() = default;
    VideoStatus(Date&, Time&, string&, STATUS_TYPE&, string&);
    ~VideoStatus() override = default;

    string& getFileName() {return fileName;}
    void setFileName(string& _fileName) {fileName = _fileName;}
    void showContent(ostream&) const override;
};

class ImageStatus : public Status {
    string fileName;
public:
    ImageStatus() = default;
    ImageStatus(Date&, Time&, string&, STATUS_TYPE&, string&);
    ~ImageStatus() override = default;

    string& getFileName() {return fileName;}
    void setFileName(string& _fileName) {fileName = _fileName;}
    void showContent(ostream&) const override;
};

class StatusExceptions : public std::exception {
public:
    const char* what() const noexcept override { return "Status error."; }
};

class EmptyStatus :public StatusExceptions {
public:
    const char* what() const noexcept override { return "Cannot enter an empty status."; }
};

class EmptyFileName :public StatusExceptions {
public:
    const char* what() const noexcept override { return "Cannot enter an empty file name."; }
};

#endif