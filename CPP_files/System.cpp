#include "../Headers/System.h"

//Constructor & Destructor
//---------------------------------------------------------
System::System() //Constructor
{
    members = new Member * [1];
    checkMem(members);
    pages = new FanPage * [1];
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
    if (_decision-'0' < 1 || _decision - '0' > 12)
    {
        cout << "Invalid choice. Please try again!" << endl;
        System::printMenu();
        cin >> _decision;
    }
    switch ((_decision - '0'))
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
char* System::InputOperation(const size_SI& type, int* foundedIndex = nullptr)
{
    int tempfound = -1;
    bool rel = false;
    char* input = nullptr;
    int counter = 0;
    switch (type)
    {
    case FAN_PAGE: // non temp index
        cout << "Please enter a fan page's name:" << endl;
        input = readString(DEFAULT_FLUSH);
        *foundedIndex = System::findEntity(input, FAN_PAGE);
        while (*foundedIndex == NOEXIST && counter <=3)
        {
            cout << "Fan Page: " << input << " Don't exist in the system\nplease enter a Page name again" << endl;
            delete[] input;
            input = readString();
            counter++;
            *foundedIndex = System::findEntity(input, FAN_PAGE);
        }
        if (counter == 3 && *foundedIndex == NOEXIST)
        {
            cout << "Cannot find entity\nToo many entries Redirecting to main menu" << endl;
            return nullptr;
        }
        else if (*foundedIndex != NOEXIST)
        {
            cout << "Fan Page: " << input << " founded!" << endl;
        }
        break;

    case FAN_PAGE_CREATION: // temp index
        cout << "Please enter a fan page's name:" << endl;
        input = readString();
        tempfound = System::findEntity(input, FAN_PAGE);
        while (tempfound != NOEXIST && counter <= 3)
        {
            cout << "Fan Page: " << input << " already exist in the system\nplease enter a name again" << endl;
            delete[]input;
            input = readString();
            counter++;
            tempfound = System::findEntity(input, FAN_PAGE);
        }
        if (counter == 3 && tempfound == NOEXIST)
        {
            cout << "Cannot find entity\nToo many entries Redirecting to main menu" << endl;
            return nullptr;
        }
        else if (tempfound != NOEXIST)
        {
            cout << "Fan Page: " << input << " founded!" << endl;
        }
        else
        {
            cout << "Creating " << input << " Fan Page !" << endl;
        }
        break;
    case MEMBER:
       
        if (foundedIndex == nullptr)
        {
            rel = true;
            foundedIndex = new int;
            checkMem(foundedIndex);
            *foundedIndex = 0;
        }
        cout << "Please enter a member's name:" << endl;
        input = readString();
        *foundedIndex = System::findEntity(input, MEMBER);
        while (*foundedIndex == NOEXIST && counter <= 3)
        {
            cout << "User: " << input << " Don't exist in the system\nplease enter a User name again:" << endl;
            delete[] input;
            input = readString(DEFAULT_FLUSH);
            counter++;
            *foundedIndex = System::findEntity(input, MEMBER);
        }
        if (counter == 3 && *foundedIndex == NOEXIST)
        {
            cout << "Cannot find entity\nToo many entries Redirecting to main menu" << endl;
            return nullptr;
        }
        else if(*foundedIndex != NOEXIST)
        {
            cout << "User: " << input << " founded!" << endl;
        }
        if (rel) { delete foundedIndex; }
        break;
    case MEMBER_CREATION:
        if (foundedIndex == nullptr)
        {
            rel = true;
            foundedIndex = new int;
            checkMem(foundedIndex);
            *foundedIndex = 0;
        }
        cout << "Please enter a member's name:" << endl;
        input = readString();
        *foundedIndex = System::findEntity(input, MEMBER);
        while (*foundedIndex != NOEXIST && counter < 3)
        {
            cout << "User: " << input << " Already exist in the system\nplease enter new User name: " << endl;
            delete[] input;
            input = readString();
            counter++;
            *foundedIndex = System::findEntity(input, MEMBER);
        }
        if (counter == 3)
        {
            cout << "Too many entries Redirecting to main menu" << endl;
            return nullptr;
        }
        if (rel) { delete foundedIndex; }
        break;
    default:
        break;
    }
    return input;
}
//--------------------------------------------------------------------------------------
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
void System::printAllStatuses() //Prints an entity's statuses.
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
   
    (decision == 1 ) ? 
        name = InputOperation(MEMBER, &found) 
        : 
        name = InputOperation(FAN_PAGE, &found);
  
    if (found != -1 && name != nullptr)
    {
        if (decision == 1)
            members[found]->Member::printStatuses(members[found]->Member::getNumOfStatuses());
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
void System::printAllFriends()  //Prints an entity's friends.
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
        entityName =InputOperation(MEMBER,&foundEntity); 
    }

    else
    {
        entityName = InputOperation(FAN_PAGE, &foundEntity);
    }

    if (foundEntity != -1 && entityName != nullptr)
    {
         if (decision == 1)
            members[foundEntity]->Member::printFriendsArr();
         else
            System::printAllFans(pages[foundEntity]);
    }
    delete[] entityName;
  
}
//----------------------------------------------------------


