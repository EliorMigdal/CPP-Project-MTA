#include "../Headers/System.h"

//---------------------------------------------------------
int System::findEntity(string& name, int entityType)
{
    bool found = false;
    int foundIndex = -1;

    if (entityType == MEMBER)
    {
        for (int i = 0; i < numOfMembers && !found; i++)
        {
            if (members[i].getName() == name)
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
            if (pages[i].getName() == name)
            {
                foundIndex = i;
                found = true;
            }
        }
    }

    return foundIndex;
}
//----------------------------------------------------------
inline bool BirthdayCheck(Date& _birthday)
{
    return (_birthday.day > 0 && _birthday.day < 32 &&
        _birthday.month > 0 && _birthday.month < 13
        && _birthday.year>1900 && _birthday.year < 2023) ? true : false;
}
//----------------------------------------------------------
inline void System::printMenu()
{
    cout << "1 - Create a member"
        "\n2 - Create a fan page"
        "\n3 - Create a status"
        "\n4 - Show all statuses"
        "\n5 - View 10 last statuses of a member's friends"
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
    case 6:
        connectMembers();
        break;
    }   
}
//----------------------------------------------------------
void System::createMember() //read name and birthday from the user with validation checks instead of doing it in the class;
{
    string name; 
    cout << "Creating a member: \nEnter name: " << flush;
    getline(cin,name);
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
//----------------------------------------------------------
void System::createMember(string& _name, Date& _date) //Added a new constructor (mostly for testing)
{
    Member member(_name, _date);
    System::addMemberToArray(member);
}
//----------------------------------------------------------
void System::transferMembers() //Updated 22/11 20:00
{
    auto* output = new Member[numOfMembers + 1];
    for (int i = 0; i < numOfMembers; i++)
        output[i] = Member(members[i]);

    delete[] members;
    members = output;
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
    string name;
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
        std::getline(cin, name);
        int found = System::findEntity(name,MEMBER);
        (found >-1) ? members[found].addStatus() :
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
void System::printAllStatuses() //Prints an entity's statuses.
{
    int decision = 0, found;
    string name;
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
        getline(cin, name);
        found = System::findEntity(name, MEMBER);
    }

    else
    {
        cout << "Please enter a Fan Page's name:" << endl;
        getline(cin, name);
        found = System::findEntity(name, FAN_PAGE);
    }

    if (found == -1)
        cout << name << " was not found in our system!" << endl;

    else
    {
        if (decision == 1)
            members[found].printStatuses(members[found].getNumOfStatuses());

        else
        {
            cout << name << "'s statuses:" << endl;
            pages[found].printStatuses();
        }
    }
}
//----------------------------------------------------------
void System::printTenLastStatuses() //Prints a member's friends ten last statuses.
{
    string name; //Need to create a readName function.
    cout << "Please enter a member's name:" << endl;
    getline(cin, name);
    int found = System::findEntity(name, MEMBER);

    if (found != -1)
    {
        Member* friendsArr = members[found].getFriendsArr();
        int numOfFriends = members[found].getNumOfFriends();

        for (int i = 0; i < numOfFriends; i++)
            friendsArr[i].printStatuses(PRINT_STATUS);
    }

    else
        cout << name << " was not found in our system!\nRedirecting to main menu." << endl;
}
//----------------------------------------------------------
void System::connectMembers() //Connecting 2 members.
{
    string name1, name2;
    int found1, found2;

    cout << "Please enter 2 members whom you'd like to connect:" << endl;
    getline(cin, name1);
    getline(cin, name2);

    found1 = findEntity(name1, MEMBER);
    found2 = findEntity(name2, MEMBER);

    if (found1 != -1 && found2 != -1)
    {
        members[found1].addFriend(members[found2]);
        members[found2].addFriend(members[found1]);
    }

    else
        cout << "One of the members was not found in our system.\nRedirecting to main menu." << endl;
}
//----------------------------------------------------------
void System::printFanPageMembers() //Prints all of a fan page's members.
{
    string pageName; //readName
    int pageIndex = findEntity(pageName, FAN_PAGE);
    int pageMembers = -1;
    if (pageIndex != -1)
        pageMembers = pages[pageIndex].getNumOfMembers();
    Member* membersArr = pages[pageIndex].getMemberArr();

    for (int i = 0; i < pageMembers; i++)
        cout << membersArr[i].getName() << endl;

    //delete pageName;
}
//----------------------------------------------------------