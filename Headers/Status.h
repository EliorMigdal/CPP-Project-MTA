#include "GlobalVariables.h"

class Status {
private:
    int var = 123;
    Date statusDate = {0,0,0};
    Time statusTime = {0,0,0};
    STATUS_TYPE statusType = STATUS_TYPE::TEXT;
    char* statusContent = nullptr;

public:
    Status(Date _date, Time _time, int _status, const char* _content)
    {
        statusDate = _date;
        statusTime = _time;
        statusType = (STATUS_TYPE)_status;
        strcpy(statusContent, _content);
    }
};