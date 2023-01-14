#include "../Headers/System.h"
#include "../Headers/FanPage.h"
#include "../Headers/Member.h"

//System constructor
//----------------------------------------------------------
System::System() noexcept(false) //Reading data constructor.
{
    try{readData();}
    catch(corruptFile& error) {throw error;}
    catch(...) {throw systemExceptions();}
}
//----------------------------------------------------------

//Start Function
//----------------------------------------------------------
void System::Start() //Boots up the system.
{
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
    try { System::writeData(); }
    catch (corruptFile& error) { cout << error.what() << endl; }
    catch (...) { cout << systemExceptions().what() << endl; };
   
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
            try{System::Connect_OR_DisconnectMember(true);}
            catch(addAFriendException& error) {throw addAFriendException(error);}
            catch(connectSameMember& error) {throw connectSameMember(error);}
            catch(memberExceptions& error) {throw memberExceptions(error);}
            catch(memberNotFound& error) {throw memberNotFound(error);}
            catch(...) {throw systemExceptions();}
            break;
        //////////////////////////////////////////////////////////////////////////////////////////
        case (size_SI)DISCONNECTMEMBERS: //7
            try{System::Connect_OR_DisconnectMember(false);}
            catch(removeAFriendException& error) {throw removeAFriendException(error);}
            catch(removeSameMember& error) {throw removeSameMember(error);}
            catch(memberExceptions& error) {throw memberExceptions(error);}
            catch(memberNotFound& error) {throw memberNotFound(error);}
            catch(...) {throw systemExceptions();}
            break;
        //////////////////////////////////////////////////////////////////////////////////////////
        case (size_SI)ADDFAN: //8
            try{System::Add_OR_RemoveFAN(true);}
            catch (addAFanException& error) { throw addAFanException(error); }
            catch(entityNotFound& error) {throw entityNotFound(error);}
            catch(...) {throw GlobalExceptions();}
            break;
        //////////////////////////////////////////////////////////////////////////////////////////
        case (size_SI)REMOVEFAN: //9
            try{System::Add_OR_RemoveFAN(false);}
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
void System::Connect_OR_DisconnectMember(bool connect) //General method for connection
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
        
        if (firstMemberName == secondMemberName)
        {
            (connect) ? throw connectSameMember() : throw removeSameMember();
        }
        if (placeHolder.find(firstMemberName) != placeHolder.end() &&
            placeHolder.find(secondMemberName) != placeHolder.end())
        {
            try {
                connectOrDisconnectMembers(dynamic_cast<Member*>(placeHolder.at(firstMemberName)), 
                    dynamic_cast<Member*>(placeHolder.at(secondMemberName)), connect);
            }
            catch (addAFriendException& error) { throw addAFriendException(error); }
            catch (removeAFriendException& error) { throw removeAFriendException(error); }
            catch (...) { throw memberExceptions(); }
        }

        else
            throw memberNotFound();
    }
    else
        throw EmptyName();
}
//----------------------------------------------------------
void System::connectOrDisconnectMembers(Member* firstMember, Member* secondMember, bool connect) //Executes connection/removal.
{
    try {
        if (connect) {
            *firstMember += *secondMember;
            *secondMember += *firstMember;
        }
        else {
            *firstMember -= *secondMember;
            *secondMember -= *firstMember;
        }
    }
    catch (addAFriendException& error) {
        throw addAFriendException(error);
    }
    catch (removeAFriendException& error) {
        throw removeAFriendException(error);
    }
   
    catch (...) {
        throw memberExceptions();
    }
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
void System::Add_OR_RemoveFAN(bool connect) //Adds or removes a fan.
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
            try {
                addOrRemoveFanUtility(dynamic_cast<Member*>(placeHolderMember.at(memberName)),
                    dynamic_cast<FanPage*>(placeHolderFanPage.at(fanPageName)), connect);
            }
            catch (addAFanException& error) { throw addAFanException(error); }
            catch (removeAFanException& error) { throw removeAFanException(error); }
            catch (GlobalExceptions& error) { throw GlobalExceptions(error); }
            catch (...) { throw systemExceptions(); }
        }
        else
            throw entityNotFound();
    }
    else
        throw EmptyName();
}
//----------------------------------------------------------
void System::addOrRemoveFanUtility(Member* Member, FanPage* Fanpage, bool connect) //Executes connection/removal.
{
    try {
        if (connect) {
            *Member += *Fanpage;
            *Fanpage += *Member;
        }
        else {
            *Member -= *Fanpage;
            *Fanpage -= *Member;
        }
    }
    catch (addAFriendException& error) {
        throw addAFriendException(error);
    }
    catch (removeAFriendException& error) {
        throw removeAFriendException(error);
    }
    catch (...) {
        throw memberExceptions();
    }
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
        if (decision == MEMBER_CHOOSE && placeHolderMember.find(name) != placeHolderMember.end() )
        {
            try 
            {dynamic_cast<Member*>(placeHolderMember.at(name))->Entity::addStatus(); }
            catch (EmptyStatus& error) { throw error; }
            catch (invalidStatusType& error) { throw error; }
            catch (...) { throw StatusExceptions(); }
        }
        else if  (decision == FAN_PAGE_CHOOSE && fanPagePlaceHolder.find(name) != fanPagePlaceHolder.end())
        {
            try {dynamic_cast<FanPage*>(fanPagePlaceHolder.at(name))->Entity::addStatus();}
            catch (EmptyStatus& error) { throw error; }
            catch (invalidStatusType& error) { throw error; }
            catch (...) { throw StatusExceptions(); }
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
        if (decision == MEMBER_CHOOSE && placeHolderMember.find(name) != placeHolderMember.end())
        {
            try{ dynamic_cast<Member*>(placeHolderMember.at(name))->Entity::printAllStatuses(); }
            catch (entityHasNoStatuses& error) {throw error;}
            catch (...) {throw EntityExceptions();}
        }

        else if (decision == FAN_PAGE_CHOOSE && fanPagePlaceHolder.find(name) != fanPagePlaceHolder.end())
        {
            try { dynamic_cast<FanPage*>(fanPagePlaceHolder.at(name))->Entity::printAllStatuses(); }
            catch (entityHasNoStatuses& error) { throw error; }
            catch (...) { throw EntityExceptions(); }
        }
        else
            throw entityNotFound();
    }
    else
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
void System::readData() //Reads data from bin file pre-startup.
{
    Entities[std::type_index(typeid(FanPage*))] = {};
    Entities[std::type_index(typeid(Member*))] = {};
    std::ifstream dataBinFile("SystemData.bin", std::ios_base::binary | std::ios_base::in);
    if (dataBinFile.peek() != std::ifstream::traits_type::eof())
    {
        if (dataBinFile.good()) {
            size_t membersSize, fanPagesSize;
            dataBinFile.read(reinterpret_cast<char*>(&membersSize), sizeof(membersSize));
            for (size_t i = 0; i < membersSize; i++) {
                std::string memberName;
                Date memberBirthday;
                size_t numOfStatuses;
                std::getline(dataBinFile, memberName, '\0');
                dataBinFile.read(reinterpret_cast<char*>(&memberBirthday.day), sizeof(memberBirthday.day));
                dataBinFile.read(reinterpret_cast<char*>(&memberBirthday.month), sizeof(memberBirthday.month));
                dataBinFile.read(reinterpret_cast<char*>(&memberBirthday.year), sizeof(memberBirthday.year));
                dataBinFile.read(reinterpret_cast<char*>(&numOfStatuses), sizeof(numOfStatuses));
                auto* member = new Member(memberName, memberBirthday);
                for (size_t j = 0; j < numOfStatuses; j++) {
                    Date statusDate;
                    Time statusTime;
                    int statusType = 0;
                    string statusContent, fileName;
                    dataBinFile.read(reinterpret_cast<char*>(&statusDate.day), sizeof(statusDate.day));
                    dataBinFile.read(reinterpret_cast<char*>(&statusDate.month), sizeof(statusDate.month));
                    dataBinFile.read(reinterpret_cast<char*>(&statusDate.year), sizeof(statusDate.year));
                    std::getline(dataBinFile, statusTime.seconds, '\0');
                    std::getline(dataBinFile, statusTime.minutes, '\0');
                    std::getline(dataBinFile, statusTime.hour, '\0');
                    dataBinFile.read(reinterpret_cast<char*>(&statusType), sizeof(statusType));
                    auto s = (STATUS_TYPE)statusType;
                    std::getline(dataBinFile, statusContent, '\0');

                    if (s != STATUS_TYPE::TEXT)
                        std::getline(dataBinFile, fileName, '\0');

                    member->addStatusFromFile(statusDate, statusTime, statusContent, s, fileName);

                }
                Entities[std::type_index(typeid(Member*))][memberName] = member;
            }
            dataBinFile.read(reinterpret_cast<char*>(&fanPagesSize), sizeof(fanPagesSize));
            for (size_t i = 0; i < fanPagesSize; i++) {
                string fanPageName;
                size_t numOfStatuses;
                std::getline(dataBinFile, fanPageName, '\0');
                dataBinFile.read(reinterpret_cast<char*>(&numOfStatuses), sizeof(size_t));
                auto* fanPage = new FanPage(fanPageName);
                for (size_t j = 0; j < numOfStatuses; j++) {
                    Date statusDate;
                    Time statusTime;
                    int statusType = 0;
                    std::string statusContent, fileName;
                    dataBinFile.read(reinterpret_cast<char*>(&statusDate.day), sizeof(statusDate.day));
                    dataBinFile.read(reinterpret_cast<char*>(&statusDate.month), sizeof(statusDate.month));
                    dataBinFile.read(reinterpret_cast<char*>(&statusDate.year), sizeof(statusDate.year));
                    std::getline(dataBinFile, statusTime.seconds, '\0');
                    std::getline(dataBinFile, statusTime.minutes, '\0');
                    std::getline(dataBinFile, statusTime.hour, '\0');
                    dataBinFile.read(reinterpret_cast<char*>(&statusType), sizeof(statusType));
                    std::getline(dataBinFile, statusContent, '\0');
                    auto s = (STATUS_TYPE)statusType;

                    if (s != STATUS_TYPE::TEXT)
                        std::getline(dataBinFile, fileName, '\0');

                    fanPage->addStatusFromFile(statusDate, statusTime, statusContent, s, fileName);
                }
                Entities[std::type_index(typeid(FanPage*))][fanPageName] = fanPage;
            }
            for (int i = 0; i < membersSize; ++i) 
            {
                string nameToAdd;
                size_t numOfMembers;
                size_t numOfPages;
                std::getline(dataBinFile, nameToAdd, '\0');
     
                dataBinFile.read(reinterpret_cast<char*>(&numOfMembers), sizeof(numOfMembers));
                Member* currMember = dynamic_cast<Member*>(Entities[std::type_index(typeid(Member*))][nameToAdd]);
                for (int i = 0; i < numOfMembers; ++i)
                {
                    string friendName;
                    std::getline(dataBinFile, friendName, '\0');

                    currMember->addMember(*(dynamic_cast<Member*>(Entities[std::type_index(typeid(Member*))][friendName])));
                }
                dataBinFile.read(reinterpret_cast<char*>(&numOfPages), sizeof(numOfPages));
                for (int i = 0; i < numOfPages; ++i)
                {
                    string pageToAdd; 
                    std::getline(dataBinFile, pageToAdd, '\0');

                   currMember->addFanPage(*(dynamic_cast<FanPage*>(Entities[std::type_index(typeid(FanPage*))][pageToAdd])));
                }
            }
            for (int i = 0; i < fanPagesSize; ++i)
            {
                string currFanPageName;
                size_t numOfMembers;
                std::getline(dataBinFile, currFanPageName, '\0');

                dataBinFile.read(reinterpret_cast<char*>(&numOfMembers), sizeof(numOfMembers));
                FanPage* currFanPage = dynamic_cast<FanPage*>(Entities[std::type_index(typeid(FanPage*))][currFanPageName]);
                for (int i = 0; i < numOfMembers; ++i)
                {
                    string memberToAdd;
                    std::getline(dataBinFile, memberToAdd, '\0');

                    currFanPage->addMember(*(dynamic_cast<Member*>(Entities[std::type_index(typeid(Member*))][memberToAdd])));
                }
            }            
        }
        else
          throw corruptFile();
    }

    dataBinFile.close();
}
//----------------------------------------------------------
void System::writeData() //Writes current system data to bin file.
{
    std::ofstream dataBinFile("SystemData.bin", std::ios_base::binary | std::ios_base::out | std::ios_base::trunc);
    if (dataBinFile.good()) {
         const auto& placeHolderMember = Entities[std::type_index(typeid(Member*))];
         const auto& placeHolderFanPage = Entities[std::type_index(typeid(FanPage*))];

         size_t s = placeHolderMember.size();

         if (!placeHolderMember.empty()) {
             dataBinFile.write(reinterpret_cast<const char*>(&s), sizeof(s));
         }

        for (const auto& kv : placeHolderMember) {
            dataBinFile.write(kv.first.c_str(), kv.first.size() + 1);

            auto* member = dynamic_cast<Member*>(kv.second);
            size_t NumOfStatuses = member->getNumOfStatuses();
            dataBinFile.write(reinterpret_cast<const char*>(&member->getBirthday().day), sizeof(member->getBirthday().day));
            dataBinFile.write(reinterpret_cast<const char*>(&member->getBirthday().month), sizeof(member->getBirthday().month));
            dataBinFile.write(reinterpret_cast<const char*>(&member->getBirthday().year), sizeof(member->getBirthday().year));
            dataBinFile.write(reinterpret_cast<const char*>(&NumOfStatuses), sizeof(NumOfStatuses));

            const auto& memberStatuses = member->getBulletinBoard();

            for (const auto& sv : memberStatuses) {
                dataBinFile.write(reinterpret_cast<const char*>(&sv->getStatusDate().day), sizeof(sv->getStatusDate().day));
                dataBinFile.write(reinterpret_cast<const char*>(&sv->getStatusDate().month), sizeof(sv->getStatusDate().month));
                dataBinFile.write(reinterpret_cast<const char*>(&sv->getStatusDate().year), sizeof(sv->getStatusDate().year));
                dataBinFile.write(sv->getStatusTime().seconds.c_str(), sv->getStatusTime().seconds.size() + 1);
                dataBinFile.write(sv->getStatusTime().minutes.c_str(), sv->getStatusTime().minutes.size() + 1);
                dataBinFile.write(sv->getStatusTime().hour.c_str(), sv->getStatusTime().hour.size() + 1);
                dataBinFile.write(reinterpret_cast<const char*>(&sv->getStatusType()), sizeof(sv->getStatusType()));
                dataBinFile.write(sv->getStatusContent().c_str(), sv->getStatusContent().size() + 1);

                if (sv->getStatusType() == STATUS_TYPE::IMAGE)
                    dataBinFile.write((dynamic_cast<ImageStatus*>(sv)->getFileName().c_str()),
                                      dynamic_cast<ImageStatus*>(sv)->getFileName().size() + 1);

                if ((sv->getStatusType() == STATUS_TYPE::VIDEO))
                    dataBinFile.write(dynamic_cast<VideoStatus*>(sv)->getFileName().c_str(),
                                      dynamic_cast<VideoStatus*>(sv)->getFileName().size() + 1);
            }
        }
        size_t fanpageSize = placeHolderFanPage.size();
        dataBinFile.write(reinterpret_cast<const char*>(&fanpageSize), sizeof(fanpageSize));
        
        for (const auto& kv : placeHolderFanPage) {
            dataBinFile.write(kv.first.c_str(), kv.first.size() + 1);

            auto* fanPage = dynamic_cast<FanPage*>(kv.second);
            size_t numOfstatuses = fanPage->getNumOfStatuses();
            dataBinFile.write(reinterpret_cast<const char*>(&numOfstatuses), sizeof(numOfstatuses));

            const auto& fanPageStatuses = fanPage->getBulletinBoard();

            for (const auto& sv : fanPageStatuses) {
                const auto& statusType = sv->getStatusType();
                dataBinFile.write(reinterpret_cast<const char*>(&sv->getStatusDate().day), sizeof(sv->getStatusDate().day));
                dataBinFile.write(reinterpret_cast<const char*>(&sv->getStatusDate().month), sizeof(sv->getStatusDate().month));
                dataBinFile.write(reinterpret_cast<const char*>(&sv->getStatusDate().year), sizeof(sv->getStatusDate().year));
                dataBinFile.write(sv->getStatusTime().seconds.c_str(), sv->getStatusTime().seconds.size() + 1);
                dataBinFile.write(sv->getStatusTime().minutes.c_str(), sv->getStatusTime().minutes.size() + 1);
                dataBinFile.write(sv->getStatusTime().hour.c_str(), sv->getStatusTime().hour.size() + 1);
                dataBinFile.write(reinterpret_cast<const char*>(&statusType), sizeof(statusType));
                dataBinFile.write(sv->getStatusContent().c_str(), sv->getStatusContent().size() + 1);

                if (sv->getStatusType() == STATUS_TYPE::IMAGE)
                    dataBinFile.write((dynamic_cast<ImageStatus*>(sv)->getFileName().c_str()),
                                      dynamic_cast<ImageStatus*>(sv)->getFileName().size() + 1);

                if ((sv->getStatusType() == STATUS_TYPE::VIDEO))
                    dataBinFile.write(dynamic_cast<VideoStatus*>(sv)->getFileName().c_str(),
                                      dynamic_cast<VideoStatus*>(sv)->getFileName().size() + 1);
            }
        }
        for (const auto& kv : placeHolderMember)
        {
            size_t numOfMembers = dynamic_cast<Member*>(kv.second)->Member::getNumOfMembers();
            size_t numOfPages = dynamic_cast<Member*>(kv.second)->Member::getNumOfPages();
            dataBinFile.write(kv.first.c_str(), kv.first.size() + 1);
            dataBinFile.write(reinterpret_cast<const char*>(&numOfMembers),
                sizeof(numOfMembers));
            const unordered_map<string, Member*> memberFriends = dynamic_cast<Member*>(kv.second)->Member::getMembers();

            for (const auto& mv : memberFriends)
                dataBinFile.write(mv.first.c_str(), mv.first.size() + 1);

            const unordered_map<string, FanPage*> memberPages = dynamic_cast<Member*>(kv.second)->Member::getPages();
            dataBinFile.write(reinterpret_cast<const char*>(&numOfPages),
                sizeof(numOfPages));

            for (const auto& pv : memberPages)
                dataBinFile.write(pv.first.c_str(), pv.first.size()+1);

        }

        for (const auto& kv : placeHolderFanPage)
        {
            size_t numOfMembers = dynamic_cast<FanPage*>(kv.second)->FanPage::getNumOfMembers();
            dataBinFile.write(kv.first.c_str(), kv.first.size() + 1);
            dataBinFile.write(reinterpret_cast<const char*>(&numOfMembers),
                sizeof(numOfMembers));
            const unordered_map<string, Member*> pagesFans = dynamic_cast<FanPage*>(kv.second)->FanPage::getMembers();

            for (const auto& pf : pagesFans)
                dataBinFile.write(pf.first.c_str(), pf.first.size() + 1);
        }
    }

    else
        throw corruptFile();

    dataBinFile.close();
}
//----------------------------------------------------------