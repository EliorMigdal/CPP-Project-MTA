#include "../Headers/Member.h"
//----------------------------------------------------------
inline void Member::addFriend(Member& member)
{
    friends[numOfFriends++] = member;
}
//----------------------------------------------------------
inline void Member::printStatus(int index) const
{
    cout << this->bulletinBoard[index].getStatus() << endl;
    this->bulletinBoard[index].printDate(this->getDate(), this->getTime());
}
//----------------------------------------------------------
inline void Member::printTenLastStatuses(Member& member) const
{
    cout << member.getName() << "'s last ten statuses:" << endl;
    for (int i = 0; i < member.getNumOfStatuses(); i++)
    {
        cout << "Status #" << i + 1 << ":" << endl;
        Member::printStatus(i);
    }
}

//----------------------------------------------------------



//----------------------------------------------------------



//----------------------------------------------------------



//----------------------------------------------------------