#include "../Headers/FanPage.h"
#include "../Headers/Member.h"
//Constructor
//-----------------------------------------------------------
FanPage::FanPage(string& _name):Entity(_name){}
//-----------------------------------------------------------

void FanPage::saveMembersToFile(ofstream& out)
{
    size_t numOfMembers = FanPage::getNumOfMembers();
    out.write(name.c_str(), name.size() + 1);
    out.write(reinterpret_cast<const char*>(&numOfMembers),
        sizeof(numOfMembers));
    const unordered_map<string, Member*> pagesFans = FanPage::getMembers();

    for (const auto& pf : pagesFans)
        out.write(pf.first.c_str(), pf.first.size() + 1);
}

void FanPage::loadMembersFromFile(ifstream& in, SystemMap& Entities)
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

void FanPage::saveToFile(ofstream& out)
{ 
    out.write(name.c_str(), name.size() + 1);
    size_t size = bulletinBoard.size();
    out.write(reinterpret_cast<const char*>(&size), sizeof(size));
    for (Status* sv : bulletinBoard)
    {
        size_t statusType = static_cast<int>(sv->getStatusType());
        out.write(reinterpret_cast<const char*>(&statusType), sizeof(statusType));
        if (statusType == static_cast<int>(STATUS_TYPE::IMAGE))
        {
            out.write(reinterpret_cast<const char*>(dynamic_cast<ImageStatus*>(sv)), sizeof(*(dynamic_cast<ImageStatus*>(sv))));
        }
        else if (statusType == static_cast<int>(STATUS_TYPE::VIDEO))
        {
            out.write(reinterpret_cast<const char*>(dynamic_cast<VideoStatus*>(sv)), sizeof(*(dynamic_cast<VideoStatus*>(sv))));
        }
        else
        {
            out.write(reinterpret_cast<const char*>(sv), sizeof(*sv));
        }
    }
}
void FanPage::loadFromFile(ifstream& in)
{
    getline(in, name, '\0');
    size_t size;
    in.read(reinterpret_cast<char*>(&size), sizeof(size));
    for (size_t i = 0; i < size; ++i) {
        size_t statusType = 0;
        in.read(reinterpret_cast<char*>(&statusType), sizeof(statusType));
        STATUS_TYPE type = static_cast<STATUS_TYPE>(statusType);
        if (type == STATUS_TYPE::IMAGE) {
            ImageStatus* sv = new ImageStatus();
            in.read(reinterpret_cast<char*>(sv), sizeof(*sv));
            bulletinBoard.emplace_back(sv);
        }
        else if (type == STATUS_TYPE::VIDEO) {
            VideoStatus* sv = new VideoStatus();
            in.read(reinterpret_cast<char*>(sv), sizeof(*sv));
            bulletinBoard.emplace_back(sv);
        }
        else {
            Status* sv = new Status();
            in.read(reinterpret_cast<char*>(sv), sizeof(*sv));
            bulletinBoard.emplace_back(sv);
        }
    }

}
//Operators
//-----------------------------------------------------------
const FanPage& FanPage::operator+=(Member& _member) //FanPage += Member method.
{
    try {this->Entity::addMember(_member);}
    catch (connectedEntities& error) {throw addAFanException();}
    catch (...) {throw GlobalExceptions();}
    return *this;
}
//-----------------------------------------------------------
const FanPage &FanPage::operator-=(Member& _member) //FanPage -= Member method.
{
    try {this->Entity::removeMember(_member);}
    catch (disconnectedEntities& error) {throw removeAFanException();}
    catch (...) {throw GlobalExceptions();}
    return *this;
}
//-----------------------------------------------------------