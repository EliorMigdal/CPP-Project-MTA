#include "../Headers/System.h"
//----------------------------------------------------------
int System::findMember(string& name)
    {
        bool found = false;
        int foundIndex = -1;
        for (int i = 0; i < numOfMembers && !found; i++)
        {
            if(members[i].getName().compare(name) == 0)
            {
                foundIndex = i;
                found = true;
            }
        }

        return foundIndex;
    }

//----------------------------------------------------------
inline bool BirthayCheck(Date& _Birthay)
{
    return (_Birthay.day > 0 && _Birthay.day < 32 &&
        _Birthay.month > 0 && _Birthay.month < 13
        && _Birthay.year>1900 && _Birthay.year < 2023) ? true : false;
}
//----------------------------------------------------------
inline void System::printMenu()
{
    cout << "1 - Create a member"
        "\n2 - Create a fan page"
        "\n3 - Create a status"
        "\n4 - Show all statuses"
        "\n5 - View 10 last statuses of a friend"
        "\n6 - Connect 2 members"
        "\n7 - Disconnect 2 members"
        "\n8 - Add a member to a fan page"
        "\n9 - Remove a member from a fan page"
        "\n10 - View all members and fan pages"
        "\n11 - View all member's friends or Fan page's fans"
        "\n12 - Exit" << endl;
}
//----------------------------------------------------------
void System::setDecision(int& _decision)
{
    if (_decision < 1 || _decision > 12)
    {
        cout << "Invalid choice. Please try again!" << endl;
        printMenu();
        cin >> _decision;
    }
    switch (_decision)
    {
    default:
        break;
    case 1:
        createMember();
        break;
    case 2:
        createFanPage();
        break;
    case 3:
        addStatus();
        break;
    case 4:
        //showAllStatuses();
        break;
    case 5:
        tenLastStatuses();
        break;
    }   
}
//----------------------------------------------------------
void System::createMember() //read name and birthay from the user with validation checks instead of doing it in the class;
{
    string name; 
    cout << "Creating a member: \nEnter name: " << flush;
    std::getline(cin,name); 
    Date Birthday;
    cout << "Enter birthday:\nDay: " << flush;
    cin >> Birthday.day;
    cout <<"Month: " << flush;
    cin >> Birthday.month; 
    cout << "Year: " << endl;
    cin >> Birthday.year;
    cin.ignore();
    while (!BirthayCheck(Birthday))
    {
        cout << "Bad birthday, enter again:" << endl;
        Birthday = { 0,0,0 };
        cin >> Birthday.day >> Birthday.month >> Birthday.year;
        cin.ignore();
    }
    Member m1(name,Birthday);
    System::addMemberToArray(m1);
}
//----------------------------------------------------------
void System::createMember(const string _name, const Date& _date) //Added a new constructor (mostly for testing)
{
    Member member(_name, _date);
    System::addMemberToArray(member);
}
//----------------------------------------------------------
void System::transferMembers() //updated
{
    Member* output = new Member[numOfMembers + 1];
    for (int i = 0; i < numOfMembers; i++)
    {
        Member temp(members[i]);
        output[i] = temp;

    }
    delete members;
    members = output;
    output = nullptr;
}
//----------------------------------------------------------
void System::addMemberToArray(Member &member) //Adds a member to the members array.
{
    if (numOfMembers == 0)
        members = new Member;

    else
        System::transferMembers();

     members[numOfMembers++] = member;
}
//----------------------------------------------------------
void System::createFanPage()
{
    //Inherit
}
//----------------------------------------------------------
void System::addStatus() 
{
    int decision = 0;
    string name = "";
    cout << "Please choose where to add the status:"
        "\n1 - A Member"
        "\n2 - A Fan Page" << endl;
    cin >> decision;
    while (decision != 1 && decision != 2)
    {
        cout << "Invalid decision. Please choose 1 or 2: " << endl;
        cin >> decision;
    }
    if (decision == 1)
    {
        cout << "Please enter a member's name:" << endl;
        std::getline(cin, name);
        // bool found = findMember(name)
        // if not found, alert - otherwise, inherit Member::addStatus
    }
    else
    {
        cout << "Please enter a Fan Page's name:" << endl;
        std::getline(cin, name);
        // bool found = findPage(name)
        // if not found, alert - otherwise, inherit FanPage::addStatus
    }
}
//----------------------------------------------------------
//void System::showAllStatuses()const
//{
//    int decision = 0;
//    string name = nullptr;
//    cout << "Please choose the entity of which you want to view the statuses:"
//        "\n1 - A Member"
//        "\n2 - A Fan Page" << endl;
//    cin >> decision;
//
//    while (decision != 1 && decision != 2)
//    {
//        cout << "Invalid decision. Please choose 1 or 2: " << endl;
//        cin >> decision;
//    }
//
//    if (decision == 1)
//    {
//        cout << "Please enter a member's name:" << endl;
//        cin >> name;
//        // bool found = findMember(name)
//        // if not found, alert - otherwise, inherit Member::showStatuses
//    }
//
//    else
//    {
//        cout << "Please enter a Fan Page's name:" << endl;
//        cin >> name;
//        // bool found = findPage(name)
//        // if not found, alert - otherwise, inherit FanPage::showStatuses
//    }
//}
//----------------------------------------------------------
void System::tenLastStatuses()
{
    string name; //Need to create a readName function.
    cout << "Please enter a member's name:" << endl;
    std::getline(cin, name);
    int found = System::findMember(name);
    if (found != -1)
        Member::printTenLastStatuses(members[found]);
    else
        cout << name << " was not found in our system!" << endl;
}
//----------------------------------------------------------
void System::connectMembers()
{
    string name1,name2 = "";
    int found1{};
    int found2{};
    cout << "Please enter 1st member's name:" << endl;
    std::getline(cin, name1);
    //find
    cout << "Please enter 2nd member's name:" << endl;
    std::getline(cin, name2);
    //find

    if (found1 != -1 && found2 != -1)
    {
        //use system data & member classes
    }
    else
    {
        //didn't find
    }
}