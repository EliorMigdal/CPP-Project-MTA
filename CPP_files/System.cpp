#include "../Headers/System.h"
#include "../Headers/FanPage.h"
#include "../Headers/Member.h"

//Start Function
//----------------------------------------------------------
void System::Start() //Boots up the system.
{
    /*this->System::initialData();*/
    cout << "Welcome to our social network!" << endl;
    System::printMenu();
    cout << "Please choose your action: " << flush;
    cin >> userDecision;

    while (userDecision != EXIT)
    {
        try {System::setDecision(userDecision);}
        catch (EmptySystemExceptions& error) {cout << error.what() << endl;}
        catch (StatusExceptions& error) {cout << error.what() << endl;}
        catch (GlobalExceptions& error) {cout << error.what() << endl;}
        catch (systemExceptions& error) {cout << error.what() << endl;}
        catch (memberExceptions& error) {cout << error.what() << endl;}
        catch (fanPageExceptions& error) {cout << error.what() << endl;}
        catch (...) {cout << "General Error." << endl;}
        System::printMenu();
        cout << "Please choose another action: " << flush;
        cin >> userDecision;
    }

    System::writeData();
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
            try {
                System::createMember();
            }
            catch (userAlreadyExists& error) {throw userAlreadyExists(error);}
            catch (invalidBirthday& error) {throw invalidBirthday(error);}
            catch (EmptyName& error) { throw EmptyName(error); }
            catch(...) {throw systemExceptions();}
            break;
        //////////////////////////////////////////////////////////////////////////////////////////
        case (size_SI)CREATEFANPAGE: //2
            try {
                System::createFanPage();
            }
            catch (pageAlreadyExists& error) {throw pageAlreadyExists(error);}
            catch (EmptyName& error) { throw EmptyName(error); }
            catch(...) {throw systemExceptions();}
            break;
        //////////////////////////////////////////////////////////////////////////////////////////
        case (size_SI)NEWSTATUS: //3
            try {System::newStatus();}
            catch(invalidUserDecision& error) {throw invalidUserDecision(error);}
            catch (EmptyStatus& error) { throw EmptyStatus(error); }
            catch (invalidStatusType& error) {throw error;}
            catch (StatusExceptions& error) { throw StatusExceptions(error); }
            catch(entityNotFound& error) {throw entityNotFound(error);}
            catch(...) {throw systemExceptions();}
            break;
        ////////////////////////////////////////////////////////////////////////////////////////////
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
        ////////////////////////////////////////////////////////////////////////////////////////////
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
        ////////////////////////////////////////////////////////////////////////////////////////
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
void System::createMember() //Creates a new member.
{
    cout << "Please enter a member's name: ";
    string name;
    cin.ignore();
    getline(cin, name);
    if (!name.empty())
    {
        if (Entities.find(std::type_index(typeid(Member*))) == Entities.end()) // until we will load from files this.
        {
            Entities[std::type_index(typeid(Member*))] = {};
        }
        unordered_map<string, Entity*>& placeHolder = Entities[std::type_index(typeid(Member*))];
        if (placeHolder.find(name) == placeHolder.end())
        {
            cout << "Please enter member's birthday:" << endl;
            Date Birthday = { 0, 0, 0 };
            readBirthday(Birthday);
            if (!BirthdayCheck(Birthday)) //not good need to change
                throw invalidBirthday();

            placeHolder[name] = new Member{ name,Birthday };
        }
        else
            throw userAlreadyExists();    
    }
    else
        throw EmptyName();
}
//----------------------------------------------------------
void System::Connect_OR_DisconnectMember(void(System::* operation)(Member*, Member*)) //Connects or
// Disconnects Members.
{
    string firstMemberName, secondMemberName;
    cout << "Please enter two member names:\nFirst member: ";
    cin.ignore();
    getline(cin, firstMemberName);
    cout << "Second member: " << flush;
    getline(cin, secondMemberName);

    if (!firstMemberName.empty() && !secondMemberName.empty())
    {
        const unordered_map<string, Entity*> placeHolder = Entities[std::type_index(typeid(Member*))];
        if (placeHolder.find(firstMemberName) != placeHolder.end() &&
            placeHolder.find(secondMemberName) != placeHolder.end())
        {
            try {
                (this->*operation)(dynamic_cast<Member*>(placeHolder.at(firstMemberName)),
                    dynamic_cast<Member*>(placeHolder.at(secondMemberName)));
            }
            catch (addAFriendException& error) { throw addAFriendException(error); }
            catch (removeAFriendException& error) { throw removeAFriendException(error); }
            catch (connectSameMember& error) { throw connectSameMember(error); }
            catch (removeSameMember& error) { throw removeSameMember(error); }
            catch (...) { throw memberExceptions(); }
        }

        else
            throw memberNotFound();
    }
    else
        throw EmptyName();
}
//----------------------------------------------------------
void System::connectMembers(Member* firstMemberName, Member* secondMemberName) //Connects two members.
{
    if (firstMemberName->Member::getName() != secondMemberName->Member::getName())
    {
        try
        {
            *firstMemberName += *secondMemberName;
            *secondMemberName += *firstMemberName;
        }
        catch (addAFriendException& error) {throw addAFriendException(error);}
        catch (...) {throw memberExceptions();}
    }
    else
        throw connectSameMember();
}
//----------------------------------------------------------
void System::disconnectMembers(Member* firstMemberName, Member* secondMemberName) //Disconnects two members.
{
    if (firstMemberName->Member::getName() != secondMemberName->Member::getName())
    {
        try
        {
            *firstMemberName -= *secondMemberName;
            *secondMemberName -= *firstMemberName;
        }
        catch (removeAFriendException& error) {throw removeAFriendException(error);}
        catch(...) {throw memberExceptions();}
    }
    else
        throw removeSameMember();
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
        if (Entities.find(std::type_index(typeid(FanPage*))) == Entities.end()) // until we will load from files this.
        {
            Entities[std::type_index(typeid(FanPage*))] = {};
        }
        unordered_map<string, Entity*>& placeHolder = Entities[std::type_index(typeid(FanPage*))];
        if (placeHolder.find(name) == placeHolder.end())
        {
            placeHolder[name] = new FanPage(name);
        }
        else
        {
            throw pageAlreadyExists();
        }
    }
    else
        throw EmptyName();
}
//----------------------------------------------------------
void System::Add_OR_RemoveFAN(void(System::*operation)(Member*,FanPage*)) //Adds or removes a fan.
{
    string fanPageName, memberName;
    cout << "Enter a member's and a fan page's name: " << endl;
    cin.ignore();
    cout << "Member name: ";
    getline(cin, memberName);
    cout << "Fan Page name: " << flush;
    getline(cin, fanPageName);
    const unordered_map<string, Entity*>& placeHolderFanPage = Entities[std::type_index(typeid(FanPage*))];
    const unordered_map<string, Entity*>& placeHolderMember = Entities[std::type_index(typeid(Member*))];
    if (!memberName.empty() && !fanPageName.empty())
    {
        if (placeHolderMember.find(memberName) != placeHolderMember.end() && 
            placeHolderFanPage.find(fanPageName) != placeHolderFanPage.end())
        {
            try { (this->*operation)(dynamic_cast<Member*>(placeHolderMember.at(memberName)),
                    dynamic_cast<FanPage*>(placeHolderFanPage.at(fanPageName))); }
            catch (addAFanException& error) { throw addAFanException(error); }
            catch (removeAFanException& error) { throw removeAFanException(error); }
            catch (GlobalExceptions& error) { throw GlobalExceptions(error); }
        }
        else
            throw entityNotFound();
    }
    else
        throw EmptyName();
}
//----------------------------------------------------------
void System::addFan(Member* MemberPTR , FanPage* FanPagePTR) //Adds a fan to a fan page's members array.
{
    try 
    {
        *MemberPTR += *FanPagePTR;
        *FanPagePTR += *MemberPTR;
    }
     catch (addAFanException& error) { throw addAFanException(error); }
     catch(...) {throw GlobalExceptions();}
}
//----------------------------------------------------------
void System::removeFan(Member* MemberPTR, FanPage* FanPagePTR) //Removes a fan from a fan page's members array.
{
    try 
    {
        *MemberPTR -= *FanPagePTR;
        *FanPagePTR -= *MemberPTR;
    }
    catch(removeAFanException& error) {throw removeAFanException(error);}
    catch (...) {throw GlobalExceptions();}
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
    catch(invalidUserDecision& error) {throw error;}
    catch(...) {throw systemExceptions();}
    getline(cin, name);

    const unordered_map<string, Entity*>& placeHolderMember = Entities[std::type_index(typeid(Member*))];
    const unordered_map<string, Entity*>& fanPagePlaceHolder = Entities[std::type_index(typeid(FanPage*))];
    if (!name.empty())
    {
        if (placeHolderMember.find(name) != placeHolderMember.end() ||
            fanPagePlaceHolder.find(name) != fanPagePlaceHolder.end())
        {
            if (decision == MEMBER_CHOOSE)
            {
                try 
                {dynamic_cast<Member*>(placeHolderMember.at(name))->Entity::addStatus(); }
                catch (EmptyStatus& error) { throw error; }
                catch (invalidStatusType& error) { throw error; }
                catch (...) { throw StatusExceptions(); }
            }

            else if (decision == FAN_PAGE_CHOOSE)
            {
                try {dynamic_cast<FanPage*>(fanPagePlaceHolder.at(name))->Entity::addStatus();}
                catch (EmptyStatus& error) { throw error; }
                catch (invalidStatusType& error) { throw error; }
                catch (...) { throw StatusExceptions(); }
            }
        }

        else
            throw entityNotFound();
    }
    else
        throw EmptyName();
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
void System::printAllStatuses() //Prints an entity's statuses.
{
    int decision;
    string name;
    cout << "Please choose the entity of which you want to view statuses:";

    try {decision = System::memberOrFanPage();}
    catch(invalidUserDecision& error) {throw invalidUserDecision(error);}
    catch(...) {throw systemExceptions();}
    getline(cin, name);

    if (!name.empty())
    {
        const unordered_map<string, Entity*>& placeHolderMember = Entities[std::type_index(typeid(Member*))];
        const unordered_map<string, Entity*>& fanPagePlaceHolder = Entities[std::type_index(typeid(FanPage*))];

        if (placeHolderMember.find(name) != placeHolderMember.end() ||
        fanPagePlaceHolder.find(name) != fanPagePlaceHolder.end())
        {
            if (decision == MEMBER_CHOOSE)
            {
                try{ dynamic_cast<Member*>(placeHolderMember.at(name))->Entity::printAllStatuses(); }
                catch (entityHasNoStatuses& error) {throw error;}
                catch (...) {throw EntityExceptions();}
            }

            else if (decision == FAN_PAGE_CHOOSE)
            {
                try { dynamic_cast<FanPage*>(fanPagePlaceHolder.at(name))->Entity::printAllStatuses(); }
                catch (entityHasNoStatuses& error) {throw error;}
                catch (...) {throw EntityExceptions();}
            }
        }
        else
            throw entityNotFound();
    }
    throw EmptyName();
}
//----------------------------------------------------------
void System::printTenLastStatuses() //Prints a member's friends ten last statuses.
{
    string name;
    int i = 0;
    cout << "Please enter a member's name: ";
    cin.ignore();
    getline(cin, name);
    const unordered_map<string, Entity*>& memberPlaceHolder = Entities[std::type_index(typeid(Member*))];
    if (!name.empty())
    {
        if (memberPlaceHolder.find(name) != memberPlaceHolder.end())
        {
            const unordered_map<string, Member*>& u_memberMap = memberPlaceHolder.at(name)->Entity::getMembers();
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
                        try { value->Member::printTenLastStatuses(); }
                        catch (memberPrintStatusesException& error) { throw memberPrintStatusesException(error); }
                        catch (...) { throw memberExceptions(); }
                    }
                }
            }

            else
                throw printFriendsException();
        }

        else
            throw memberNotFound();

    }
    else
        throw EmptyName();

}
//----------------------------------------------------------
void System::printAllEntities() //Prints all entities.
{

    if (Entities.empty())
        throw EmptySystemExceptions();
    else
    {
        const unordered_map<string, Entity*>& placeHolderFanPage = Entities[std::type_index(typeid(FanPage*))];
        const unordered_map<string, Entity*>& placeHolderMember = Entities[std::type_index(typeid(Member*))];
        if (!placeHolderMember.empty())
        {
            cout << "------------------------------------\nOur system's "
                    "members list:\n------------------------------------" << endl;
    
            for (const auto& kv: placeHolderMember)
            {
                const auto& key = kv.first;
                cout << "\t" << key << endl;
            }
        }
        else
        {
            throw noMembersInSystem();
        }
        if (!placeHolderFanPage.empty())
        {
            cout << "------------------------------------\nOur system's "
                "fan pages list:\n------------------------------------" << endl;

            for (const auto& kv : placeHolderFanPage)
            {
                const auto& key = kv.first;
                cout << "\t" << key << endl;
            }
        }
        else
        {
            throw noPagesInSystem();
        }      
    }
}
//----------------------------------------------------------
void System::printAllFriends()  //Prints an entity's friends.
{
    int decision;
    string entityName;
    cout << "Please enter the entity of which you want to view its friends:";

    try {decision = System::memberOrFanPage();}
    catch(invalidUserDecision& error) {throw invalidUserDecision(error);}
    catch(...) {throw systemExceptions();}
    getline(cin, entityName);
    if (!entityName.empty())
    { 
        const unordered_map<string, Entity*>& placeHolderMember = Entities[std::type_index(typeid(Member*))];
        const unordered_map<string, Entity*>& placeHolderFanPage = Entities[std::type_index(typeid(FanPage*))];
        if (placeHolderFanPage.find(entityName) != placeHolderFanPage.end() ||
            placeHolderMember.find(entityName) != placeHolderMember.end())
        {
            if (decision == MEMBER_CHOOSE)
            {
                auto* MemberPTR = dynamic_cast<Member*>(placeHolderMember.at(entityName));
                try { MemberPTR->Entity::printMembers();}
                catch (printFriendsException& error) { throw printFriendsException(error); }
                catch (...) { throw memberExceptions(); }
            }
            else if (decision == FAN_PAGE_CHOOSE)
            {
                auto* FanPagePTR = dynamic_cast<FanPage*>(placeHolderFanPage.at(entityName));
                try { FanPagePTR->Entity::printMembers();}
                catch (printFansException& error) { throw printFansException(error); }
                catch (...) { throw fanPageExceptions(); }
            }
        }
        else
            throw entityNotFound();
    }
    else
        throw EmptyName();
}
//----------------------------------------------------------


