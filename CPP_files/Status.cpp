#include "../Headers/Status.h"
//----------------------------------------------------------
inline void Status::printDate(Date date, Time time) const
{
    cout << date.day << "/" << date.month << "/" << date.year << endl;
    cout << time.hour << ":" << time.minutes << ":" << time.seconds << endl;
}
//----------------------------------------------------------