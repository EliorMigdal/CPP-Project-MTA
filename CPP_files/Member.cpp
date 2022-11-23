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
    this->bulletinBoard[index].printDate(this->bulletinBoard[index].getStatusDate(), this->bulletinBoard[index].getStatusTime());
}
//----------------------------------------------------------
void Member::printStatuses(int numToPrint) //Prints member's statuses.
{
    int numOfStatuses = this->getNumOfStatuses();
    int logicPrintSize;
    if (numOfStatuses == 0)
        cout << this->getName() << " has not posted any statuses." << endl;

    if (numToPrint == PRINT_STATUS)
    {
        if (numOfStatuses < PRINT_STATUS)
        {
            logicPrintSize = numOfStatuses;
            cout << this->getName() << " has only posted " << numOfStatuses << " statuses:" << endl;
        }

        else
        {
            logicPrintSize = PRINT_STATUS;
            cout << this->getName() << "'s last " << PRINT_STATUS << " statuses:" << endl;
        }

        for (int i = numOfStatuses - 1; i >= numOfStatuses - logicPrintSize; i--)
        {
            cout << "Status #" << i + 1 << ":" << endl;
            this->printStatus(i);
        }
    }
}
//----------------------------------------------------------
int Member::findFriend(std::string friendName) //Searches for a friend in a member's array of friends.
{
    int found = -1;
    for (int i = 0; i < numOfFriends && found == -1; i++)
    {
        if (friends[i].getName() == friendName)
            found = i;
    }

    return found;
}
//----------------------------------------------------------



//----------------------------------------------------------