//Files methods
//----------------------------------------------------------
void System::writeData() //Writes system data to a bin file.
{
    ofstream dataBinFile("SystemData.bin", std::ios_base::binary|std::ios_base::out);
    if (dataBinFile.good())
    {
        const unordered_map<string, Entity*>& placeHolderMember = Entities[std::type_index(typeid(Member*))];
        const unordered_map<string, Entity*>& placeHolderFanPage = Entities[std::type_index(typeid(FanPage*))];

        dataBinFile.write((const char*)placeHolderMember.size(), sizeof(placeHolderMember.size()));

        for (const auto& kv : placeHolderMember)
        {
            dataBinFile.write((const char*)kv.first.c_str(), sizeof(kv.first.c_str()));
            dataBinFile.write((const char*) dynamic_cast<Member*>(kv.second)->getBirthday().day,
                              sizeof(dynamic_cast<Member*>(kv.second)->getBirthday().day));
            dataBinFile.write((const char*) dynamic_cast<Member*>(kv.second)->getBirthday().month,
                              sizeof(dynamic_cast<Member*>(kv.second)->getBirthday().day));
            dataBinFile.write((const char*) dynamic_cast<Member*>(kv.second)->getBirthday().year,
                              sizeof(dynamic_cast<Member*>(kv.second)->getBirthday().day));
            dataBinFile.write((const char*) dynamic_cast<Member*>(kv.second)->getNumOfStatuses(),
                              sizeof(dynamic_cast<Member*>(kv.second)->getNumOfStatuses()));

            const vector<Status*> memberStatuses = dynamic_cast<Member*>(kv.second)->getBulletinBoard();

            for (const auto& sv : memberStatuses)
            {
                dataBinFile.write((const char*)sv->getStatusDate().day, sizeof(sv->getStatusDate().day));
                dataBinFile.write((const char*)sv->getStatusDate().month, sizeof(sv->getStatusDate().month));
                dataBinFile.write((const char*)sv->getStatusDate().year, sizeof(sv->getStatusDate().year));
                dataBinFile.write((const char*)sv->getStatusTime().seconds.c_str(),
                                  sizeof(sv->getStatusTime().seconds.c_str()));
                dataBinFile.write((const char*)sv->getStatusTime().minutes.c_str(),
                                  sizeof(sv->getStatusTime().minutes.c_str()));
                dataBinFile.write((const char*)sv->getStatusTime().hour.c_str(),
                                  sizeof(sv->getStatusTime().hour.c_str()));
                dataBinFile.write((const char*)sv->getStatusType(), sizeof(sv->getStatusType()));
                dataBinFile.write((const char*)sv->getStatusContent().c_str(), sizeof(sv->getStatusContent().c_str()));
            }
        }

        for (const auto& kv : placeHolderFanPage)
        {
            dataBinFile.write((const char*)kv.first.c_str(), sizeof(kv.first));
            dataBinFile.write((const char*) dynamic_cast<FanPage*>(kv.second)->getNumOfStatuses(),
                              sizeof(dynamic_cast<FanPage*>(kv.second)->getNumOfStatuses()));

            const vector<Status*> fanPageStatuses = dynamic_cast<FanPage*>(kv.second)->getBulletinBoard();

            for (const auto& sv : fanPageStatuses)
            {
                dataBinFile.write((const char*)sv->getStatusDate().day, sizeof(sv->getStatusDate().day));
                dataBinFile.write((const char*)sv->getStatusDate().month, sizeof(sv->getStatusDate().month));
                dataBinFile.write((const char*)sv->getStatusDate().year, sizeof(sv->getStatusDate().year));
                dataBinFile.write((const char*)sv->getStatusTime().seconds.c_str(),
                                  sizeof(sv->getStatusTime().seconds.c_str()));
                dataBinFile.write((const char*)sv->getStatusTime().minutes.c_str(),
                                  sizeof(sv->getStatusTime().minutes.c_str()));
                dataBinFile.write((const char*)sv->getStatusTime().hour.c_str(),
                                  sizeof(sv->getStatusTime().hour.c_str()));
                dataBinFile.write((const char*)sv->getStatusType(), sizeof(sv->getStatusType()));
                dataBinFile.write((const char*)sv->getStatusContent().c_str(), sizeof(sv->getStatusContent().c_str()));
            }
        }
    }
}
//----------------------------------------------------------


