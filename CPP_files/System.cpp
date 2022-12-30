#include "../Headers/System.h"

//Start Function
//----------------------------------------------------------
void System::Start() //Hard-coded data for our system.
{
    this->System::initialData();
    cout << "Welcome to our social network!" << endl;
    System::printMenu();
    cout << "Please choose your action: " << flush;
    cin >> userDecision;

    while (userDecision != EXIT)
    {
        try { System::setDecision(userDecision);}
        catch (EmptySystemExceptions& error) { cout << error.what() << endl; }
        catch (StatusExceptions& error) { cout << error.what() << endl; }
        catch (GlobalExceptions& error) { cout << error.what() << endl; }
        catch (systemExceptions& error) {cout << error.what() << endl;}
        catch (memberExceptions& error) {cout << error.what() << endl;}
        catch (fanPageExceptions& error) {cout << error.what() << endl;}
        catch (...) {cout << "General Error." << endl;}
        System::printMenu();
        cout << "Please choose another action: " << flush;
        cin >> userDecision;
    }
}
//----------------------------------------------------------
void System::initialData() //Inserts hard-coded data.
{
    Date eliDay = { 24, 04, 1995 };
    Date bencoDay = { 23, 12, 1997 };
    Date benhanDay = { 12, 01, 1998 };
    Date ramezDay = { 05, 07, 1999 };
    this->members.reserve(4);
    this->pages.reserve(4);
    this->createMember("Elior Migdal", eliDay);
    this->newStatus("Elior Migdal", MEMBER, "Hi Facebook!");
    this->createMember("Ben Cohen", bencoDay);
    this->newStatus("Elior Migdal", MEMBER, "Hi Ben :) Wassup! @Ben Cohen");
    this->connectMembersHardCoded(&this->members.at("Elior Migdal"), &this->members.at("Ben Cohen"));
    this->newStatus("Ben Cohen", MEMBER, "Eli ya habibi");
    this->createMember("Ben Hanover", benhanDay);
    this->newStatus("Ben Hanover", MEMBER, "Yoooooyooooooo");
    this->connectMembersHardCoded(&this->members.at("Elior Migdal"), &this->members.at("Ben Hanover"));
    this->newStatus("Elior Migdal", MEMBER, "Yo Yo Ben!");
    this->createMember("Ramez Mannaa", ramezDay);
    this->newStatus("Ben Cohen", MEMBER, "I'm the king!");
    this->newStatus("Ben Hanover", MEMBER, "I know I'm the king bro");
    this->newStatus("Ramez Mannaa", MEMBER, "I'm here too!");
    this->newStatus("Ramez Mannaa", MEMBER, "Who wants to be my friend?");
    this->connectMembersHardCoded(&this->members.at("Ben Cohen"), &this->members.at("Ramez Mannaa"));
    this->connectMembersHardCoded(&this->members.at("Ben Cohen"), &this->members.at("Ben Hanover"));
    this->createFanPage("The Bens");
    this->createFanPage("We love Tel-Aviv");
    this->createFanPage("They were on a break!");
    this->connectMembersHardCoded(&this->members.at("Ramez Mannaa"), &this->members.at("Elior Migdal"));
    this->connectMembersHardCoded(&this->members.at("Ramez Mannaa"), &this->members.at("Ben Hanover"));
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
    this->disconnectMembersHardCoded(&this->members.at("Ben Cohen"), &this->members.at("Elior Migdal"));
    this->disconnectMembersHardCoded(&this->members.at("Ben Hanover"), &this->members.at("Elior Migdal"));
    this->disconnectMembersHardCoded(&this->members.at("Ramez Mannaa"), &this->members.at("Elior Migdal"));
    this->newStatus("Elior Migdal", MEMBER, "LOL you all left me!");
    this->newStatus("Elior Migdal", MEMBER, "yo GUYS");
    this->connectMembersHardCoded(&this->members.at("Elior Migdal"), &this->members.at("Ben Hanover"));
    this->connectMembersHardCoded(&this->members.at("Elior Migdal"), &this->members.at("Ben Cohen"));
    this->connectMembersHardCoded(&this->members.at("Elior Migdal"), &this->members.at("Ramez Mannaa"));
    this->newStatus("Elior Migdal", MEMBER, "yo GUYS");
    this->newStatus("Elior Migdal", MEMBER, "yeaaaaaaa");
    this->newStatus("Elior Migdal", MEMBER, "hello people");
    this->newStatus("Elior Migdal", MEMBER, "wassup");
    this->newStatus("Elior Migdal", MEMBER, "I LOVE C++");
    this->newStatus("Elior Migdal", MEMBER, "but python is better");
    this->newStatus("Elior Migdal", MEMBER, "just kidding");
    this->newStatus("Elior Migdal", MEMBER, "or not....");
    this->newStatus("Elior Migdal", MEMBER, ";)");
}
//----------------------------------------------------------

