#include "../Headers/GlobalVariables.h"
#include "../Headers/System.h"

int main()
{ // didnt check yet the main after all the edits.
    
 


    System Facebook;
    Date d1 = {24, 4, 1995};
    Date d2 = {23, 5, 1990};
    size_SI userDecision;
    cout << "Welcome to our social network!" << endl;
    Facebook.printMenu();
    Facebook.createMember("Elior Migdal", d1);
    Facebook.createMember("Ben Cohen", d2);
    cout << "Please choose your action: " << flush;
    cin >> userDecision;
    // stop at checking inputoperation function + all the menu functionallity!
    while (userDecision != EXIT)
    {
        Facebook.setDecision(userDecision);
        cout << "Please choose another action: " << flush;
        cin >> userDecision;
       
        if (userDecision == EXIT)
        {
            //frees
        }
    }
    return 0;
}