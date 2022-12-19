#include "../Headers/System.h"
//System-to-user methods
//----------------------------------------------------------
inline void System::printMenu() const //Prints the menu for the user.
{
    cout << "------------------------------------\n1 - Create a member\t\t7 - Disconnect 2 members"
        "\n2 - Create a fan page\t\t8 - Add a member to a fan page"
        "\n3 - Create a status\t\t9 - Remove a member from a fan page"
        "\n4 - Show all statuses\t\t10 - View all members and fan pages"
        "\n5 - 10 last statuses of member\t11 - View all member's friends or Fan page's fans"
        "\n6 - Connect 2 members\t\t12 - Exit" << endl;
          
}
//----------------------------------------------------------
void System::setDecision(size_SI& _decision) //Gets the decision from user and acts on it.
{

    if (_decision < (size_SI)CREATEMEMBER || _decision  > (size_SI)EXIT)
    {
        cout << "Invalid choice. Please try again!" << endl;
        System::printMenu();
        cin >> _decision;
    }
    switch (_decision )
    {
        default:
            break;
        case (size_SI)CREATEMEMBER:
            System::createMember();
            break;
        case (size_SI)CREATEFANPAGE:
            System::createFanPage();
            break;
        case (size_SI)NEWSTATUS:
            System::newStatus();
            break;
        case (size_SI)PRINTALLSTATUSES:
            System::printAllStatuses();
            break;
        case (size_SI)PRINTTENLASTSTATUSES:
            System::printTenLastStatuses();
            break;
        case (size_SI)CONNECTMEMBERS:
            System::Connect_OR_DissconnectMember(&System::connectMembers);
            break;
        case (size_SI)DISCONNECTMEMBERS:
            System::Connect_OR_DissconnectMember(&System::disconnectMembers);
            break;
        case (size_SI)ADDFAN:
            System::Add_OR_RemoveFAN(&System::addFan);
            break;
        case (size_SI)REMOVEFAN:
            System::Add_OR_RemoveFAN(&System::removeFan);
            break;
        case (size_SI)PRINTALLENTITIES:
            System::printAllEntities();
            break;
        case (size_SI)PRINTALLFRIENDS:
            System::printAllFriends();
            break;
    }
}
//----------------------------------------------------------