//System-to-user methods
//----------------------------------------------------------
inline void System::printMenu() //Prints the menu for the user.
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
        throw invalidUserDecision();

    switch (_decision )
    {
        default:
            break;
        //////////////////////////////////////////////////////////////////////////////////////////
        case (size_SI)CREATEMEMBER:  //1
            try {System::createMember();}
            catch (userAlreadyExists& error) {throw userAlreadyExists(error);}
            catch (invalidBirthday& error) {throw invalidBirthday(error);}
            catch (EmptyName& error) { throw EmptyName(error); }
            catch(...) {throw systemExceptions();}
            break;
        //////////////////////////////////////////////////////////////////////////////////////////
        case (size_SI)CREATEFANPAGE: //2
            try {System::createFanPage();}
            catch (pageAlreadyExists& error) {throw pageAlreadyExists(error);}
            catch (EmptyName& error) { throw EmptyName(error); }
            catch(...) {throw systemExceptions();}
            break;
        //////////////////////////////////////////////////////////////////////////////////////////
        case (size_SI)NEWSTATUS: //3
            try {System::newStatus();}
            catch(invalidUserDecision& error) {throw invalidUserDecision(error);}
            catch (EmptyStatus& error) { throw EmptyStatus(error); }
            catch (StatusExceptions& error) { throw StatusExceptions(error); }
            catch(entityNotFound& error) {throw entityNotFound(error);}
            catch(...) {throw systemExceptions();}
            break;
        //////////////////////////////////////////////////////////////////////////////////////////
        case (size_SI)PRINTALLSTATUSES: //4
            try {System::printAllStatuses();}
            catch(invalidUserDecision& error) {throw invalidUserDecision(error);}
            catch(entityNotFound& error) {throw entityNotFound(error);}
            catch(memberPrintStatusesException& error) {throw memberPrintStatusesException(error);}
            catch(memberExceptions& error) {throw memberExceptions(error);}
            catch(fanPagePrintStatusesException& error) {throw fanPagePrintStatusesException(error);}
            catch(fanPageExceptions& error) {throw fanPageExceptions(error);}
            catch(...) {throw systemExceptions();}
            break;
        //////////////////////////////////////////////////////////////////////////////////////////
        case (size_SI)PRINTTENLASTSTATUSES: //5
            try{System::printTenLastStatuses();}
            catch(memberPrintStatusesException& error) {throw memberPrintStatusesException(error);}
            catch(printFriendsException& error) {throw printFriendsException(error);}
            catch(memberExceptions& error) {throw memberExceptions(error);}
            catch(memberNotFound& error) {throw memberNotFound(error);}
            catch(...) {throw systemExceptions();}
            break;
        //////////////////////////////////////////////////////////////////////////////////////////
        case (size_SI)CONNECTMEMBERS: //6
            try{System::Connect_OR_DisconnectMember(&System::connectMembers);}
            catch(addAFriendException& error) {throw addAFriendException(error);}
            catch(connectSameMember& error) {throw connectSameMember(error);}
            catch(memberExceptions& error) {throw memberExceptions(error);}
            catch(memberNotFound& error) {throw memberNotFound(error);}
            catch(...) {throw systemExceptions();}
            break;
        //////////////////////////////////////////////////////////////////////////////////////////
        case (size_SI)DISCONNECTMEMBERS: //7
            try{System::Connect_OR_DisconnectMember(&System::disconnectMembers);}
            catch(removeAFriendException& error) {throw removeAFriendException(error);}
            catch(removeSameMember& error) {throw removeSameMember(error);}
            catch(memberExceptions& error) {throw memberExceptions(error);}
            catch(memberNotFound& error) {throw memberNotFound(error);}
            catch(...) {throw systemExceptions();}
            break;
        //////////////////////////////////////////////////////////////////////////////////////////
        case (size_SI)ADDFAN: //8
            try{System::Add_OR_RemoveFAN(&System::addFan);}
            catch (addAFanException& error) { throw addAFanException(error); }
            catch(entityNotFound& error) {throw entityNotFound(error);}
            catch(...) {throw GlobalExceptions();}
            break;
        //////////////////////////////////////////////////////////////////////////////////////////
        case (size_SI)REMOVEFAN: //9
            try{System::Add_OR_RemoveFAN(&System::removeFan);}
            catch (removeAFanException& error) { throw removeAFanException(error); }
            catch(entityNotFound& error) {throw entityNotFound(error);}
            catch(...) {throw GlobalExceptions();}
            break;
        //////////////////////////////////////////////////////////////////////////////////////////
        case (size_SI)PRINTALLENTITIES: //10
            try{System::printAllEntities();}
            catch(noMembersInSystem& error) {throw noMembersInSystem(error);}
            catch(noPagesInSystem& error) {throw noPagesInSystem(error);}
            catch(...) {throw EmptySystemExceptions();}
            break;
        //////////////////////////////////////////////////////////////////////////////////////////
        case (size_SI)PRINTALLFRIENDS: //11
            try {System::printAllFriends();}
            catch(invalidUserDecision& error) {throw invalidUserDecision(error);}
            catch(printFriendsException& error) {throw printFriendsException(error);}
            catch(printFansException& error) {throw printFansException(error);}
            catch(memberExceptions& error) {throw memberExceptions(error);}
            catch(fanPageExceptions& error) {throw fanPageExceptions(error);}
            catch(entityNotFound& error) {throw entityNotFound(error);}
            catch(...) {throw systemExceptions();}
            break;
        //////////////////////////////////////////////////////////////////////////////////////////
    }
}
//----------------------------------------------------------
int System::memberOrFanPage() //Gets user decision for specific functions.
{
    int decision = 0;
    cout << "\n1 - A Member\n2 - A Fan Page" << endl;
    cin >> decision;
    cin.ignore();

    if (decision != MEMBER_CHOOSE && decision != FAN_PAGE_CHOOSE)
        throw invalidUserDecision();

    if (decision == MEMBER_CHOOSE)
        cout << "Please enter a member's name: ";

    else if (decision == FAN_PAGE_CHOOSE)
        cout << "Please enter a fan page's name: ";

    return decision;
}
//----------------------------------------------------------