//Members Methods
//----------------------------------------------------------
void System::createMember() //read name and birthday from the user with validation checks instead of doing it in the class;
{
    char* name = nullptr;
    name = InputOperation(MEMBER_CREATION);
    if (name != nullptr)
    {
        cout << "Please enter a birthday:" << endl;
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
    else
    {
        delete[] name;
        return;
    }
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
void System::printTenLastStatuses()  //Prints a member's friends ten last statuses.
{
    char* name = nullptr;
    int found = -1;
    name = InputOperation(MEMBER, &found);

    if (found != -1 && name!=nullptr)
    {
        Member** friendsArr = members[found]->Member::getFriendsArr();
        size_t numOfFriends = members[found]->Member::getNumOfFriends();
        for (size_t i = 0; i < numOfFriends; i++)
        {
            friendsArr[i]->Member::printStatuses(PRINT_STATUS);
        }
    }
    else
    {
        delete[] name;
        return;
    }

    delete[] name;
}
//----------------------------------------------------------
void System::connectMembers() //Connects two members.
{
    char* firstMemberName = nullptr, * secondMemberName = nullptr;
    int foundFirst = -1, foundSecond = -1;
    bool areFriends;
    firstMemberName = InputOperation(MEMBER, &foundFirst);
    secondMemberName = InputOperation(MEMBER, &foundSecond);

    if (foundFirst != -1 && foundSecond != -1 && firstMemberName != nullptr && secondMemberName != nullptr)
    {
        areFriends = members[foundFirst]->Member::checkIfFriend(members[foundSecond]);
        if (!areFriends)
        {
                members[foundFirst]->Member::addFriend(members[foundSecond]);
                members[foundSecond]->Member::addFriend(members[foundFirst]); 
                cout << "Users: " << firstMemberName << " and " << secondMemberName << " Connected Succesfully." << endl;
        }
        else
            cout << firstMemberName << " and " << secondMemberName << " are already friends." << endl;
    }
    else
    {
        delete[] firstMemberName;
        delete[] secondMemberName;
        return;
    }

    delete[] firstMemberName;
    delete[] secondMemberName;
}
//----------------------------------------------------------
void System::disconnectMembers() //Disconnects two members.
{ 
    char* firstMemberName = nullptr, * secondMemberName = nullptr;
    int foundFirst = -1, foundSecond = -1;
    bool areFriends;
    firstMemberName = InputOperation(MEMBER, &foundFirst);
    secondMemberName = InputOperation(MEMBER, &foundSecond);

    if (foundFirst != -1 && foundSecond != -1 && firstMemberName!=nullptr && secondMemberName != nullptr)
    {     
        areFriends = members[foundFirst]->Member::checkIfFriend(members[foundSecond]);
        if (areFriends)
        {
            members[foundFirst]->Member::removeFriend(members[foundSecond]);
            members[foundSecond]->Member::removeFriend(members[foundFirst]);
            cout << "Users: " << firstMemberName << " and " << secondMemberName << " Disconnected Succesfully." << endl;
        }
        else
            cout << firstMemberName << " and " << secondMemberName << " are not friends." << endl;     
    }
    else
    {
        delete[] firstMemberName;
        delete[] secondMemberName;
        return;
    }
    delete[] firstMemberName;
    delete[] secondMemberName;
}
//------------------------------------------------------------------------------------------


//Fan Pages Methods
//----------------------------------------------------------------------------------------
void System::createFanPage() //Implementation needed.
{
    char* name = nullptr;
    name = InputOperation(FAN_PAGE_CREATION);
  
    if (name != nullptr)
    {
        auto* page = new FanPage(name);
        checkMem(page);
        delete[] name;
        System::addFanPageToArray(page);
    }
    else
    {
        delete[] name;
        return;
    }
}
//-----------------------------------------------------------------------------------------
void System::addFan() //Adds a fan to a fan page's members array.
{
    char* fanPageName = nullptr, *memberName = nullptr;
    int foundFanPage = -1, foundMember = -1;
    bool isFan = false;
    memberName = InputOperation(MEMBER, &foundMember);
    fanPageName = InputOperation(FAN_PAGE, &foundFanPage);
    if (foundFanPage != -1 && foundMember != -1 && memberName != nullptr && fanPageName != nullptr)
    {
        isFan = pages[foundFanPage]->FanPage::checkIfFan(members[foundMember]);

        if (!isFan)
        {
            members[foundMember]->Member::addPage(pages[foundFanPage]);
            pages[foundFanPage]->FanPage::addMember(members[foundMember]);
            cout << "Succesfully added " << memberName << " To " << fanPageName << "!" << endl;
        }
        else
            cout << memberName << " is already " << fanPageName << "'s fan" << endl;
    }
    else
    {   
        delete[] fanPageName;
        delete[] memberName;
        return;
    }
    delete[] fanPageName;
    delete[] memberName;
}
//------------------------------------------------------------------------------------------
void System::removeFan() //Removes a fan from a fan page's members array. Implementation needed.
{
    char* fanPageName = nullptr, * memberName = nullptr;
    int foundFanPage = -1, foundMember = -1;
    bool deletedFan = false;
    memberName = InputOperation(MEMBER,&foundMember);
    fanPageName = InputOperation(FAN_PAGE,&foundFanPage);
    if (foundFanPage != -1 && foundMember != -1 && memberName !=nullptr && fanPageName != nullptr)
    {
        deletedFan = pages[foundFanPage]->FanPage::findIndexAndRemoveFAN(members[foundMember]);
        if(deletedFan)
            cout << "Succesfully added " << memberName << " To " << fanPageName << "!" << endl;
        else
            cout << memberName << " not a " << fanPageName << "'s fan" << endl;
    }
    else
    {
        delete[] fanPageName;
        delete[] memberName;
        return;
    }
    delete[] fanPageName;
    delete[] memberName;
}
//----------------------------------------------------------------------------------
void System::addFanPageToArray(FanPage* page)
{
    if (numOfPages > 0)
        System::transferFanPages();

    pages[numOfPages++] = page;
}


//----------------------------------------------------------
//Status Methods
//----------------------------------------------------------
void System::newStatus() // not yet modified
{
    int decision = 0;
    char* name= nullptr;
    int found = -1;
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
        name = InputOperation(MEMBER,&found);
        if (found != -1 && name != nullptr)
        {
            members[found]->Member::addStatus();
        }
        else
        {
            return;
        }
        
    }
    else
    {
        
        name = InputOperation(FAN_PAGE, &found);
        if (found != -1 && name !=nullptr)
        {
            pages[found]->FanPage::addStatus();
        }
        else
        {
            return;
        }
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
void System::transferFanPages()
{
    auto* output = new FanPage * [numOfPages + 1];
    checkMem(output);
    for (size_t i = 0; i < numOfPages; i++)
    {
        output[i] = pages[i];
    }

    delete[] pages;
    pages = output;

}