#include "../Headers/GlobalVariables.h"
#include "../Headers/System.h"

int main()
{
    System Facebook;

    /////////////////////////Hard-coded data
    Facebook.Start();
    /////////////////////////End of hard-coded data

    size_SI userDecision;
    cout << "Welcome to our social network!" << endl;
    Facebook.printMenu();
    cout << "Please choose your action: " << flush;
    cin >> userDecision;
    // stop at checking inputoperation function + all the menu functionallity!

    while (userDecision != EXIT)
    {
        Facebook.setDecision(userDecision);
        Facebook.printMenu();
        cout << "Please choose another action: " << flush;
        cin >> userDecision;
    }

    return 0;
}