//Member Methods
//----------------------------------------------------------
void System::createMember() //Read name and birthday from the user with validation checks.
{
    string name;
    cout << "Please enter a member's name: ";
    cin.ignore();
    getline(cin, name);
    if (!name.empty())
    {
        if (members.find(name) == members.end())
        {
            cout << "Please enter member's birthday:" << endl;
            Date Birthday = { 0, 0, 0 };
            readBirthday(Birthday);
            if (!BirthdayCheck(Birthday)) //not good need to change
                throw invalidBirthday();

            this->members[name] = Member{ name, Birthday };
        }
        else
            throw userAlreadyExists();
    }
    else
        throw EmptyName();

}
//----------------------------------------------------------
void System::createMember(const string& _name, Date& _date) //For hard-coded data.
{
    if (this->members.find(_name) == this->members.end())
        this->members[_name] = Member{ _name,_date };
}
//----------------------------------------------------------
void System::Connect_OR_DisconnectMember(void(System::* operation)(const string&, const string&)) //Connects or
// Disconnects Members.
{
    string firstMemberName, secondMemberName;
    cout << "Please enter two member names:\nFirst member: ";
    cin.ignore();
    getline(cin, firstMemberName);
    cout << "Second member: " << flush;
    getline(cin, secondMemberName);

    if (this->members.find(firstMemberName) != this->members.end() &&
        this->members.find(secondMemberName) != this->members.end())
    {
        try {(this->*operation)(firstMemberName, secondMemberName);}
        catch(addAFriendException& error) {throw addAFriendException(error);}
        catch(removeAFriendException& error) {throw removeAFriendException(error);}
        catch(connectSameMember& error) {throw connectSameMember(error);}
        catch(removeSameMember& error) {throw removeSameMember(error);}
        catch(...) {throw memberExceptions();}
    }

    else
        throw memberNotFound();
}
//----------------------------------------------------------
void System::connectMembers(const string& firstMemberName, const string& secondMemberName) //Connects two members.
{
    if (firstMemberName != secondMemberName)
    {
        try{this->members[firstMemberName] += &this->members[secondMemberName];}
        catch (addAFriendException& error) {throw addAFriendException(error);}
        catch (...) {throw memberExceptions();}
        try{this->members[secondMemberName] += &this->members[firstMemberName];}
        catch (addAFriendException& error) {throw addAFriendException(error);}
        catch (...) {throw memberExceptions();}
    }
    else
        throw connectSameMember();
}
//----------------------------------------------------------
void System::disconnectMembers(const string& firstMemberName, const string& secondMemberName) //Disconnects two members.
{
    if (firstMemberName != secondMemberName)
    {
        try{this->members[firstMemberName] -= &this->members[secondMemberName];}
        catch (removeAFriendException& error) {throw removeAFriendException(error);}
        catch(...) {throw memberExceptions();}
        try{this->members[secondMemberName] -= &this->members[firstMemberName];}
        catch (removeAFriendException& error) {throw removeAFriendException(error);}
        catch(...) {throw memberExceptions();}
    }
    else
        throw removeSameMember();
}
//----------------------------------------------------------
void System::connectMembersHardCoded(Member* member1, Member* member2) //Connect members for
// hard-coded data.
{
    *member1 += member2;
    *member2 += member1;
}
//----------------------------------------------------------
void System::disconnectMembersHardCoded(Member* member1, Member* member2) //Disconnect members for
// hard-coded data.
{
    *member1 -= member2;
    *member2 -= member1;
}
//----------------------------------------------------------

