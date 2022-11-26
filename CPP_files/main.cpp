#include "../Headers/GlobalVariables.h"
#include "../Headers/System.h"

int main()
{ // didnt check yet the main after all the edits..
    System Facebook;
    Date d1 = {24, 4, 1995};
    Date d2 = {23, 5, 1990};
   /* Facebook.createMember("ben", d1);*/
    int userDecision;
    cout << "Welcome to our social network!" << endl;
    Facebook.printMenu();
    cout << "Please choose your action:" << endl;
    cin >> userDecision;

    while (userDecision != EXIT)
    {
        Facebook.setDecision(userDecision);
        cout << "Please choose another action:" << endl;
        cin >> userDecision;

        if (userDecision == EXIT)
        {
            //frees
        }
    }
    return 0;
}