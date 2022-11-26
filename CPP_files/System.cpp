#include "../Headers/System.h"

//---------------------------------------------------------
int System::findEntity(const char* name, const size_SI& entityType) const
{
    bool found = false;
    int foundIndex = -1;

    if (entityType == MEMBER)
    {
        for (int i = 0; i < numOfMembers && !found; i++)
        {
            if (members[i]->getName() == name)
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
            if (pages[i]->getName() == name)
            {
                foundIndex = i;
                found = true;
            }
        }
    }

    return foundIndex;
}
//----------------------------------------------------------
inline bool System::BirthdayCheck(const Date& _birthday)
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
    char* name = nullptr;
    name = readName(MEMBER);
    Date Birthday = readBirthday();
    cout << "Enter birthday:" << endl;
    
    while (!BirthdayCheck(Birthday))
    {
        cout << "Bad birthday, enter again:" << endl;
        Birthday = readBirthday();
    } 
    Member m1(name,Birthday);
    System::addMemberToArray(&m1);
}
//----------------------------------------------------------
void System::createMember(const char* _name, Date& _date) //Added a new constructor (mostly for testing)
{
    Member member(_name, _date);
    System::addMemberToArray(&member);
}
//----------------------------------------------------------
void System::transferMembers() //Updated 22/11 20:00
{
    auto* output = new Member * [numOfMembers + 1];
    checkMem(output);
    for (int i = 0 ; i < numOfMembers;i++)
    {
        output[i] = members[i];
    }

    delete[] members;
    members = output;
}
//----------------------------------------------------------
void System::addMemberToArray(Member* member) //Adds a member to the members array. Updated 22/11 20:00.
{
    if (numOfMembers == 0)
        members = new Member * [numOfMembers];

    else
        System::transferMembers();

     members[numOfMembers++] = member;
}
////----------------------------------------------------------

void System::createFanPage()
{


}
////----------------------------------------------------------
void System::connectMembers() //Connecting 2 members.
{
    char* name1 = nullptr, *name2 = nullptr;
    int found1, found2;

    cout << "Please enter 2 members whom you'd like to connect:" << endl;
    name1 = readName(DEFAULT_TYPE);
    name2 = readName(DEFAULT_TYPE);

    found1 = findEntity(name1, MEMBER);
    found2 = findEntity(name2, MEMBER);

    if (found1 != -1 && found2 != -1)
    {
        members[found1]->addFriend(members[found2]);
        members[found2]->addFriend(members[found1]);
    }

    else
        (found1 == -1) ?
        cout << "Cannot find user called: " << name1 << endl 
        : 
        (found2 == -1) ? 
        cout << "Cannot find user called: " << name2 << endl 
        : cout << "Redirecting to main menu." << endl;
   
}
////----------------------------------------------------------
void System::newStatus() // not yet modified
{
    int decision = 0;
    char* name= nullptr;
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
        name = readName(MEMBER);
        int found = System::findEntity(name,MEMBER);
        /*(found >-1) ? members[found].addStatus() :*/
        // if not found, alert - otherwise, inherit Member::addStatus
    }
    else
    {
        name = readName(FAN_PAGE);
        int found = System::findEntity(name, FAN_PAGE);
        // if not found, alert - otherwise, inherit FanPage::addStatus
    }
}
//----------------------------------------------------------
void System::printAllStatuses() //Prints an entity's statuses.
{
    int decision = 0, found;
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
        name = readName(MEMBER);
        found = System::findEntity(name, MEMBER);
    }

    else
    {
        name = readName(FAN_PAGE);
        found = System::findEntity(name, FAN_PAGE);
    }

    if (found == -1)
        cout << name << " was not found in our system!" << endl;

    else
    {
        if (decision == 1)// not yet modified
        {
     /*       members[found].printStatuses(members[found].getNumOfStatuses());*/

        }

        else
        {
          /*  cout << name << "'s statuses:" << endl;
            pages[found].printStatuses();*/
        }
    }
}
//----------------------------------------------------------
void System::printTenLastStatuses() //Prints a member's friends ten last statuses.
{
    char* name = nullptr;
     name = readName(MEMBER);
    int found = System::findEntity(name, MEMBER);

    if (found != -1)
    {
        Member** friendsArr = members[found]->Member::getFriendsArr();
        int numOfFriends = members[found]->Member::getNumOfFriends();

        for (int i = 0; i < numOfFriends; i++)
            friendsArr[i]->Member::printStatuses(PRINT_STATUS);
    }

    else
        cout << name << " was not found in our system!\nRedirecting to main menu." << endl;
}
//----------------------------------------------------------
void System::printFanPageMembers() //Prints all of a fan page's members.
{
    char* pageName=  nullptr; 
    pageName = readName(FAN_PAGE);
    int pageIndex = findEntity(pageName, FAN_PAGE);
    size_t pageMembers = -1;
    if (pageIndex != -1)
        pageMembers = pages[pageIndex]->FanPage::getNumOfMembers();
    Member** membersArr = pages[pageIndex]->FanPage::getMemberArr();

    for (size_t i = 0; i < pageMembers; i++)
        cout << membersArr[i]->getName() << endl;

    delete pageName;
}
////----------------------------------------------------------