//FanPage Methods
//----------------------------------------------------------
void System::createFanPage() //Creates a fan page.
{
    string name;
    cout << "Please enter a fan page's name: ";
    cin.ignore();
    getline(cin, name);
    if (!name.empty())
    {
        if (this->pages.find(name) == this->pages.end())
            this->pages[name] = FanPage(name);

        else
            throw pageAlreadyExists();
    }
    else
        throw EmptyName();
}
//----------------------------------------------------------
void System::createFanPage(const string& _name) //Creates a fan page for hard-coded data.
{
    if (this->pages.find(_name) == this->pages.end())
        this->pages[_name] = FanPage(_name);
}
//----------------------------------------------------------
void System::Add_OR_RemoveFAN(void(System::*operation)(const string&,const string&)) //Adds or removes a fan.
{
    string fanPageName, memberName;
    cout << "Enter a member's and a fan page's name: " << endl;
    cin.ignore();
    cout << "Member name: ";
    getline(cin, memberName);
    cout << "Fan Page name: " << flush;
    getline(cin, fanPageName);

    if (members.find(memberName) != members.end() && pages.find(fanPageName) != pages.end())
    {
        try {(this->*operation)(fanPageName, memberName);}
        
        catch(addAFanException& error) {throw addAFanException(error);}
        catch(removeAFanException& error) {throw removeAFanException(error);}
        catch(GlobalExceptions& error) {throw GlobalExceptions(error);}

    }

    else
        throw entityNotFound();
}
//----------------------------------------------------------
void System::addFan(const string& fanPageName, const string& memberName) //Adds a fan to a fan page's members array.
{
    try 
    {
        this->members.at(memberName) += &this->pages.at(fanPageName);
        this->pages.at(fanPageName) += &this->members.at(memberName);
    }
     catch (addAFanException& error) { throw addAFanException(error); }
     catch(...) {throw GlobalExceptions();}
}
//----------------------------------------------------------
void System::removeFan(const string& fanPageName, const string& memberName) //Removes a fan from a fan page's
// members array.
{
    try 
    {
        this->pages.at(fanPageName) -= &this->members.at(memberName);
        this->members.at(memberName) -= &this->pages.at(fanPageName);
    }
    catch(removeAFanException& error) {throw removeAFanException(error);}
    catch (...) {throw GlobalExceptions();}
}
//----------------------------------------------------------
void System::addFanHardCoded(const string& pageName, const string& fanName) //Add fan for hard-coded data.
{
    this->members.at(fanName) += &this->pages.at(pageName);
    this->pages.at(pageName) += &this->members.at(fanName);
}
//----------------------------------------------------------
void System::removeFanHardCoded(const string& pageName, const string& fanName) //Remove fan for hard-coded data.
{
    this->pages.at(pageName) -= &this->members.at(fanName);
    this->members.at(fanName) -= &this->pages.at(pageName);
}
//----------------------------------------------------------

