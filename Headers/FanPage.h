#ifndef CPP_PROJECT_FANPAGE_H
#define CPP_PROJECT_FANPAGE_H
#include "Entity.h"

class FanPage : public Entity {
public:
    //Constructors & Destructor
    FanPage() = default;
    FanPage(const FanPage&) = delete;
    FanPage(FanPage&&) noexcept = delete;
    explicit FanPage(string&);
    FanPage& operator=(const FanPage& fan_page) = default;
    FanPage& operator=(FanPage&& fan_page) = default;
    ~FanPage() override = default;

    virtual const FanPage& operator+=(Member&) noexcept(false);
    virtual const FanPage& operator-=(Member&) noexcept(false);

};
//    bool checkIfFan(const string&);
//    void addFan(Member*) noexcept(false);
//    void removeFan(Member*) noexcept(false);
//    void printFans()const noexcept(false);
//    void printStatuses() const noexcept(false);
//    void addStatus();
//    void addStatus(const string&);
//    friend ostream& operator<<(ostream&, FanPage*);
//    bool operator<(FanPage&) const;
//    bool operator<=(FanPage&) const;
//    bool operator>(FanPage&) const;
//    bool operator>=(FanPage&) const;

class fanPageExceptions : public std::exception {
public:
    const char* what() const noexcept override { return "Error handling fan page."; }
};

class fanPagePrintStatusesException : public fanPageExceptions {
public:
    const char* what() const noexcept override { return "Fan page has not posted any statuses yet."; }
};

class printFansException : public fanPageExceptions {
public:
    const char* what() const noexcept override { return "This fan page has no fans yet."; }
};

#endif