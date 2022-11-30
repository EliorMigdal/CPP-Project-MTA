#include "../Headers/System.h"

//Constructor & Destructor
//---------------------------------------------------------
System::System() //Constructor.
{
    members = new Member * [1];
    checkMem(members);
    pages = new FanPage * [1];
    checkMem(pages);
}
//---------------------------------------------------------
System::~System() //Destructor.
{
    for (size_SI i = 0; i < numOfMembers; i++)
        delete members[i];
    delete[] members;

    for (size_SI i = 0; i < numOfPages; i++)
        delete pages[i];
    delete[] pages;
}


//System-to-user methods
//----------------------------------------------------------
inline void System::printMenu() const //Prints the menu for the user.
{
    cout << "1 - Create a member\t\t7 - Disconnect 2 members"
        "\n2 - Create a fan page\t\t8 - Add a member to a fan page"
        "\n3 - Create a status\t\t9 - Remove a member from a fan page"
        "\n4 - Show all statuses\t\t10 - View all members and fan pages"
        "\n5 - 10 last statuses of member\t11 - View all member's friends or Fan page's fans"
        "\n6 - Connect 2 members\t\t12 - Exit" << endl;
          
}
//----------------------------------------------------------
void System::setDecision(size_SI& _decision) //Gets the decision from user and acts on it.
{
    if (_decision < 1 || _decision  > 12)
    {
        cout << "Invalid choice. Please try again!" << endl;
        System::printMenu();
        cin >> _decision;
    }
    switch (_decision )
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
char* System::InputOperation(const size_SI& type, int* foundedIndex = nullptr, const bool& readAfter = false)
{
    int tempfound = -1;
    char* input = nullptr;
    int counter = 0;
    switch (type)
    {
    case FAN_PAGE: // non temp index 
        cout << "Please enter a fan page's name:" << endl;
        (readAfter) ? input = readString(DEFAULT_FLUSH) : input = readString();
        *foundedIndex = System::findEntity(input, FAN_PAGE);
        while (*foundedIndex == NOEXIST && counter < MAX_ATTEMPTS)
        {
            cout << input << " Fan Page was not found in our system. You have " << MAX_ATTEMPTS - counter
                << " more attempts.\nPlease enter a Fan Page's name:" << endl;
            delete[] input;
            (readAfter) ? input = readString() : input = readString(DEFAULT_FLUSH);     
            counter++;
            *foundedIndex = System::findEntity(input, FAN_PAGE);
        }
        if (counter == MAX_ATTEMPTS && *foundedIndex == NOEXIST)
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
        while (tempfound != NOEXIST && counter < MAX_ATTEMPTS)
        {
            cout << input << " Already found in our system. You have " << MAX_ATTEMPTS - counter
                << " more attempts.\nPlease enter a fan page's name:" << endl;
         
            delete[]input;
            input = readString(DEFAULT_FLUSH);
            counter++;
            tempfound = System::findEntity(input, FAN_PAGE);
        }
        if (counter == MAX_ATTEMPTS && tempfound == NOEXIST)
        {
            cout << "Cannot find entity\nToo many entries Redirecting to main menu" << endl;
            return nullptr;
        }
        else if (tempfound != NOEXIST)
        {
            cout << "Fan Page: " << input << " founded!" << endl;
            cin.ignore();
        }
        else
        {
            cout << "Creating " << input << " Fan Page !" << endl;
        }
        break;
    case MEMBER:
        
        cout << "Please enter a member's name:" << endl;
        (readAfter)? input = readString(DEFAULT_FLUSH): input = readString();
        *foundedIndex = System::findEntity(input, MEMBER);
        while (*foundedIndex == NOEXIST && counter < MAX_ATTEMPTS)
        {
            cout << input << " was not found in our system. You have " << MAX_ATTEMPTS - counter
                << " more attempts.\nPlease enter a member's name:" << endl;
            delete[] input;
            (readAfter) ? input = readString() : input = readString(DEFAULT_FLUSH);
            counter++;
            *foundedIndex = System::findEntity(input, MEMBER);
        }
        if (counter == MAX_ATTEMPTS )
        {
            cout << "Cannot find entity\nToo many entries Redirecting to main menu" << endl;
            return nullptr;
        }
        else if(*foundedIndex != NOEXIST)
        {
            cout << "User: " << input << " founded!" << endl;
        }
        break;
    case MEMBER_CREATION:
       
        cout << "Please enter a member's name:" << endl;
        input = readString();
        tempfound = System::findEntity(input, MEMBER);
        while (tempfound != NOEXIST && counter < MAX_ATTEMPTS)
        {
            cout << input << " was found in our system. You have " << MAX_ATTEMPTS - counter
                << " more attempts.\nPlease enter a member's name:" << endl;
            delete[] input;
            input = readString(DEFAULT_FLUSH);
            counter++;
            tempfound = System::findEntity(input, MEMBER);
        }
        if (counter == MAX_ATTEMPTS)
        {
            cout << "Too many entries Redirecting to main menu" << endl;
            return nullptr;
        }
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


//Members Methods
//----------------------------------------------------------
void System::createMember() //read name and birthday from the user with validation checks instead of doing it in the class;
{
    char* name = nullptr;
    name = InputOperation(MEMBER_CREATION);
    if (name != nullptr)
    {
        cout << "Please enter a birthday:" << endl;
        Date Birthday = { 0,0,0 };
        readBirthday(Birthday);
        while (!BirthdayCheck(Birthday))
        {
            cout << "Bad birthday, enter again:" << endl;
            readBirthday(Birthday);
        }
        auto* m1 = new Member(name, Birthday);
        checkMem(m1);
      
        System::addMemberToArray(m1);
    }
      delete[] name;
  
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
void System::connectMembers(const char *name1, const char *name2) //Connect members for hard-coded data.
{
    int found1, found2;
    found1 = findEntity(name1, MEMBER);
    found2 = findEntity(name2, MEMBER);

    members[found1]->Member::addFriend(members[found2]);
    members[found2]->Member::addFriend(members[found1]);
}
//----------------------------------------------------------
void System::disconnectMembers(const char *name1, const char *name2) //Disconnect members for hard-coded data.
{
    int found1, found2;
    found1 = findEntity(name1, MEMBER);
    found2 = findEntity(name2, MEMBER);

    members[found1]->Member::removeFriend(members[found2]);
    members[found2]->Member::removeFriend(members[found1]);
}
//----------------------------------------------------------


//Fan Pages Methods
//----------------------------------------------------------
void System::createFanPage() //Creates a fan page.
{
    char* name = nullptr;
    name = InputOperation(FAN_PAGE_CREATION);
  
    if (name != nullptr)
    {
        auto* page = new FanPage(name);
        checkMem(page);
    
        System::addFanPageToArray(page);
    }
    delete[] name; 
}
//----------------------------------------------------------
void System::createFanPage(const char *_name) //Creates a fan page for hard-coded data.
{
    auto* page = new FanPage(_name);
    checkMem(page);
    System::addFanPageToArray(page);
}
//----------------------------------------------------------
void System::addFan() //Adds a fan to a fan page's members array.
{
    char* fanPageName = nullptr, *memberName = nullptr;
    int foundFanPage = -1, foundMember = -1;
    bool isFan = false;
    memberName = InputOperation(MEMBER, &foundMember);
    if (memberName == nullptr)
    {
        return;
    }
    fanPageName = InputOperation(FAN_PAGE, &foundFanPage,true);
    if (fanPageName == nullptr)
    {
        delete[] memberName;
        return;
    }
    if (foundFanPage != -1 && foundMember != -1)
    {
        isFan = pages[foundFanPage]->FanPage::checkIfFan(members[foundMember]);

        if (!isFan)
        {
            members[foundMember]->Member::addPage(pages[foundFanPage]);
            pages[foundFanPage]->FanPage::addMember(members[foundMember]);
            cout << "Successfully added " << memberName << " To " << fanPageName << "!" << endl;
        }
        else
            cout << memberName << " is already " << fanPageName << "'s fan" << endl;
    }
    delete[] fanPageName;
    delete[] memberName;
}
//----------------------------------------------------------
void System::addFan(const char *pageName, const char *fanName) //Add fan for hard-coded data.
{
    int foundPage, foundFan;

    foundPage = findEntity(pageName, FAN_PAGE);
    foundFan = findEntity(fanName, MEMBER);

    pages[foundPage]->FanPage::addMember(members[foundFan]);
    members[foundFan]->Member::addPage(pages[foundPage]);
}
//----------------------------------------------------------
void System::removeFan() //Removes a fan from a fan page's members array.
{
    char* fanPageName = nullptr, * memberName = nullptr;
    int foundFanPage = -1, foundMember = -1;
    bool deletedFan = false;
    memberName = InputOperation(MEMBER,&foundMember);
    if (memberName == nullptr)
    {
        return;
    }
    fanPageName = InputOperation(FAN_PAGE,&foundFanPage);
    if (fanPageName == nullptr)
    {
        delete[] memberName;
        return;
    }
    if (foundFanPage != -1 && foundMember != -1)
    {
        deletedFan = pages[foundFanPage]->FanPage::findIndexAndRemoveFAN(members[foundMember]);
        if(deletedFan)
            cout << "Succesfully deleted " << memberName << " From " << fanPageName << "!" << endl;
        else
            cout << memberName << " not a " << fanPageName << "'s fan" << endl;
    }
    delete[] fanPageName;
    delete[] memberName;
}
//----------------------------------------------------------
void System::removeFan(const char *pageName, const char *fanName) //Remove fan for hard-coded data.
{
    int foundPage, foundFan;

    foundPage = findEntity(pageName, FAN_PAGE);
    foundFan = findEntity(fanName, MEMBER);

    pages[foundPage]->FanPage::findIndexAndRemoveFAN(members[foundFan]);
    members[foundFan]->Member::removePage(pages[foundPage]);
}
//----------------------------------------------------------
void System::addFanPageToArray(FanPage* page) //Adds a new fanpage to the pages array.
{
    if (numOfPages > 0)
        System::transferFanPages();

    pages[numOfPages++] = page;
}
//----------------------------------------------------------


//Status Methods
//----------------------------------------------------------
void System::newStatus() //Creates a new status.
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
        cin.ignore();//??????????
        name = InputOperation(MEMBER,&found,true);
        if (found != -1 && name != nullptr)
        {
            members[found]->Member::addStatus();
        }
        
    }
    else
    {
        name = InputOperation(FAN_PAGE, &found,true);
        if (found != -1 && name !=nullptr)
        {
            pages[found]->FanPage::addStatus();
        }
    }
}
//----------------------------------------------------------
void System::newStatus(const char *name, const size_SI &type, const char *statusContent) //Creates a new status for hard-coded data.
{
    int found = findEntity(name, type);

    if (type == MEMBER)
        members[found]->Member::addStatus(statusContent);

    else
        pages[found]->FanPage::addStatus(statusContent);
}
//----------------------------------------------------------


//----------------------------------------------------------
void System::Start() //Hard-coded data for our system.
{
    Date eliDay = { 24, 4, 1995 };
    Date bencoDay = { 23, 5, 1990 };
    Date benhanDay = { 5, 9, 1983 };
    Date ramezDay = { 14, 12, 2005 };
    this->createMember("Elior Migdal", eliDay);
    this->newStatus("Elior Migdal", MEMBER, "Hi Facebook!");
    this->createMember("Ben Cohen", bencoDay);
    this->newStatus("Elior Migdal", MEMBER, "Hi Ben :) Wassup! @Ben Cohen");
    this->connectMembers("Elior Migdal", "Ben Cohen");
    this->newStatus("Ben Cohen", MEMBER, "Eli ya habibi");
    this->createMember("Ben Hanover", benhanDay);
    this->newStatus("Ben Hanover", MEMBER, "Yoooooyooooooo");
    this->connectMembers("Elior Migdal", "Ben Hanover");
    this->newStatus("Elior Migdal", MEMBER, "Yo Yo Ben!");
    this->createMember("Ramez Mannaa", ramezDay);
    this->newStatus("Ben Cohen", MEMBER, "I'm the king!");
    this->newStatus("Ben Hanover", MEMBER, "I know I'm the king bro");
    this->newStatus("Ramez Mannaa", MEMBER, "I'm here too!");
    this->newStatus("Ramez Mannaa", MEMBER, "Who wants to be my friend?");
    this->connectMembers("Ben Cohen", "Ramez Mannaa");
    this->connectMembers("Ben Cohen", "Ben Hanover");
    this->createFanPage("The Bens");
    this->createFanPage("We love Tel-Aviv");
    this->createFanPage("They were on a break!");
    this->connectMembers("Ramez Mannaa", "Elior Migdal");
    this->connectMembers("Ramez Mannaa", "Ben Hanover");
    this->newStatus("The Bens", FAN_PAGE, "We are the Bens!");
    this->addFan("The Bens", "Ben Cohen");
    this->newStatus("Ben Cohen", MEMBER, "I JOINED THE BENS!!!");
    this->addFan("The Bens", "Ben Hanover");
    this->newStatus("Ben Hanover", MEMBER, "ME TOO!");
    this->newStatus("The Bens", FAN_PAGE, "WE HAVE TWO NEW MEMBERS!!");
    this->removeFan("The Bens", "Ben Cohen");
    this->newStatus("Ben Cohen", MEMBER, "Now I left...");
    this->newStatus("The Bens", FAN_PAGE, ":(");
    this->addFan("The Bens", "Ramez Mannaa");
    this->addFan("They were on a break!", "Elior Migdal");
    this->addFan("They were on a break!", "Ben Cohen");
    this->addFan("They were on a break!", "Ben Hanover");
    this->newStatus("Elior Migdal", MEMBER, "They were on a break!!!");
    this->newStatus("They were on a break!", FAN_PAGE, "@Elior yes they were!");
    this->newStatus("They were on a break!", FAN_PAGE, "@Ben Cohen what do you think?");
    this->newStatus("Ben Cohen", MEMBER, "Yes yes");
    this->newStatus("They were on a break!", FAN_PAGE, "Good good");
    this->newStatus("Ben Hanover", MEMBER, "YES!!!!!!!!!");
    this->newStatus("We love Tel-Aviv", FAN_PAGE, "We LOVE Tel Aviv!!");
    this->addFan("We love Tel-Aviv", "Ramez Mannaa");
    this->addFan("We love Tel-Aviv", "Ben Cohen");
    this->addFan("We love Tel-Aviv", "Ben Hanover");
    this->newStatus("We love Tel-Aviv", FAN_PAGE, "Welcome Tel Aviv Lovers!!");
    this->newStatus("We love Tel-Aviv", FAN_PAGE, "Where is @Elior Migdal?");
    this->newStatus("Ramez Mannaa", MEMBER, "@WLTLV He Hates TLV!!");
    this->newStatus("We love Tel-Aviv", FAN_PAGE, "NO WAY!!!!%^%$^#%");
    this->disconnectMembers("Ben Cohen", "Elior Migdal");
    this->disconnectMembers("Ben Hanover", "Elior Migdal");
    this->disconnectMembers("Ramez Mannaa", "Elior Migdal");
    this->newStatus("Elior Migdal", MEMBER, "LOL you all left me!");

    size_SI userDecision;
    cout << "Welcome to our social network!" << endl;
    printMenu();
    cout << "Please choose your action: " << flush;
    cin >> userDecision;

    while (userDecision != EXIT)
    {
        setDecision(userDecision);
        printMenu();
        cout << "Please choose another action: " << flush;
        cin >> userDecision;
    }
}
//----------------------------------------------------------


//Private Global Methods
//----------------------------------------------------------
inline bool System::BirthdayCheck(const Date& _birthday) //Verifies birthday inserted correctly.
{
    return (_birthday.day > 0 && _birthday.day < 32 &&
        _birthday.month > 0 && _birthday.month < 13
        && _birthday.year>1900 && _birthday.year < 2023) ? true : false;
}
//----------------------------------------------------------


//Private Printer Methods
//----------------------------------------------------------
void System::printAllStatuses() //Prints an entity's statuses.
{
    size_SI decision = 0;
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
void System::printTenLastStatuses() //Prints a member's friends ten last statuses.
{
    char* name = nullptr;
    int found = -1;
    name = InputOperation(MEMBER, &found);
    if (name != nullptr)
    {
        if (members[found]->Member::getNumOfFriends() != 0)
        {
            if (found != -1)
            {
                Member** friendsArr = members[found]->Member::getFriendsArr();
                size_t numOfFriends = members[found]->Member::getNumOfFriends();
                for (size_t i = 0; i < numOfFriends; i++)
                {
                    cout << "------------------------------------\nFriend #" << i + 1 <<"\n------------------------------------" << endl;
                    friendsArr[i]->Member::printStatuses(PRINT_STATUS);
                }
            }

        }
        else
        {
            cout << "Member " << name << " Have no friends yet\nRedirecting to main menu" << endl;
            
        }
    }
    delete[] name;
}
//----------------------------------------------------------
void System::printAllEntities() const //Prints all entities.
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
void System::printAllFriends() //Prints an entity's friends.
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

    (decision == 1) ? entityName = InputOperation(MEMBER, &foundEntity): entityName = InputOperation(FAN_PAGE, &foundEntity);

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
void System::printAllPages() //Prints a list of a member's pages.
{
    char* memberName = nullptr;
    int found, attempts = 1; //First attempt is 2 rows below.
    cout << "Please enter a member who you'd like to view his pages list:" << endl;
    memberName = InputOperation(FAN_PAGE, &found);

    if (found == -1)
        cout << memberName << " was not found in our system.\nRedirecting to main menu." << endl;

    else
    {
        size_t membersNumOfPages = members[found]->Member::getNumOfPages();
        FanPage** membersArrOfPages = members[found]->Member::getPagesArr();

        if (membersNumOfPages == 0)
            cout << memberName << " isn't a fan of any page." << endl;

        else
            cout << memberName << " is a fan of the following pages:" << endl;

        for (size_t i = 0; i < membersNumOfPages; i++)
            cout << membersArrOfPages[i]->FanPage::getName() << endl;
    }

    delete[] memberName;
}
//----------------------------------------------------------


//Private System-Member Methods
//----------------------------------------------------------
void System::connectMembers() //Connects two members.
{
    char* firstMemberName = nullptr, * secondMemberName = nullptr;
    int foundFirst = -1, foundSecond = -1;
    bool areFriends;
    firstMemberName = InputOperation(MEMBER, &foundFirst);
    if (firstMemberName == nullptr)
    {
        return;
    }
    secondMemberName = InputOperation(MEMBER, &foundSecond, true);
    if (secondMemberName == nullptr)
    {
        delete[] firstMemberName;
        return;
    }
    if (foundFirst != -1 && foundSecond != -1)
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
    if (firstMemberName == nullptr)
    {
        return;
    }
    secondMemberName = InputOperation(MEMBER, &foundSecond, true);
    if (secondMemberName == nullptr)
    {
        delete[] firstMemberName;
        return;
    }
    if (foundFirst != -1 && foundSecond != -1)
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
    delete[] firstMemberName;
    delete[] secondMemberName;
}
//----------------------------------------------------------


//Private Re-Allocation Methods
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
//----------------------------------------------------------