//Status Methods
//----------------------------------------------------------
void System::newStatus() //Creates a new status.
{
    string name;
    int decision;
    cout << "Please choose the entity which you would like to add a status to:";

    try {decision = System::memberOrFanPage();}
    catch(invalidUserDecision& error) {throw invalidUserDecision(error);}
    catch(...) {throw systemExceptions();}
    getline(cin, name);
   
    if (this->pages.find(name) != this->pages.end() || this->members.find(name) != this->members.end())
    {
        if (decision == MEMBER_CHOOSE)
        {
            try { this->members.at(name).Member::addStatus(); }
            catch (EmptyStatus& error) { throw EmptyStatus(error); }
            catch (...) { throw StatusExceptions(); }

        }


        else if (decision == FAN_PAGE_CHOOSE)
        {
            try { this->pages.at(name).FanPage::addStatus(); }
            catch (EmptyStatus& error) { throw EmptyStatus(error); }
            catch (...) { throw StatusExceptions(); }    
        }
    }
    else
        throw entityNotFound();
   
}
//----------------------------------------------------------
void System::newStatus(const string& name, const size_SI& type, const string& statusContent) //Creates a new status for
// hard-coded data.
{
    if (type == MEMBER)
        this->members.at(name).Member::addStatus(statusContent);

    else if (type == FAN_PAGE)
        this->pages.at(name).FanPage::addStatus(statusContent);
}
//----------------------------------------------------------

//Private Global Methods
//----------------------------------------------------------
inline bool System::BirthdayCheck(const Date& _birthday) //Verifies birthday inserted correctly.
{
    return (_birthday.day > 0 && _birthday.day < 32 &&
        _birthday.month > 0 && _birthday.month < 13
        && _birthday.year > 1900 && _birthday.year < 2023) ? true : false;
}
//----------------------------------------------------------

