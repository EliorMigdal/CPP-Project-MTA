#include "../Headers/Status.h"
//----------------------------------------------------------
void Status::printDate(Date date, Time time)
{
    cout << date.day << "/" << date.month << "/" << date.year << endl;
    cout << time.hour << ":" << time.minutes << ":" << time.seconds << endl;
}
//----------------------------------------------------------