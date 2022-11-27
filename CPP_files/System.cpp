#include "../Headers/System.h"

//Constructor & Destructor
//---------------------------------------------------------
System::System() //Constructor
{
    members = new Member * [numOfMembers];
    checkMem(members);
    pages = new FanPage * [numOfPages];
    checkMem(pages);
}
//---------------------------------------------------------
System::~System() //Destructor.
{
    delete[] members;
    delete[] pages;
}


//System-to-user methods
//----------------------------------------------------------
inline void System::printMenu() const//Prints the menu for the user.
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
void System::setDecision(Byte& _decision) //Gets the decision from user and acts on it.
{
    if (_decision < 1 || _decision > 12)
    {
        cout << "Invalid choice. Please try again!" << endl;
        System::printMenu();
        cin >> _decision;
    }
    switch (_decision)
    {
        default:
            break;
        case 1:
            System::createMember();
            break;
        case 2:
            System::createFanPage();
            break;
        case 3:
            System::newStatus();
            break;
        case 4:
            System::printAllStatuses();
            break;
        case 5:
            System::printTenLastStatuses();
            break;
        case 6:
            System::connectMembers();
            break;
        case 7:
            System::disconnectMembers();
            break;
        case 8:
            System::addFan();
            break;
        case 9:
            System::removeFan();
            break;
        case 10:
            System::printAllEntities();
            break;
        case 11:
            System::printAllFriends();
            break;
    }
}
//----------------------------------------------------------


//General Methods
//---------------------------------------------------------
int System::findEntity(const char* name, const size_SI& entityType) const //Searches for a member/fan page in their array.
{
    bool found = false;
    int foundIndex = -1;

    if (entityType == MEMBER)
    {
        for (size_t i = 0; i < numOfMembers && !found; i++)
        {
            if (strcmp(members[i]->Member::getName(), name) == 0)
            {
                foundIndex = i;
                found = true;
            }
        }
    }

    else if (entityType == FAN_PAGE)
    {
        for (size_t i = 0; i < numOfPages && !found; i++)
        {
            if (strcmp(pages[i]->FanPage::getName(), name) == 0)
            {
                foundIndex = i;
                found = true;
            }
        }
    }

    return foundIndex;
}
//----------------------------------------------------------
void System::printAllStatuses() const//Prints an entity's statuses.
{
    Byte decision = 0;
    int found = -1;
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
        cout << "Please enter a fan page's name:" << endl;
        name = readName();
        found = System::findEntity(name, FAN_PAGE);
    }

    if (found == -1)
        cout << name << " was not found in our system!" << endl;

    else
    {
        if (decision == 1)
        {
            members[found]->Member::printStatuses(members[found]->Member::getNumOfStatuses());
        }

        else
        {
            cout << name << "'s statuses:" << endl;
            pages[found]->FanPage::printStatuses();
        }
    }

    delete[] name;
}
//----------------------------------------------------------
void System::printAllEntities() const//Prints all entities.
{
    if (numOfMembers == 0)
        cout << "Our system has no members yet." << endl;

    else
        cout << "Our system's members list:" << endl;

    for (size_t i = 0; i < numOfMembers; i++)
        cout << members[i]->Member::getName() << endl;

    if (numOfPages == 0)
        cout << "Our system has no fan pages yet." << endl;

    else
        cout << "Our system's fan pages list:" << endl;

    for (size_t i = 0; i < numOfPages; i++)
        cout << pages[i]->FanPage::getName() << endl;
}
//----------------------------------------------------------
void System::printAllFriends() const //Prints an entity's friends.
{
    int decision, foundEntity = -1;
    char* entityName = nullptr;
    cout << "Please enter the entity of which you want to view its friends:"
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
        entityName = readName();
        foundEntity = System::findEntity(entityName, MEMBER);
    }

    else
    {
        cout << "Please enter a fan page's name:" << endl;
        entityName = readName();
        foundEntity = System::findEntity(entityName, FAN_PAGE);
    }

    if (foundEntity == -1)
        cout << entityName << " was not found in our system.\nRedirecting to main menu." << endl;

    else if (decision == 1)
        members[foundEntity]->Member::printFriendsArr();

    else
        System::printAllFans(pages[foundEntity]);
}
//----------------------------------------------------------


