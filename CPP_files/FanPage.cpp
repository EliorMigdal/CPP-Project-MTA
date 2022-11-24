#include "../Headers/FanPage.h"
//----------------------------------------------------------
void FanPage::printStatuses() const //Prints all fan page's statuses.
{
    size_SI _numOfStatuses = this->getNumOfStatuses();

    for (size_SI i = 0; i < _numOfStatuses; i++)
    {
        cout << "Status #" << i + 1 << ":" << endl;
        cout << this->bulletinBoard[i].getStatus() << endl;
        this->bulletinBoard[i].printDate(this->bulletinBoard[i].getStatusDate(),
                this->bulletinBoard[i].getStatusTime());
    }
}
//----------------------------------------------------------