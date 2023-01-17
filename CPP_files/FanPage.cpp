#include "../Headers/FanPage.h"
#include "../Headers/Member.h"

//Constructor
//-----------------------------------------------------------
FanPage::FanPage(string& _name):Entity(_name){}
//-----------------------------------------------------------

//FanPage-to-File Methods
//-----------------------------------------------------------
void FanPage::saveMembersToFile(ofstream& out) //Saves FanPage's connections to a file.
{
    size_t numOfMembers = FanPage::getNumOfMembers();
    out.write(name.c_str(), name.size() + 1);
    out.write(reinterpret_cast<const char*>(&numOfMembers),
        sizeof(numOfMembers));
    const unordered_map<string, Member*> pagesFans = FanPage::getMembers();

    for (const auto& pf : pagesFans)
        out.write(pf.first.c_str(), pf.first.size() + 1);
}
//-----------------------------------------------------------
void FanPage::loadMembersFromFile(ifstream& in, SystemMap& Entities) //Reads FanPage's connections from a file.
{
    size_t numOfMembers;
    in.read(reinterpret_cast<char*>(&numOfMembers), sizeof(numOfMembers));
    
    for (size_t j = 0; j < numOfMembers; ++j)
    {
        string memberToAdd;
        std::getline(in, memberToAdd, '\0');
        this->addMember(*(dynamic_cast<Member*>(Entities[std::type_index(typeid(Member*))][memberToAdd])));
    }
}
//-----------------------------------------------------------

//Operators
//-----------------------------------------------------------
FanPage& FanPage::operator+=(Member& _member) //FanPage += Member method.
{
    try {this->Entity::addMember(_member);}
    catch (connectedEntities& error) { throw reinterpret_cast<addAFanException*>(&error); }
    catch (...) {throw GlobalExceptions();}
    return *this;
}
//-----------------------------------------------------------
FanPage &FanPage::operator-=(Member& _member) //FanPage -= Member method.
{
    try {this->Entity::removeMember(_member);}
    catch (disconnectedEntities& error) {throw reinterpret_cast<removeAFanException*>(&error);}
    catch (...) {throw GlobalExceptions();}
    return *this;
}
//-----------------------------------------------------------