#include "../Headers/GlobalVariables.h"


// Global functions: 
//--------------------------------------------------------------------------------------
void checkMem(void* ptr)
{
	if (ptr == nullptr)
	{
		exit(1);
	}
}
//---------------------------------------------------------------------------------
char* readName(const size_SI& type)
{
	char* data = new char[MAX_CHARS_LEN];
	checkMem(data);
	switch (type)
	{
	case STATUS:
		cout << "Creating a Status: \nEnter status: " << flush;
		break;
	case FAN_PAGE:
		cout << "Creating a FanPage: \nEnter name: " << flush;
		break;
	case MEMBER:
		cout << "Creating a Member: \nEnter name: " << flush;
		break;
	default:
		break;
	}
	cin.ignore();
	cin.getline(data, MAX_CHARS_LEN);
	char* updated = new char[strlen(data) + 1];
	checkMem(updated);
	strcpy(updated, data);
	delete[] data;
	return updated;
}
//---------------------------------------------------------------------------------
Date& readBirthday()
{
	Date birthday;
	cout << "Day: " << flush;
	cin >> birthday.day;
	cout << "Month: " << flush;
	cin >> birthday.month;
	cout << "Year: " << flush;
	cin >> birthday.year;
	cin.ignore();
	return birthday;
}