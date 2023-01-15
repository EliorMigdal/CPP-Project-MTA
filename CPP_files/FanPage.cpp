#include "../Headers/FanPage.h"

//Constructor
//-----------------------------------------------------------
FanPage::FanPage(string& _name):Entity(_name){}
//-----------------------------------------------------------

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