//General Methods
//---------------------------------------------------------
string System::InputOperation(const size_SI& type, bool readAfter = false) //Returns the string according to each situation.
{
    int tempfound = -1, counter = 0;
    string input;
    bool founded = false;
    switch (type)
    {
    case FAN_PAGE: //Non-temp index
        cout << "Please enter a fan page's name:" << endl;
        if (readAfter) {
            cin.ignore();
            getline(cin, input);
        }
        else getline(cin, input);
        founded = pages.find(input) == pages.end();
        while (founded && counter < MAX_ATTEMPTS)
        {
            cout << input << " Fan Page was not found in our system. You have " << MAX_ATTEMPTS - counter
                << " more attempts.\nPlease enter a Fan Page's name:" << endl;
            getline(cin, input);
            counter++;
            founded = pages.find(input) == pages.end();
        }
        if (counter == MAX_ATTEMPTS && founded)
        {
            cout << "Cannot find fan page.\nToo many entries, redirecting to main menu" << endl;
            return "";
        }
        else
            cout << "Fan Page: " << input << " found!" << endl;

        break;
        //////////////////////////////////////////////////////////////////////////
    case FAN_PAGE_CREATION: //Temp index
        cout << "Please enter a fan page's name:" << endl;
        cin.ignore();
        getline(cin, input);
        founded = pages.find(input) != pages.end();
        while (founded && counter < MAX_ATTEMPTS)
        {
            cout << input << " Already found in our system. You have " << MAX_ATTEMPTS - counter
                << " more attempts.\nPlease enter a fan page's name:" << endl;
            getline(cin, input);
            counter++;
            founded = pages.find(input) != pages.end();
        }
        if (counter == MAX_ATTEMPTS && founded)
        {
            cout << "Fan Page: " << input << " already exists.\nToo many entries, redirecting to main menu." << endl;
            return "";
        }
        break;
        //////////////////////////////////////////////////////////////////////////
    case MEMBER:
        cout << "Please enter a member's name:" << endl;
        if (readAfter) {
            cin.ignore();
            getline(cin, input);
        }
        else getline(cin, input);
        founded = members.find(input) == members.end();
        while (founded && counter < MAX_ATTEMPTS)
        {
            cout << input << " was not found in our system. You have " << MAX_ATTEMPTS - counter
                << " more attempts.\nPlease enter a member's name:" << endl;
            getline(cin, input);
            counter++;
            founded = members.find(input) == members.end();
        }
        if (counter == MAX_ATTEMPTS && founded)
        {
            cout << "Cannot find member.\nToo many entries, redirecting to main menu." << endl;
            return "";
        }
        else 
            cout << "User: " << input << " found!" << endl;

        break;
        //////////////////////////////////////////////////////////////////////////
    case MEMBER_CREATION:

        cout << "Please enter a member's name:" << endl;
        cin.ignore();
        getline(cin, input);
        founded = members.find(input) != members.end();
        while (founded && counter < MAX_ATTEMPTS)
        {
            cout << input << " was found in our system. You have " << MAX_ATTEMPTS - counter
                << " more attempts.\nPlease enter a member's name:" << endl;
            getline(cin, input);
            counter++;
            founded = members.find(input) != members.end();
        }
        if (counter == MAX_ATTEMPTS && founded)
        {
            cout << "Member: " << input << " already exists.\nToo many entries, redirecting to main menu." << endl;
            return "";
        }
        break;
        //////////////////////////////////////////////////////////////////////////
    default:
        break;
    }
    return input;
}
//--------------------------------------------------------------------------------------
//bool System::ifExist_INVector(const string& Curr_name,const string& name_to_search, const size_SI& entityType)  //Searches for a member/fan page in their array.
//{
//    bool found = false;
//
//    if (entityType == MEMBER)
//    {
//        vector<Member> memVec = this->members[Curr_name];
//        for (const auto& val: memVec)
//        {
//            if (val.getName()== name_to_search)
//            {
//                found = true;
//            }
//        }
//    }
//
//    else if (entityType == FAN_PAGE)
//    {
//        vector<FanPage> memVec = this->pages[Curr_name];
//        for (const auto & val: memVec)
//        {
//            if (val.getName() == name_to_search)
//            {
//                found = true;
//            }
//        }
//    }
//
//    return found;
//}
//----------------------------------------------------------


//Members Methods
//----------------------------------------------------------
void System::createMember() //read name and birthday from the user with validation checks instead of doing it in the class;
{
    string name;
    name = InputOperation(MEMBER_CREATION);
    if (!name.empty())
    {
        cout << "Please enter a birthday:" << endl;
        Date Birthday = { "0","0","0" };
        readBirthday(Birthday);
        while (!BirthdayCheck(Birthday))//not good need to change
        {
            cout << "Bad birthday, enter again:" << endl;
            readBirthday(Birthday);
        }
        this->members[name] = Member{ name,Birthday };
 
        
        cout << "User " << name << " created successfully!" << endl;
    }
  
}

