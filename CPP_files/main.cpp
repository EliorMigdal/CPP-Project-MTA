#include "../Headers/GlobalVariables.h"
#include "../Headers/System.h"

int main()
{
    System Facebook;

    /////////////////////////Hard-coded data
    Date eliDay = {24, 4, 1995};
    Date bencoDay = {23, 5, 1990};
    Date benhanDay = {5, 9, 1983};
    Date ramezDay = {14, 12, 2005};
    Facebook.createMember("Elior Migdal", eliDay);
    Facebook.createMember("Ben Cohen", bencoDay);
    Facebook.createMember("Ben Hanover", benhanDay);
    Facebook.createMember("Ramez Mannaa", ramezDay);
    Facebook.createFanPage("The Bens");
    Facebook.createFanPage("We love Tel-Aviv");
    Facebook.createFanPage("They were on a break!");
    Facebook.connectMembers("Elior Migdal", "Ben Cohen");
    Facebook.connectMembers("Elior Migdal", "Ben Hanover");
    Facebook.connectMembers("Ben Cohen", "Ramez Mannaa");
    Facebook.connectMembers("Ben Cohen", "Ben Hanover");
    Facebook.connectMembers("Ramez Mannaa", "Elior Migdal");
    Facebook.connectMembers("Ramez Mannaa", "Ben Hanover");
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