#include "../Headers/GlobalVariables.h"

//Global functions
//---------------------------------------------------------------------------------
void readBirthday(Date& birthday) //Reads birthday from user.
{
	cout << "\tDay: " << flush;
	cin >> birthday.day;
	cout << "\tMonth: " << flush;
	cin >> birthday.month;
	cout << "\tYear: " << flush;
	cin >> birthday.year;
	cin.ignore();
}
//---------------------------------------------------------------------------------
void setTimeAndDate(Time& exactTime, Date& exactDate) //Sets date & time for statuses.
{
	time_t curr_time;
	curr_time = time(nullptr);
	tm* tm_local = localtime(&curr_time);
	if (tm_local->tm_hour >= 0 && tm_local->tm_hour < 10)
	{
		exactTime.hour = "0" + std::to_string(tm_local->tm_hour);
	} 
	else exactTime.hour = std::to_string(tm_local->tm_hour);
	if (tm_local->tm_min >= 0 && tm_local->tm_min < 10)
	{
		exactTime.minutes = "0" + std::to_string(tm_local->tm_min);
	}
	else  exactTime.minutes = std::to_string(tm_local->tm_min);
	if (tm_local->tm_sec >= 0 && tm_local->tm_sec < 10)
	{
		exactTime.seconds = "0" + std::to_string(tm_local->tm_sec);
	}
	else exactTime.seconds = std::to_string(tm_local->tm_sec);
	exactDate.year = std::to_string(tm_local->tm_year + 1900);
	if (tm_local->tm_mon >= 0 && tm_local->tm_mon < 10)
	{
		exactDate.month = "0" + std::to_string(tm_local->tm_mon + 1);
	}
	else exactDate.month = std::to_string(tm_local->tm_mon + 1);
	if (tm_local->tm_mday >= 0 && tm_local->tm_mday < 10)
	{
		exactDate.day = "0" + std::to_string(tm_local->tm_mday);
	}
	else exactDate.day = std::to_string(tm_local->tm_mday);
}
//---------------------------------------------------------------------------------