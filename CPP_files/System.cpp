#include "../Headers/System.h"

//---------------------------------------------------------
int System::findEntity(const char* name,const int entityType)

{
    bool found = false;
    int foundIndex = -1;

    if (entityType == MEMBER)
    {
        for (int i = 0; i < numOfMembers && !found; i++)
        {
            if (strcmp(members[i].getName(),name) == 0)
            {
                foundIndex = i;
                found = true;
            }
        }
    }

    else if (entityType == FAN_PAGE)
    {
        for (int i = 0; i < numOfPages && !found; i++)
        {

     
            if (strcmp(pages[i].getName(),name) == 0)

            {
                foundIndex = i;
                found = true;
            }
        }
    }

    return foundIndex;
}

//----------------------------------------------------------
inline bool BirthdayCheck(Date& _Birthday)
{
    return (_Birthday.day > 0 && _Birthday.day < 32 &&
        _Birthday.month > 0 && _Birthday.month < 13
        && _Birthday.year>1900 && _Birthday.year < 2023) ? true : false;
}
//----------------------------------------------------------
inline void System::printMenu()
{
    cout << "1 - Create a member"
        "\n2 - Create a fan page"
        "\n3 - Create a status"
        "\n4 - Show all statuses"
        "\n5 - View 10 last statuses of a member's friend"
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
        newStatus();
        break;
    case 4:
        printAllStatuses();
        break;
    case 5:
        printTenLastStatuses();
        break;
    }   
}
//----------------------------------------------------------
void System::createMember() //read name and birthday from the user with validation checks instead of doing it in the class;
{
    char* name=nullptr; 
    cout << "Creating a member: \nEnter name: " << flush;
    name = readName();
    Date Birthday;
    cout << "Enter birthday:\nDay: " << flush;
    cin >> Birthday.day;
    cout <<"Month: " << flush;
    cin >> Birthday.month; 
    cout << "Year: " << flush;
    cin >> Birthday.year;
    cin.ignore();
    while (!BirthdayCheck(Birthday))
    {
        cout << "Bad birthday, enter again:" << endl;
        Birthday = { 0,0,0 };
        cin >> Birthday.day >> Birthday.month >> Birthday.year;
        cin.ignore();
    } 
    Member m1(name,Birthday);
    System::addMemberToArray(m1);
}
//---------------------------------------------------------- TeST
void System::createMember(const char* _name, const Date& _date) //Added a new constructor (mostly for testing)
{
    Member member(_name, _date);
    System::addMemberToArray(member);
}
//----------------------------------------------------------
void System::transferMembers() //Updated 22/11 20:00
{
    Member* output = new Member[numOfMembers + 1];
    for (int i = 0; i < numOfMembers; i++)
        output[i] = Member(members[i]);

    delete members;
    members = output;
    output = nullptr;
}
//----------------------------------------------------------
void System::addMemberToArray(Member &member) //Adds a member to the members array. Updated 22/11 20:00.
{
    if (numOfMembers == 0)
        members = new Member[numOfMembers];

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
void System::newStatus() 
{
    int decision = 0;
    char* name = nullptr;
    cout << "Please choose where to add the status:"
        "\n1 - A Member"
        "\n2 - A Fan Page" << endl;
    cin >> decision;
    while (decision != 1 && decision != 2)
    {
        cout << "Invalid decision. Please choose 1 or 2: " << endl;
        cin >> decision;
        cin.ignore();
    }
    if (decision == 1)
    {
        cout << "Please enter a member's name:" << endl;
        name = readName();
        int found = System::findEntity(name,MEMBER);
       /* (found >-1) ? members[found].addStatus()*/
        // if not found, alert - otherwise, inherit Member::addStatus
    }
    else
    {
        cout << "Please enter a Fan Page's name:" << endl;
        name = readName();
        // bool found = findPage(name)
        // if not found, alert - otherwise, inherit FanPage::addStatus
    }
}
//----------------------------------------------------------
void System::printAllStatuses() //Prints an entity's statuses.
{
    int decision = 0, found = -1;
    char* name = nullptr;
    cout << "Please choose the entity of which you want to view statuses:"
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
        name = readName();
        found = System::findEntity(name, MEMBER);
    }

    else
    {
        cout << "Please enter a Fan Page's name:" << endl;
        name = readName();
        found = System::findEntity(name, FAN_PAGE);
    }

    if (found == -1)
        cout << name << " was not found in our system!" << endl;

    else
    {
        if (decision == 1)
        members[found].printStatuses(members[found].getNumOfStatuses());

        else
            pages[found].printStatuses();
    }
}
//----------------------------------------------------------
void System::printTenLastStatuses() //Prints a member's friend ten last statuses.
{
    char* name = nullptr,* friendName = nullptr; //Need to create a readName function.
    cout << "Please enter a member's name:" << endl;
    name = readName();
    int found = System::findEntity(name, MEMBER), foundFriend = -1, printIndex = -1;

    if (found != -1)

    {
        cout << "Please type one of " << name << "'s friends's name:" << endl;
        friendName = readName();
        foundFriend = members[found].findFriend(friendName);
        if (foundFriend == -1)
            cout << friendName << " was not found in " << name << "'s friends list.\nRedirecting to main menu" << endl;
        else
        {
            printIndex = System::findEntity(friendName, MEMBER);
            members[printIndex].printStatuses();
        }
    }

    else
        cout << name << " was not found in our system!" << endl;
}
//----------------------------------------------------------
void System::connectMembers()
{
    char* name1=nullptr,*name2 = nullptr;
    int found1{};
    int found2{};
    cout << "Please enter 1st member's name:" << endl;
    name1 = readName();
    //find
    cout << "Please enter 2nd member's name:" << endl;
    name2 = readName();
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