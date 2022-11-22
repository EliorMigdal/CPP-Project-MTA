#include "../Headers/Member.h"
//----------------------------------------------------------
void Member::addFriend(Member& member)
{
    friends[numOfFriends++] = member;
}
//----------------------------------------------------------
void Member::printStatus(int index)
{
    cout << this->bulletinBoard[index].getStatus() << endl;
    this->bulletinBoard[index].printDate(this->getDate(), this->getTime());
}
//----------------------------------------------------------
void Member::printTenLastStatuses(Member& member)  //Prints member's 10 last statuses
{
    int numOfStatuses = member.getNumOfStatuses();
    if (numOfStatuses == 0)
        cout << member.getName() << " has not posted any statuses." << endl;
    else if (numOfStatuses < 10)
        cout << member.getName() << " has only posted " << numOfStatuses << " statuses:" << endl;
    else
        cout << member.getName() << "'s last ten statuses:" << endl;

    for (int i = numOfStatuses - 1; i >= 0; i--)
    {
        cout << "Status #" << i + 1 << ":" << endl;
        Member::printStatus(i);
    }
}
//----------------------------------------------------------
void Member::printAllStatuses()
{

}
//----------------------------------------------------------



//----------------------------------------------------------



//----------------------------------------------------------