//----------------------------------------------------------
void System::createMember(const string& _name, Date& _date) //For hard-coded data.
{
    if (this->members.find(_name) == this->members.end())
    {
        this->members[_name] = Member{ _name,_date };
    }
}
////----------------------------------------------------------
void System::connectMembersHardCoded(const Member& member1, const Member& member2) //Connect members for hard-coded data.
{
    this->members.at(member1.getName()).Member::addFriend(member2);
    this->members.at(member2.getName()).Member::addFriend(member1);
}
////----------------------------------------------------------
void System::disconnectMembersHardCoded(const Member& member1, const Member& member2) //Disconnect members for hard-coded data.
{

    this->members[member1.getName()].Member::removeFriend(member2.getName());
    this->members[member2.getName()].Member::removeFriend(member1.getName());
}
////----------------------------------------------------------
//
//
////Fan Pages Methods
////----------------------------------------------------------
void System::createFanPage() //Creates a fan page.
{
    string name;
    name = InputOperation(FAN_PAGE_CREATION);
    if (!name.empty())
    {
        this->pages[name] = new FanPage(name);
        cout << "Fan Page: " << name << " was created successfully!" << endl;
    } 
}
////----------------------------------------------------------
void System::createFanPage(const string& _name) //Creates a fan page for hard-coded data.
{
    this->pages[_name] = new FanPage(_name);

}
////----------------------------------------------------------
void System::addFan(const string& fanPageName, const string& memberName) //Adds a fan to a fan page's members array.
{
    bool isFan = this->pages.at(fanPageName)->FanPage::checkIfFan(memberName);
    if (!isFan)
    {

        this->members.at(memberName).Member::addPage(this->pages.at(fanPageName),fanPageName);
        this->pages.at(fanPageName)->FanPage::addFan(this->members.at(memberName));
        cout << "Successfully added " << memberName << " To " << fanPageName << "!" << endl;
    }
    else
        cout << memberName << " is already " << fanPageName << "'s fan" << endl;              
}
////----------------------------------------------------------
void System::removeFan(const string& fanPageName,const string& memberName) //Removes a fan from a fan page's members array.
{ 
   bool deletedFan = this->pages.at(fanPageName)->FanPage::removeFan(this->members.at(memberName).getName());
    if (deletedFan)
        cout << "Succesfully deleted " << memberName << " From " << fanPageName << "!" << endl;
    else
        cout << memberName << " not a " << fanPageName << "'s fan" << endl;  
}
////----------------------------------------------------------
void System::addFanHardCoded(const string& pageName, const string& fanName) //Add fan for hard-coded data.
{
    this->members.at(fanName).Member::addPage(this->pages.at(pageName),pageName);
    this->pages.at(pageName)->FanPage::addFan(this->members.at(fanName));
}

