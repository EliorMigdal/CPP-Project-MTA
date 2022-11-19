#include "../Headers/GlobalVariables.h"
#include "../Headers/System.h"

int main() {
    System Facebook;
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
