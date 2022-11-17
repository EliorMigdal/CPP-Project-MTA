#include "../Headers/GlobalVariables.h"
#include "../Headers/Menu.h"

int main() {
    Menu mainMenu;
    int userDecision;
    cout << "Welcome to our social network!" << endl;
    mainMenu.printMenu();
    cout << "Please choose your action:" << endl;
    cin >> userDecision;

    while (userDecision != EXIT)
    {
        mainMenu.setDecision(userDecision);
        cout << "Please choose another action:" << endl;
        cin >> userDecision;

        if (userDecision == EXIT)
        {
            //frees
        }
    }
    return 0;
}