//Private Printer Methods
//----------------------------------------------------------
void System::printAllStatuses() const //Prints an entity's statuses.
{
    int decision;
    string name;
    cout << "Please choose the entity of which you want to view statuses:";

    try {decision = System::memberOrFanPage();}
    catch(invalidUserDecision& error) {throw invalidUserDecision(error);}
    catch(...) {throw systemExceptions();}
    getline(cin, name);

    if (this->pages.find(name) != this->pages.end() || this->members.find(name) != this->members.end())
    {
        if (decision == MEMBER_CHOOSE)
        {
            try { this->members.at(name).Member::printStatuses(this->members.at(name).
            Member::getNumOfStatuses()); }
            catch (memberPrintStatusesException& error) {throw memberPrintStatusesException(error);}
            catch (...) {throw memberExceptions();}
        }

        else if (decision == FAN_PAGE_CHOOSE)
        {
            try { this->pages.at(name).FanPage::printStatuses(); }
            catch (fanPagePrintStatusesException& error) {throw fanPagePrintStatusesException(error);}
            catch (...) {throw fanPageExceptions();}
        }
    }

    else
        throw entityNotFound();
}
//----------------------------------------------------------
void System::printTenLastStatuses() const //Prints a member's friends ten last statuses.
{
    string name;
    int i = 0;
    cout << "Please enter a member's name: ";
    cin.ignore();
    getline(cin, name);

    if (this->members.find(name) != this->members.end())
    {
        unordered_map<string, Member*> u_memberMap = this->members.at(name).Member::getFriendsArr();
        if (!u_memberMap.empty())
        {
            for (const auto& kv : u_memberMap)
            {
                auto& key = kv.first;
                auto& value = kv.second;
                if (key != name) // need to change after creating all the classes operators
                {
                    cout << "####################################\nFriend #" << ++i
                    << ": " << key << "\n####################################" << endl;
                    try {value->Member::printStatuses(PRINT_STATUS);}
                    catch (memberPrintStatusesException& error) {throw memberPrintStatusesException(error);}
                    catch (...) {throw memberExceptions();}
                }
            }
        }

        else
            throw printFriendsException();
    }

    else
        throw memberNotFound();

}
//----------------------------------------------------------
void System::printAllEntities() const //Prints all entities.
{
    if (this->members.empty() && this->pages.empty())
        throw EmptySystemExceptions();
    else
    {
        if (!this->members.empty())
        {
            cout << "------------------------------------\nOur system's "
                    "members list:\n------------------------------------" << endl;
    
            for (const auto& kv: this->members)
            {
                const auto& key = kv.first;
                cout << "\t" << key << endl;
            }
        }
        if (!this->pages.empty())
        {
            cout << "------------------------------------\nOur system's "
                "fan pages list:\n------------------------------------" << endl;

            for (const auto& kv : this->pages)
            {
                const auto& key = kv.first;
                cout << "\t" << key << endl;
            }
        }
        if (this->members.empty())
            throw noMembersInSystem();
        else if (this->pages.empty())
            throw noPagesInSystem();
    }
}
//----------------------------------------------------------
void System::printAllFriends() const //Prints an entity's friends.
{
    int decision;
    string entityName;
    cout << "Please enter the entity of which you want to view its friends:";

    try {decision = System::memberOrFanPage();}
    catch(invalidUserDecision& error) {throw invalidUserDecision(error);}
    catch(...) {throw systemExceptions();}
    getline(cin, entityName);

    if (this->pages.find(entityName) != this->pages.end() ||
    this->members.find(entityName) != this->members.end())
    {
        if (decision == MEMBER_CHOOSE)
        {
            try {this->members.at(entityName).Member::printFriendsArr();}
            catch(printFriendsException& error) {throw printFriendsException(error);}
            catch (...) {throw memberExceptions();}
        }

        else if (decision == FAN_PAGE_CHOOSE)
        {
            try {this->pages.at(entityName).FanPage::printFans();}
            catch(printFansException& error) {throw printFansException(error);}
            catch (...) {throw fanPageExceptions();}
        }
    }

    else
        throw entityNotFound();
}
//----------------------------------------------------------