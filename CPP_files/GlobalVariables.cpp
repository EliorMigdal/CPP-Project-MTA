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
char* readName(const size_SI& type) //Reads a name & strings from user, using dynamic allocation.
{
	char* data = new char[MAX_CHARS_LEN];
	checkMem(data);
	switch (type)
	{
	case STATUS:
		cout << "Creating a Status: \nEnter status: " << endl;
		break;
	case FAN_PAGE:
		cout << "Creating a FanPage: \nEnter name: " << endl;
		break;
	case MEMBER:
		cout << "Creating a Member: \nEnter name: " << endl;
		break;
    case DEFAULT_TYPE:
        cout << "Connecting members:\nEnter a name:" << endl;
        break;
	default:
		break;
	}
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
//---------------------------------------------------------------------------------