//Commented Methods
//----------------------------------------------------------
//void System::createMember(const string& _name, Date& _date) //For hard-coded data.
//{
//    if (this->members.find(_name) == this->members.end())
//        this->members[_name] = Member{ _name,_date };
//}
//----------------------------------------------------------
//void System::initialData() //Inserts hard-coded data.
//{
//    Date eliDay = { 24, 04, 1995 };
//    Date bencoDay = { 23, 12, 1997 };
//    Date benhanDay = { 12, 01, 1998 };
//    Date ramezDay = { 05, 07, 1999 };
//    this->Entities.reserve(4);
//    this->createMember("Elior Migdal", eliDay);
//    this->newStatus("Elior Migdal", MEMBER, "Hi Facebook!");
//    this->createMember("Ben Cohen", bencoDay);
//    this->newStatus("Elior Migdal", MEMBER, "Hi Ben :) Wassup! @Ben Cohen");
//    this->connectMembersHardCoded(&this->members.at("Elior Migdal"), &this->members.at("Ben Cohen"));
//    this->newStatus("Ben Cohen", MEMBER, "Eli ya habibi");
//    this->createMember("Ben Hanover", benhanDay);
//    this->newStatus("Ben Hanover", MEMBER, "Yoooooyooooooo");
//    this->connectMembersHardCoded(&this->members.at("Elior Migdal"), &this->members.at("Ben Hanover"));
//    this->newStatus("Elior Migdal", MEMBER, "Yo Yo Ben!");
//    this->createMember("Ramez Mannaa", ramezDay);
//    this->newStatus("Ben Cohen", MEMBER, "I'm the king!");
//    this->newStatus("Ben Hanover", MEMBER, "I know I'm the king bro");
//    this->newStatus("Ramez Mannaa", MEMBER, "I'm here too!");
//    this->newStatus("Ramez Mannaa", MEMBER, "Who wants to be my friend?");
//    this->connectMembersHardCoded(&this->members.at("Ben Cohen"), &this->members.at("Ramez Mannaa"));
//    this->connectMembersHardCoded(&this->members.at("Ben Cohen"), &this->members.at("Ben Hanover"));
//    this->createFanPage("The Bens");
//    this->createFanPage("We love Tel-Aviv");
//    this->createFanPage("They were on a break!");
//    this->connectMembersHardCoded(&this->members.at("Ramez Mannaa"), &this->members.at("Elior Migdal"));
//    this->connectMembersHardCoded(&this->members.at("Ramez Mannaa"), &this->members.at("Ben Hanover"));
//    this->newStatus("The Bens", FAN_PAGE, "We are the Bens!");
//    this->addFanHardCoded("The Bens", "Ben Cohen");
//    this->newStatus("Ben Cohen", MEMBER, "I JOINED THE BENS!!!");
//    this->addFanHardCoded("The Bens", "Ben Hanover");
//    this->newStatus("Ben Hanover", MEMBER, "ME TOO!");
//    this->newStatus("The Bens", FAN_PAGE, "WE HAVE TWO NEW MEMBERS!!");
//    this->removeFanHardCoded("The Bens", "Ben Cohen");
//    this->newStatus("Ben Cohen", MEMBER, "Now I left...");
//    this->newStatus("The Bens", FAN_PAGE, ":(");
//    this->addFanHardCoded("The Bens", "Ramez Mannaa");
//    this->addFanHardCoded("They were on a break!", "Elior Migdal");
//    this->addFanHardCoded("They were on a break!", "Ben Cohen");
//    this->addFanHardCoded("They were on a break!", "Ben Hanover");
//    this->newStatus("Elior Migdal", MEMBER, "They were on a break!!!");
//    this->newStatus("They were on a break!", FAN_PAGE, "@Elior yes they were!");
//    this->newStatus("They were on a break!", FAN_PAGE, "@Ben Cohen what do you think?");
//    this->newStatus("Ben Cohen", MEMBER, "Yes yes");
//    this->newStatus("They were on a break!", FAN_PAGE, "Good good");
//    this->newStatus("Ben Hanover", MEMBER, "YES!!!!!!!!!");
//    this->newStatus("We love Tel-Aviv", FAN_PAGE, "We LOVE Tel Aviv!!");
//    this->addFanHardCoded("We love Tel-Aviv", "Ramez Mannaa");
//    this->addFanHardCoded("We love Tel-Aviv", "Ben Cohen");
//    this->addFanHardCoded("We love Tel-Aviv", "Ben Hanover");
//    this->newStatus("We love Tel-Aviv", FAN_PAGE, "Welcome Tel Aviv Lovers!!");
//    this->newStatus("We love Tel-Aviv", FAN_PAGE, "Where is @Elior Migdal?");
//    this->newStatus("Ramez Mannaa", MEMBER, "@WLTLV He Hates TLV!!");
//    this->newStatus("We love Tel-Aviv", FAN_PAGE, "NO WAY!!!!%^%$^#%");
//    this->disconnectMembersHardCoded(&this->members.at("Ben Cohen"), &this->members.at("Elior Migdal"));
//    this->disconnectMembersHardCoded(&this->members.at("Ben Hanover"), &this->members.at("Elior Migdal"));
//    this->disconnectMembersHardCoded(&this->members.at("Ramez Mannaa"), &this->members.at("Elior Migdal"));
//    this->newStatus("Elior Migdal", MEMBER, "LOL you all left me!");
//    this->newStatus("Elior Migdal", MEMBER, "yo GUYS");
//    this->connectMembersHardCoded(&this->members.at("Elior Migdal"), &this->members.at("Ben Hanover"));
//    this->connectMembersHardCoded(&this->members.at("Elior Migdal"), &this->members.at("Ben Cohen"));
//    this->connectMembersHardCoded(&this->members.at("Elior Migdal"), &this->members.at("Ramez Mannaa"));
//    this->newStatus("Elior Migdal", MEMBER, "yo GUYS");
//    this->newStatus("Elior Migdal", MEMBER, "yeaaaaaaa");
//    this->newStatus("Elior Migdal", MEMBER, "hello people");
//    this->newStatus("Elior Migdal", MEMBER, "wassup");
//    this->newStatus("Elior Migdal", MEMBER, "I LOVE C++");
//    this->newStatus("Elior Migdal", MEMBER, "but python is better");
//    this->newStatus("Elior Migdal", MEMBER, "just kidding");
//    this->newStatus("Elior Migdal", MEMBER, "or not....");
//    this->newStatus("Elior Migdal", MEMBER, ";)");
//}
//----------------------------------------------------------
//void System::CreateFanPageORMember(void(System::* operation)(Entity*)) //Adds or removes a fan.
//{
//    string name;
//    cin.ignore();
//    getline(cin, name);
//    if (!name.empty())
//    {
//
//        if (Entities.find(name) != Entities.end())
//        {
//            FanPage* fp = dynamic_cast<FanPage*>(Entities[name]);
//            if (fp)
//            {
//                if (Entities.find(name) == Entities.end())
//                {
//
//                }
//                throw pageAlreadyExists();
//            }
//            else
//            {
//                throw userAlreadyExists();
//            }
//         /*   throw EntityAlreadyExists();*/
//        }
//        else
//        {
//            try { (this->*operation)(Entities[name]); }
//            catch(addAFriendException& error) {throw addAFriendException(error);}
//            catch(removeAFriendException& error) {throw removeAFriendException(error);}
//            catch(connectSameMember& error) {throw connectSameMember(error);}
//            catch(removeSameMember& error) {throw removeSameMember(error);}
//            catch(...) {throw memberExceptions();}
//        }
//    }
//    else
//        throw EmptyName();
//}
//----------------------------------------------------------
//void System::connectMembersHardCoded(Member* member1, Member* member2) //Connect members for hard-coded data.
//{
//    *member1 += member2;
//    *member2 += member1;
//}
//----------------------------------------------------------
//void System::disconnectMembersHardCoded(Member* member1, Member* member2) //Disconnect members for hard-coded data.
//{
//    *member1 -= member2;
//    *member2 -= member1;
//}
//----------------------------------------------------------
//void System::createFanPage(const string& _name) //Creates a fan page for hard-coded data.
//{
//    if (this->pages.find(_name) == this->pages.end())
//        this->pages[_name] = FanPage(_name);
//}
//----------------------------------------------------------
//void System::addFanHardCoded(const string& pageName, const string& fanName) //Add fan for hard-coded data.
//{
//    this->members.at(fanName) += &this->pages.at(pageName);
//    this->pages.at(pageName) += &this->members.at(fanName);
//}
//----------------------------------------------------------
//void System::removeFanHardCoded(const string& pageName, const string& fanName) //Remove fan for hard-coded data.
//{
//    this->pages.at(pageName) -= &this->members.at(fanName);
//    this->members.at(fanName) -= &this->pages.at(pageName);
//}
//----------------------------------------------------------
//void System::newStatus(const string& name, const size_SI& type, const string& statusContent) //Creates a new status for hard-coded data.
//{
//    if (type == MEMBER)
//        this->members.at(name).Member::addStatus(statusContent);
//
//    else if (type == FAN_PAGE)
//        this->pages.at(name).FanPage::addStatus(statusContent);
//}
//----------------------------------------------------------