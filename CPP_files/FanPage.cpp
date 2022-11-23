#include "../Headers/FanPage.h"
//----------------------------------------------------------
void FanPage::printStatuses() const //Prints all fan page's statuses.
{
    string name = this->getName();
    size_SI numOfStatuses = this->getNumOfStatuses();
    cout << name << "'s statuses:" << endl;

    for (size_SI i = 0; i < numOfStatuses; i++)
    {
        cout << "Status #" << i+1 << ":" << endl;
        cout << this->bulletinBoard[i].getStatus() << endl;
        this->bulletinBoard[i].printDate(this->bulletinBoard[i].getStatusDate(),
                this->bulletinBoard[i].getStatusTime());
    }
}