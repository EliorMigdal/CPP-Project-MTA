#include "../Headers/GlobalVariables.h"

//Global functions
//--------------------------------------------------------------------------------------
void checkMem(void* ptr) //Verifies memory allocation.
{
	if (ptr == nullptr)
	{
        cout << "Memory allocation failed. Shutting down..." << endl;
		exit(1);
	}
}
//---------------------------------------------------------------------------------
char* readString(const size_SI& type) //Reads a name & strings from user, using dynamic allocation.
{
	char* data = new char[MAX_CHARS_LEN];
	checkMem(data);

    if (type != DEFAULT_FLUSH)
        cin.ignore();

    cin.getline(data, MAX_CHARS_LEN);
	char* updated = new char[strlen(data) + 1];
	checkMem(updated);
	strcpy(updated, data);
	delete[] data;
    return updated;
}
//---------------------------------------------------------------------------------
void readBirthday(Date& birthday) //Reads birthday from user.
{
	cout << "Day: " << flush;
	cin >> birthday.day;
	cout << "Month: " << flush;
	cin >> birthday.month;
	cout << "Year: " << flush;
	cin >> birthday.year;
	cin.ignore();
}
//---------------------------------------------------------------------------------
void setTimeAndDate(Time& exactTime, Date& exactDate) //Sets date & time for statuses.
{
	time_t curr_time;
	curr_time = time(NULL);
	tm* tm_local = localtime(&curr_time);
	exactTime.hour = tm_local->tm_hour;
	exactTime.minutes = tm_local->tm_min;
	exactTime.seconds = tm_local->tm_sec;
	exactDate.year = tm_local->tm_year + 1900;
	exactDate.month = tm_local->tm_mon + 1;
	exactDate.day = tm_local->tm_mday;
}
//---------------------------------------------------------------------------------