////----------------------------------------------------------
void System::Add_OR_RemoveFAN(void(System::*operation)(const string&,const string&))
{
    string fanPageName, memberName;
    bool deletedFan = false;
    memberName = InputOperation(MEMBER, true);
    if (!memberName.empty())
    {
        fanPageName = InputOperation(FAN_PAGE);
        if (!fanPageName.empty())
        {
            (this->*operation)(fanPageName, memberName);
        }
    } 
}
////----------------------------------------------------------
void System::removeFanHardCoded(const string&  pageName, const string& fanName) //Remove fan for hard-coded data.
{
    this->pages.at(pageName)->FanPage::removeFan(this->members.at(fanName).getName());
}
////----------------------------------------------------------
////----------------------------------------------------------
//
//
////Status Methods
////----------------------------------------------------------
void System::newStatus() //Creates a new status.
{
    int decision = 0;
    string name;
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
        name = InputOperation(MEMBER, true);
        if (!name.empty())
        {
            this->members.at(name).Member::addStatus();
        }
        
    }
    else
    {
        name = InputOperation(FAN_PAGE, true);
        if (!name.empty())
        {
            this->pages.at(name)->FanPage::addStatus();
        }
    }
}
////----------------------------------------------------------
void System::newStatus(const string& name, const size_SI& type, const string& statusContent) //Creates a new status for hard-coded data.
{
    if (type == MEMBER)
        this->members.at(name).Member::addStatus(statusContent);

    else
        this->pages.at(name)->FanPage::addStatus(statusContent);
}
////----------------------------------------------------------
//
//
////----------------------------------------------------------
void System::Start() //Hard-coded data for our system.
{
    Date eliDay = { "24", "4", "1995" };
    Date bencoDay = { "23", "5", "1990" };
    Date benhanDay = { "5", "9", "1983" };
    Date ramezDay = { "14", "12", "2005" };
    this->members.reserve(4);
    this->pages.reserve(4);
    this->createMember("Elior Migdal", eliDay);
    this->newStatus("Elior Migdal", MEMBER, "Hi Facebook!");
    this->createMember("Ben Cohen", bencoDay);
    this->newStatus("Elior Migdal", MEMBER, "Hi Ben :) Wassup! @Ben Cohen");
    this->connectMembersHardCoded(this->members.at("Elior Migdal"), this->members.at("Ben Cohen"));
    this->newStatus("Ben Cohen", MEMBER, "Eli ya habibi");
    this->createMember("Ben Hanover", benhanDay);
    this->newStatus("Ben Hanover", MEMBER, "Yoooooyooooooo");
    this->connectMembersHardCoded(this->members.at("Elior Migdal"), this->members.at("Ben Hanover"));
    this->newStatus("Elior Migdal", MEMBER, "Yo Yo Ben!");
    this->createMember("Ramez Mannaa", ramezDay);
    this->newStatus("Ben Cohen", MEMBER, "I'm the king!");
    this->newStatus("Ben Hanover", MEMBER, "I know I'm the king bro");
    this->newStatus("Ramez Mannaa", MEMBER, "I'm here too!");
    this->newStatus("Ramez Mannaa", MEMBER, "Who wants to be my friend?");
    this->connectMembersHardCoded(this->members.at("Ben Cohen"), this->members.at("Ramez Mannaa"));
    this->connectMembersHardCoded(this->members.at("Ben Cohen"), this->members.at("Ben Hanover"));
    this->createFanPage("The Bens");
    this->createFanPage("We love Tel-Aviv");
    this->createFanPage("They were on a break!");
    this->connectMembersHardCoded(this->members.at("Ramez Mannaa"), this->members.at("Elior Migdal"));
    this->connectMembersHardCoded(this->members.at("Ramez Mannaa"), this->members.at("Ben Hanover"));
    this->newStatus("The Bens", FAN_PAGE, "We are the Bens!");
    this->addFanHardCoded("The Bens", "Ben Cohen");
    this->newStatus("Ben Cohen", MEMBER, "I JOINED THE BENS!!!");
    this->addFanHardCoded("The Bens", "Ben Hanover");
    this->newStatus("Ben Hanover", MEMBER, "ME TOO!");
    this->newStatus("The Bens", FAN_PAGE, "WE HAVE TWO NEW MEMBERS!!");
    this->removeFanHardCoded("The Bens", "Ben Cohen");
    this->newStatus("Ben Cohen", MEMBER, "Now I left...");
    this->newStatus("The Bens", FAN_PAGE, ":(");
    this->addFanHardCoded("The Bens", "Ramez Mannaa");
    this->addFanHardCoded("They were on a break!", "Elior Migdal");
    this->addFanHardCoded("They were on a break!", "Ben Cohen");
    this->addFanHardCoded("They were on a break!", "Ben Hanover");
    this->newStatus("Elior Migdal", MEMBER, "They were on a break!!!");
    this->newStatus("They were on a break!", FAN_PAGE, "@Elior yes they were!");
    this->newStatus("They were on a break!", FAN_PAGE, "@Ben Cohen what do you think?");
    this->newStatus("Ben Cohen", MEMBER, "Yes yes");
    this->newStatus("They were on a break!", FAN_PAGE, "Good good");
    this->newStatus("Ben Hanover", MEMBER, "YES!!!!!!!!!");
    this->newStatus("We love Tel-Aviv", FAN_PAGE, "We LOVE Tel Aviv!!");
    this->addFanHardCoded("We love Tel-Aviv", "Ramez Mannaa");
    this->addFanHardCoded("We love Tel-Aviv", "Ben Cohen");
    this->addFanHardCoded("We love Tel-Aviv", "Ben Hanover");
    this->newStatus("We love Tel-Aviv", FAN_PAGE, "Welcome Tel Aviv Lovers!!");
    this->newStatus("We love Tel-Aviv", FAN_PAGE, "Where is @Elior Migdal?");
    this->newStatus("Ramez Mannaa", MEMBER, "@WLTLV He Hates TLV!!");
    this->newStatus("We love Tel-Aviv", FAN_PAGE, "NO WAY!!!!%^%$^#%");
    this->disconnectMembersHardCoded(this->members.at("Ben Cohen"), this->members.at("Elior Migdal"));
    this->disconnectMembersHardCoded(this->members.at("Ben Hanover"), this->members.at("Elior Migdal"));
    this->disconnectMembersHardCoded(this->members.at("Ramez Mannaa"), this->members.at("Elior Migdal"));
    this->newStatus("Elior Migdal", MEMBER, "LOL you all left me!");
    this->newStatus("Elior Migdal", MEMBER, "yo GUYS");
    this->connectMembersHardCoded(this->members.at("Elior Migdal"), this->members.at("Ben Hanover"));
    this->connectMembersHardCoded(this->members.at("Elior Migdal"), this->members.at("Ben Cohen"));
    this->connectMembersHardCoded(this->members.at("Elior Migdal"), this->members.at("Ramez Mannaa"));
    this->newStatus("Elior Migdal", MEMBER, "yo GUYS");
    this->newStatus("Elior Migdal", MEMBER, "yeaaaaaaa");
    this->newStatus("Elior Migdal", MEMBER, "hello people");
    this->newStatus("Elior Migdal", MEMBER, "wassup");
    this->newStatus("Elior Migdal", MEMBER, "I LOVE C++");
    this->newStatus("Elior Migdal", MEMBER, "but python is better");
    this->newStatus("Elior Migdal", MEMBER, "just kidding");
    this->newStatus("Elior Migdal", MEMBER, "or not....");
    this->newStatus("Elior Migdal", MEMBER, ";)");

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
////----------------------------------------------------------
////Private Global Methods
////----------------------------------------------------------
inline bool System::BirthdayCheck(const Date& _birthday) //Verifies birthday inserted correctly.
{
    return (_birthday.day > "0" && _birthday.day < "32" &&
        _birthday.month > "0" && _birthday.month < "13"
        && _birthday.year>"1900" && _birthday.year < "2023") ? true : false;
}
////----------------------------------------------------------
//
//
////Private Printer Methods
////----------------------------------------------------------
void System::printAllStatuses() //Prints an entity's statuses.
{
    size_SI decision = 0;
    string name;
    cout << "Please choose the entity of which you want to view statuses:"
            "\n1 - A Member"
            "\n2 - A Fan Page" << endl;
    cin >> decision;
    cin.ignore();
    while (decision != 1 && decision != 2)
    {
        cout << "Invalid decision. Please choose 1 or 2: " << endl;
        cin >> decision;
        cin.ignore();
    }

    (decision == 1 ) ?
            name = InputOperation(MEMBER)
                     :
            name = InputOperation(FAN_PAGE);

    if (!name.empty())
    {
        if (decision == 1)
            this->members.at(name).Member::printStatuses(this->members.at(name).getStatusArr().size());
        else
        {
            cout << name << "'s statuses:" << endl;
            this->pages.at(name)->FanPage::printStatuses();
        }
    }
}
////----------------------------------------------------------
void System::printTenLastStatuses() //Prints a member's friends ten last statuses.
{
    string name;
    int i = 0;
    name = InputOperation(MEMBER,true);
    if (!name.empty())
    {

        if (!this->members[name].Member::getFriendsArr().empty())
        {

            for (const auto& kv : this->members) 
            {
                auto& key = kv.first;
                auto& value = kv.second;
                if (key != name) // need to change after creating all the classes operators
                {
                    cout << "####################################\nFriend #" << ++i  << "\n####################################" << endl;
                    value.Member::printStatuses(PRINT_STATUS);
                }
            }
        }

        else
            cout << "Member " << name << " has no friends yet.\nRedirecting to main menu." << endl;
    }

}
////----------------------------------------------------------
void System::printAllEntities() const //Prints all entities.
{
    if (this->members.empty())
        cout << "Our system has no members yet." << endl;
    else
    {
        cout << "------------------------------------\nOur system's members list:\n------------------------------------" << endl;
    
        for (const auto& kv:this->members)
        {
            const auto& key = kv.first;
            cout << "\t" << key << endl;
        }
    }        
    if (this->pages.empty())
        cout << "Our system has no fan pages yet." << endl;

    else
    {
        cout << "------------------------------------\nOur system's fan pages list:\n------------------------------------" << endl;

        for (const auto& kv : this->pages)
        {
            const auto& key = kv.first;
            cout << "\t" << key << endl;
        }
    }

}
////----------------------------------------------------------
void System::printAllFriends() //Prints an entity's friends.
{
    int decision;
    string entityName;
    cout << "Please enter the entity of which you want to view its friends:"
            "\n1 - A Member"
            "\n2 - A Fan Page" << endl;
    cin >> decision;

    while (decision != 1 && decision != 2)
    {
        cout << "Invalid decision. Please choose 1 or 2: " << endl;
        cin >> decision;
    }

    (decision == 1) ? entityName = InputOperation(MEMBER,true): entityName = InputOperation(FAN_PAGE, true);

    if (!entityName.empty())
    {
        if (decision == 1)
            members[entityName].Member::printFriendsArr();
        else
            System::printAllFans(pages[entityName]);
    }

}
////----------------------------------------------------------
void System::printAllFans(FanPage* fanpage) const //Prints a fan page's fans list.
{
    unordered_map<string, Member> MembersMap = fanpage->getMemberArr();
    if (MembersMap.empty())
        cout << fanpage->FanPage::getName() << " has no fans." << endl;

    else
    {
        cout << "------------------------------------\n" << fanpage->FanPage::getName() << "'s fans list:\n------------------------------------" << endl;
        for (const auto& kv : MembersMap)
        {
            const auto& key = kv.first;
            cout << "\t" << key << endl;
        }
    }
}

void System::printAllPages()
{
}
        

    
////----------------------------------------------------------
////Only implementation.
//void System::printAllPages() //Prints a list of a member's pages.
//{
//    string memberName;
//    int found, attempts = 1; //First attempt is 2 rows below.
//    cout << "Please enter a member who you'd like to view his pages list:" << endl;
//    memberName = InputOperation(FAN_PAGE, &found);
//
//    if (found == -1)
//        cout << memberName << " was not found in our system.\nRedirecting to main menu." << endl;
//
//    else
//    {
//        size_t membersNumOfPages = members[found]->Member::getNumOfPages();
//        FanPage** membersArrOfPages = members[found]->Member::getPagesArr();
//
//        if (membersNumOfPages == 0)
//            cout << memberName << " isn't a fan of any page." << endl;
//
//        else
//            cout << memberName << " is a fan of the following pages:" << endl;
//
//        for (size_t i = 0; i < membersNumOfPages; i++)
//            cout << membersArrOfPages[i]->FanPage::getName() << endl;
//    }
//
//}
////----------------------------------------------------------
//
//
////Private System-Member Methods

void System::Connect_OR_DissconnectMember(void(System::* operation)(const string&, const string&))
{
    string firstMemberName, secondMemberName;
    firstMemberName = InputOperation(MEMBER, true);
    if (!firstMemberName.empty())
    {
        secondMemberName = InputOperation(MEMBER);
        if (!secondMemberName.empty())
        {
            (this->*operation)(firstMemberName, secondMemberName);
        }
    }
}
////----------------------------------------------------------
void System::connectMembers(const string& firstMemberName, const string& secondMemberName) //Connects two members.
{
    if (firstMemberName != secondMemberName)
    {
        bool areFriends = members[firstMemberName].Member::checkIfFriend(members[secondMemberName].getName());
        if (!areFriends)
        {
            members[firstMemberName].Member::addFriend(members[secondMemberName]);
            members[secondMemberName].Member::addFriend(members[firstMemberName]);
            cout << "Users: " << firstMemberName << " and " << secondMemberName << " Connected Succesfully." << endl;
        }
        else
            cout << firstMemberName << " and " << secondMemberName << " are already friends." << endl;           
    }
    else
    {
        cout << "Cannot add yourself to your friend's list\nredirecting to main menu" << endl;
    }
    
}
////----------------------------------------------------------
void System::disconnectMembers(const string& firstMemberName, const string& secondMemberName) //Disconnects two members.
{
    bool areFriends = members[firstMemberName].Member::checkIfFriend(members[secondMemberName].getName());
    if (areFriends)
    {
        members[firstMemberName].Member::removeFriend(members[secondMemberName].getName());
        members[secondMemberName].Member::removeFriend(members[firstMemberName].getName());
        cout << "Users: " << firstMemberName << " and " << secondMemberName << " Disconnected Succesfully." << endl;
    }
    else
        cout << firstMemberName << " and " << secondMemberName << " are not friends." << endl;      
}
////----------------------------------------------------------