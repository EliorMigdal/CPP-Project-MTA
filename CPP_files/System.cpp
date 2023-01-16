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
        catch (systemExceptions& error) {cout << error.what() << endl;}
        catch (EmptySystemExceptions& error) {cout << error.what() << endl;}
        catch (EntityExceptions& error) {cout << error.what() << endl;}
        catch (memberExceptions& error) {cout << error.what() << endl;}
        catch (fanPageExceptions& error) {cout << error.what() << endl;}
        catch (StatusExceptions& error) {cout << error.what() << endl;}
        catch (GlobalExceptions& error) {cout << error.what() << endl;}
        catch (...) {cout << "General Error." << endl;}
        System::printMenu();
        cout << "Please choose another action: " << flush;
        cin >> userDecision;
    }

    try {System::writeData();}
    catch (corruptFile& error) {cout << error.what() << endl;}
    catch (...) {cout << systemExceptions().what() << endl;}
   
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
            catch (EmptyName& error) {throw EmptyName(error);}
            catch (...) {throw systemExceptions();}
            break;
        //////////////////////////////////////////////////////////////////////////////////////////
        case (size_SI)CREATEFANPAGE: //2
            try {System::createFanPage();}
            catch (pageAlreadyExists& error) {throw pageAlreadyExists(error);}
            catch (EmptyName& error) {throw EmptyName(error);}
            catch(...) {throw systemExceptions();}
            break;
        //////////////////////////////////////////////////////////////////////////////////////////
        case (size_SI)NEWSTATUS: //3
            try {System::newStatus();}
            catch (invalidUserDecision& error) {throw invalidUserDecision(error);}
            catch (invalidStatusType& error) {throw invalidStatusType(error);}
            catch (EmptyFileName& error) {throw EmptyFileName(error);}
            catch (EmptyStatus& error) {throw EmptyStatus(error);}
            catch (StatusExceptions& error) {throw StatusExceptions(error);}
            catch (EmptyName& error) {throw EmptyName(error);}
            catch (entityNotFound& error) {throw entityNotFound(error);}
            catch (...) {throw systemExceptions();}
            break;
        ////////////////////////////////////////////////////////////////////////////////////////////
        case (size_SI)PRINTALLSTATUSES: //4
            try {System::printAllStatuses();}
            catch (invalidUserDecision& error) {throw invalidUserDecision(error);}
            catch (memberPrintStatusesException& error) {throw memberPrintStatusesException(error);}
            catch (fanPagePrintStatusesException& error) {throw fanPagePrintStatusesException(error);}
            catch (entityNotFound& error) {throw entityNotFound(error);}
            catch (EntityExceptions& error) {throw EntityExceptions(error);}
            catch (EmptyName& error) {throw EmptyName(error);}
            catch (...) {throw systemExceptions();}
            break;
        ////////////////////////////////////////////////////////////////////////////////////////////
        case (size_SI)PRINTTENLASTSTATUSES: //5
            try {System::printTenLastStatuses();}
            catch (memberPrintStatusesException& error) {throw memberPrintStatusesException(error);}
            catch (printFriendsException& error) {throw printFriendsException(error);}
            catch (memberNotFound& error) {throw memberNotFound(error);}
            catch (EmptyName& error) {throw EmptyName(error);}
            catch (memberExceptions& error) {throw memberExceptions(error);}
            catch (...) {throw systemExceptions();}
            break;
        //////////////////////////////////////////////////////////////////////////////////////////
        case (size_SI)CONNECTMEMBERS: //6
            try {System::Connect_OR_DisconnectMember(true);}
            catch (connectSameMember& error) {throw connectSameMember(error);}
            catch (addAFriendException& error) {throw addAFriendException(error);}
            catch (memberExceptions& error) {throw memberExceptions(error);}
            catch (memberNotFound& error) {throw memberNotFound(error);}
            catch (EmptyName& error) {throw EmptyName(error);}
            catch (...) {throw systemExceptions();}
            break;
        //////////////////////////////////////////////////////////////////////////////////////////
        case (size_SI)DISCONNECTMEMBERS: //7
            try {System::Connect_OR_DisconnectMember(false);}
            catch (removeSameMember& error) {throw removeSameMember(error);}
            catch (removeAFriendException& error) {throw removeAFriendException(error);}
            catch (memberExceptions& error) {throw memberExceptions(error);}
            catch (memberNotFound& error) {throw memberNotFound(error);}
            catch (EmptyName& error) {throw EmptyName(error);}
            catch (...) {throw systemExceptions();}
            break;
        //////////////////////////////////////////////////////////////////////////////////////////
        case (size_SI)ADDFAN: //8
            try {System::Add_OR_RemoveFAN(true);}
            catch (addAFanException& error) {throw addAFanException(error);}
            catch (entityNotFound& error) {throw entityNotFound(error);}
            catch (EmptyName& error) {throw EmptyName(error);}
            catch (...) {throw systemExceptions();}
            break;
        //////////////////////////////////////////////////////////////////////////////////////////
        case (size_SI)REMOVEFAN: //9
            try {System::Add_OR_RemoveFAN(false);}
            catch (removeAFanException& error) {throw removeAFanException(error);}
            catch (entityNotFound& error) {throw entityNotFound(error);}
            catch (EmptyName& error) {throw EmptyName(error);}
            catch (...) {throw systemExceptions();}
            break;
        //////////////////////////////////////////////////////////////////////////////////////////
        case (size_SI)PRINTALLENTITIES: //10
            try {System::printAllEntities();}
            catch (noMembersInSystem& error) {throw noMembersInSystem(error);}
            catch (noPagesInSystem& error) {throw noPagesInSystem(error);}
            catch (EmptySystemExceptions& error) {throw EmptySystemExceptions(error);}
            catch (...) {throw systemExceptions();}
            break;
        //////////////////////////////////////////////////////////////////////////////////////////
        case (size_SI)PRINTALLFRIENDS: //11
            try {System::printAllFriends();}
            catch (invalidUserDecision& error) {throw invalidUserDecision(error);}
            catch (printFriendsException& error) {throw printFriendsException(error);}
            catch (printFansException& error) {throw printFansException(error);}
            catch (memberExceptions& error) {throw memberExceptions(error);}
            catch (fanPageExceptions& error) {throw fanPageExceptions(error);}
            catch (entityNotFound& error) {throw entityNotFound(error);}
            catch (EmptyName& error) {throw EmptyName(error);}
            catch (...) {throw systemExceptions();}
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
            try {connectOrDisconnectMembers(dynamic_cast<Member*>(placeHolder.at(firstMemberName)),
                    dynamic_cast<Member*>(placeHolder.at(secondMemberName)), connect);}
            catch (addAFriendException& error) {throw addAFriendException(error);}
            catch (removeAFriendException& error) {throw removeAFriendException(error);}
            catch (...) {throw memberExceptions();}
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

    catch (addAFriendException& error) {throw addAFriendException(error);}
    catch (removeAFriendException& error) {throw removeAFriendException(error);}
    catch (...) {throw memberExceptions();}
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
        unordered_map<string, Entity*>& placeHolder = Entities[std::type_index(typeid(FanPage*))];
        if (placeHolder.find(name) == placeHolder.end())
            placeHolder[name] = new FanPage(name);

        else
            throw pageAlreadyExists();
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
            try {addOrRemoveFanUtility(dynamic_cast<Member*>(placeHolderMember.at(memberName)),
                    dynamic_cast<FanPage*>(placeHolderFanPage.at(fanPageName)), connect);}
            catch (addAFanException& error) {throw addAFanException(error);}
            catch (removeAFanException& error) {throw removeAFanException(error);}
            catch (GlobalExceptions& error) {throw GlobalExceptions(error);}
            catch (...) {throw systemExceptions();}
        }
        else
            throw entityNotFound();
    }
    else
        throw EmptyName();
}
//----------------------------------------------------------
void System::addOrRemoveFanUtility(Member* Member, FanPage* FanPage, bool connect) //Executes connection/removal.
{
    try {
        if (connect) {
            *Member += *FanPage;
            *FanPage += *Member;
        }

        else {
            *Member -= *FanPage;
            *FanPage -= *Member;
        }
    }

    catch (addAFanException& error) {throw addAFanException(error);}
    catch (removeAFanException& error) {throw removeAFanException(error);}
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
    catch (invalidUserDecision& error) {throw error;}
    catch (...) {throw systemExceptions();}

    getline(cin, name);
    const unordered_map<string, Entity*>& placeHolderMember = Entities[std::type_index(typeid(Member*))];
    const unordered_map<string, Entity*>& fanPagePlaceHolder = Entities[std::type_index(typeid(FanPage*))];

    if (!name.empty())
    {
        if (decision == MEMBER_CHOOSE && placeHolderMember.find(name) != placeHolderMember.end() )
        {
            try {dynamic_cast<Member*>(placeHolderMember.at(name))->Entity::addStatus();}
            catch (invalidStatusType& error) {throw invalidStatusType(error);}
            catch (EmptyFileName& error) {throw EmptyFileName(error);}
            catch (EmptyStatus& error) {throw EmptyStatus(error);}
            catch (...) {throw StatusExceptions();}
        }

        else if  (decision == FAN_PAGE_CHOOSE && fanPagePlaceHolder.find(name) != fanPagePlaceHolder.end())
        {
            try {dynamic_cast<FanPage*>(fanPagePlaceHolder.at(name))->Entity::addStatus();}
            catch (invalidStatusType& error) {throw invalidStatusType(error);}
            catch (EmptyFileName& error) {throw EmptyFileName(error);}
            catch (EmptyStatus& error) {throw EmptyStatus(error);}
            catch (...) {throw StatusExceptions();}
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
        && _birthday.year > 1900 && _birthday.year < 2024) ? true : false;
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
            try {dynamic_cast<Member*>(placeHolderMember.at(name))->Entity::printAllStatuses();}
            catch (entityHasNoStatuses& error) {throw memberPrintStatusesException();}
            catch (...) {throw EntityExceptions();}
        }

        else if (decision == FAN_PAGE_CHOOSE && fanPagePlaceHolder.find(name) != fanPagePlaceHolder.end())
        {
            try {dynamic_cast<FanPage*>(fanPagePlaceHolder.at(name))->Entity::printAllStatuses();}
            catch (entityHasNoStatuses& error) {throw fanPagePrintStatusesException();}
            catch (...) {throw EntityExceptions();}
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
                    if (key != name)
                    {
                        cout << "####################################\nFriend #" << ++i
                            << ": " << key << "\n####################################" << endl;

                        try {value->Member::printTenLastStatuses();}
                        catch (memberPrintStatusesException& error) {cout << key << ": " << error.what() << endl; }
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
            throw noMembersInSystem();

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
            throw noPagesInSystem();
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

        if (decision == MEMBER_CHOOSE && placeHolderMember.find(entityName) != placeHolderMember.end())
        {
            auto* MemberPTR = dynamic_cast<Member*>(placeHolderMember.at(entityName));
            try {MemberPTR->Entity::printMembers();}
            catch (entityHasNoConnections& error) {throw printFriendsException();}
            catch (...) {throw memberExceptions();}
        }

        else if (decision == FAN_PAGE_CHOOSE && placeHolderFanPage.find(entityName) != placeHolderFanPage.end())
        {
            auto* FanPagePTR = dynamic_cast<FanPage*>(placeHolderFanPage.at(entityName));
            try {FanPagePTR->Entity::printMembers();}
            catch (entityHasNoConnections& error) {throw printFansException();}
            catch (...) {throw fanPageExceptions();}
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
    //Step 1: Initialization of Entities.
    Entities[std::type_index(typeid(FanPage*))] = {};
    Entities[std::type_index(typeid(Member*))] = {};

    std::ifstream dataBinFile("SystemData.bin", std::ios_base::binary | std::ios_base::in);
    if (dataBinFile.peek() != std::ifstream::traits_type::eof())
    {
        if (dataBinFile.good()) {

            //Step 2: Read all members and their statuses.
            size_t membersSize, fanPagesSize;
            dataBinFile.read(reinterpret_cast<char*>(&membersSize), sizeof(membersSize));
            for (size_t i = 0; i < membersSize; ++i)
            {
                auto* member = new Member();
                member->loadFromFile(dataBinFile);
                Entities[std::type_index(typeid(Member*))][member->getName()] = member;
            }

            //Step 3: Read all pages and their statuses.
            dataBinFile.read(reinterpret_cast<char*>(&fanPagesSize), sizeof(fanPagesSize));
            for (size_t i = 0; i < fanPagesSize; ++i)
            {
                auto* fanpage = new FanPage();
                fanpage->loadFromFile(dataBinFile);
                Entities[std::type_index(typeid(FanPage*))][fanpage->getName()] = fanpage;
            }

            //Step 4: Connect Members to Members and Members to Fan Pages.
            for (int i = 0; i < membersSize; ++i) 
            {
                string nameToAdd;
                std::getline(dataBinFile, nameToAdd, '\0');
                auto* member = dynamic_cast<Member*>(Entities[std::type_index(typeid(Member*))][nameToAdd]);
                member->loadMembersFromFile(dataBinFile, Entities);
             
            }

            //Step 5: Connect Fan Pages to Members
            for (int i = 0; i < fanPagesSize; ++i)
            {
                string currFanPageName;
                std::getline(dataBinFile, currFanPageName, '\0');
                FanPage* currFanPage = dynamic_cast<FanPage*>(Entities[std::type_index(typeid(FanPage*))][currFanPageName]);
                currFanPage->loadMembersFromFile(dataBinFile, Entities);
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
    std::ofstream dataBinFile("SystemData.bin", std::ios_base::binary | std::ios_base::out);

    if (dataBinFile.good()) {
         const auto& placeHolderMember = Entities[std::type_index(typeid(Member*))];
         const auto& placeHolderFanPage = Entities[std::type_index(typeid(FanPage*))];

         //Step 1: Writing num of members in system.
         size_t s = placeHolderMember.size();
         dataBinFile.write(reinterpret_cast<const char*>(&s), sizeof(s));
         //Step 2: Writing each member's name, date of birth and statuses.
         for (const auto& kv : placeHolderMember)
         {
             dynamic_cast<Member*>(kv.second)->savetoFile(dataBinFile);
         }

         //Step 3: Writing num of pages in system.
         size_t fanPageSize = placeHolderFanPage.size();
         dataBinFile.write(reinterpret_cast<const char*>(&fanPageSize), sizeof(fanPageSize));

         //Step 4: Writing each fan page's name and statuses.
         for (const auto& kv : placeHolderFanPage)
         {
             dynamic_cast<FanPage*>(kv.second)->saveToFile(dataBinFile);
         }

         //Step 5: Writing each member's friends and pages.
         for (const auto& kv : placeHolderMember)
         {
             dynamic_cast<Member*>(kv.second)->saveMembersToFile(dataBinFile);
         }

         //Step 6: Writing each fan page's fans.
         for (const auto& kv : placeHolderFanPage)
         {
             dynamic_cast<FanPage*>(kv.second)->saveMembersToFile(dataBinFile);
         }
    }

    else
        throw corruptFile();

    dataBinFile.close();
}
//----------------------------------------------------------