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
char* readName(const size_SI& type) //Reads a name & strings from user, using dynamic allocation.
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
Date& readBirthday() //Reads birthday from user.
{
	Date birthday={ 0,0,0 };
	cout << "Day: " << flush;
	cin >> birthday.day;
	cout << "Month: " << flush;
	cin >> birthday.month;
	cout << "Year: " << flush;
	cin >> birthday.year;
	cin.ignore();
	return birthday;
}
//---------------------------------------------------------------------------------