//Members Methods
//----------------------------------------------------------
void System::createMember() //read name and birthday from the user with validation checks instead of doing it in the class;
{
    char* name = nullptr;
    name = readName();
    Date Birthday = readBirthday();

    while (!BirthdayCheck(Birthday))
    {
        cout << "Bad birthday, enter again:" << endl;
        Birthday = readBirthday();
    }
    auto* m1 = new Member(name, Birthday);
    checkMem(m1);
    delete[] name;
    System::addMemberToArray(m1);
}
//----------------------------------------------------------
void System::createMember(const char* _name, Date& _date) //For hard-coded data.
{
    auto* member = new Member(_name, _date);
    checkMem(member);
    System::addMemberToArray(member);
}
//----------------------------------------------------------
void System::addMemberToArray(Member* member) //Adds a member to the members array.
{
    if (numOfMembers > 0)
        System::transferMembers();

    members[numOfMembers++] = member;
}
//----------------------------------------------------------
void System::transferMembers() //Re-allocates memory to members array.
{
    auto* output = new Member * [numOfMembers + 1];
    checkMem(output);
    for (size_t i = 0 ; i < numOfMembers;i++)
    {
        output[i] = members[i];
    }

    delete[] members;
    members = output;
}
//----------------------------------------------------------
void System::printTenLastStatuses() const //Prints a member's friends ten last statuses.
{
    char* name = nullptr;
    cout << "Please enter a member's name:" << endl;
    name = readName();
    int found = System::findEntity(name, MEMBER);

    if (found != -1)
    {
        Member** friendsArr = members[found]->Member::getFriendsArr();
        size_t numOfFriends = members[found]->Member::getNumOfFriends();

        for (size_t i = 0; i < numOfFriends; i++)
            friendsArr[i]->Member::printStatuses(PRINT_STATUS);
    }

    else
        cout << name << " was not found in our system.\nRedirecting to main menu." << endl;

    delete[] name;
}
//----------------------------------------------------------
void System::connectMembers(const size_SI& type) //Connects XOR Disconnects two members.
{
    char* firstMemberName = nullptr, *secondMemberName = nullptr;
    int foundFirst = -1, foundSecond = -1;
    bool areFriends;

    cout << "Please enter 1st member name:" << endl;
    firstMemberName = readName();

    cout << "Please enter 2nd member name:" << endl;
    secondMemberName = readName(DEFAULT_FLUSH);

    foundFirst = System::findEntity(firstMemberName, MEMBER);
    foundSecond = System::findEntity(secondMemberName, MEMBER);

    if (foundFirst != -1 && foundSecond != -1)
    {
        areFriends = members[foundFirst]->Member::checkIfFriend(members[foundSecond]);

        if (!areFriends)
        {
            if (type == CONNECT)
            {
                members[foundFirst]->Member::addFriend(members[foundSecond]);
                members[foundSecond]->Member::addFriend(members[foundFirst]);
            }
            else
            {
                members[foundFirst]->Member::removeFriend(members[foundSecond]);
                members[foundSecond]->Member::removeFriend(members[foundFirst]);
            }
           
        }

        else
            cout << firstMemberName << " and " << secondMemberName << " are already friends." << endl;
    }

    else
    {
        if (foundFirst == -1)
            cout << firstMemberName << " was not found in our system.\nRedirecting to main menu." << endl;

        else
            cout << secondMemberName << " was not found in our system.\nRedirecting to main menu." << endl;
    }

    delete[] firstMemberName;
    delete[] secondMemberName;
}
//----------------------------------------------------------
void System::disconnectMembers() //Disconnects two members.
{
    System::connectMembers(DISCONNECT);
}
//----------------------------------------------------------


//Fan Pages Methods
//----------------------------------------------------------
void System::createFanPage() //Implementation needed.
{

}
//----------------------------------------------------------
void System::addFan() //Adds a fan to a fan page's members array.
{
    char* fanPageName = nullptr, *memberName = nullptr;
    int foundFanPage = -1, foundMember = -1;
    bool isFan = false;

    cout << "Please enter a fan page's name:" << endl;
    fanPageName = readName();
    cout << "Please enter a member's name:" << endl;
    memberName = readName(DEFAULT_FLUSH);

    foundFanPage = System::findEntity(fanPageName, FAN_PAGE);
    foundMember = System::findEntity(memberName, MEMBER);

    if (foundFanPage != -1 && foundMember != -1)
    {
        isFan = pages[foundFanPage]->FanPage::checkIfFan(members[foundMember]);

        if (!isFan)
        {
            members[foundMember]->Member::addPage(pages[foundFanPage]);
            pages[foundFanPage]->FanPage::addMember(members[foundMember]);
        }
    }

    else
    {
        if (isFan)
            cout << memberName << " is already " << fanPageName << "'s fan" << endl;

        else if (foundMember == -1)
            cout << memberName << " was not found in our system.\nRedirecting to main menu." << endl;

        else
            cout << fanPageName << " was not found in our system.\nRedirecting to main menu." << endl;
    }

    delete[] fanPageName;
    delete[] memberName;
}
//----------------------------------------------------------
void System::removeFan() //Removes a fan from a fan page's members array. Implementation needed.
{

}
//----------------------------------------------------------
void System::printAllFans(FanPage* fanpage) const //Prints a fan page's fans list.
{
    size_t numOfFans = fanpage->FanPage::getNumOfMembers();
    Member** fansArr = fanpage->FanPage::getMemberArr();

    if (numOfFans == 0)
        cout << fanpage->FanPage::getName() << " has no fans." << endl;

    else
        cout << fanpage->FanPage::getName() << "'s fans list:" << endl;

    for (size_t i = 0; i < numOfFans; i++)
        cout << fansArr[i]->Member::getName() << endl;
}
//----------------------------------------------------------


//Status Methods
//----------------------------------------------------------
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


//Private Methods
//----------------------------------------------------------
inline bool System::BirthdayCheck(const Date& _birthday) //Verifies birthday inserted correctly.
{
    return (_birthday.day > 0 && _birthday.day < 32 &&
        _birthday.month > 0 && _birthday.month < 13
        && _birthday.year>1900 && _birthday.year < 2023) ? true : false;
}
//----------------------------------------------------------