#ifndef CPP_PROJECT_MENU_H
#define CPP_PROJECT_MENU_H
#include "Member.h"
#include "FanPage.h"
#include "Status.h"

class Menu : public Member, public FanPage, public Status {
private:
    int userDecision = 0;

public:
    Menu(){}
    void setDecision(int _decision)
    {
        if (_decision < 1 || _decision > 12)
        {
            cout << "Invalid choice. Please try again!" << endl;
            printMenu();
            cin >> _decision;
        }

        switch(_decision)
        {
            default:
                break;
            case 1:
                createMember();
                break;
            case 2:
                createFanPage();
                break;
            case 3:
                addStatus();
                break;
            case 4:
                showAllStatuses();
                break;
            case 5:
                connectMembers();
                break;

        }
    }

    int getDecision() const {return userDecision;}

    static void printMenu()
    {
        cout << "1 - Create a member"
                "\t2 - Create a fan page"
                "\t3 - Create a status"
                "\t4 - Show all statuses"
                "\t5 - View 10 last statuses of a friend"
                "\t6 - Connect 2 members"
                "\n7 - Disconnect 2 members"
                "\t8 - Add a member to a fan page"
                "\t9 - Remove a member from a fan page"
                "\t10 - View all members and fan pages"
                "\t11 - View all member's friends or Fan page's fans"
                "\t12 - Exit" << endl;
    }

    void createMember()
    {
        //Inherit
    }

    void createFanPage()
    {
        //Inherit
    }

    static void addStatus()
    {
        int decision = 0;
        char* name;
        cout << "Please choose where to add the status:"
                "\n1 - A Member"
                "\n2 - A Fan Page" << endl;
        cin >> decision;
        while (decision != 1 && decision != 2)
        {
            cout << "Invalid decision. Please choose 1 or 2: " << endl;
            cin >> decision;
        }
        if (decision == 1)
        {
            cout << "Please enter a member's name:" << endl;
            cin >> name;
            // bool found = findMember(name)
            // if not found, alert - otherwise, inherit Member::addStatus
        }
        else
        {
            cout << "Please enter a Fan Page's name:" << endl;
            cin >> name;
            // bool found = findPage(name)
            // if not found, alert - otherwise, inherit FanPage::addStatus
        }
    }

    static void showAllStatuses()
    {
        int decision = 0;
        char* name;
        cout << "Please choose the entity of which you want to view the statuses:"
                "\n1 - A Member"
                "\n2 - A Fan Page" << endl;
        cin >> decision;

        while (decision != 1 && decision != 2)
        {
            cout << "Invalid decision. Please choose 1 or 2: " << endl;
            cin >> decision;
        }

        if (decision == 1)
        {
            cout << "Please enter a member's name:" << endl;
            cin >> name;
            // bool found = findMember(name)
            // if not found, alert - otherwise, inherit Member::showStatuses
        }

        else
        {
            cout << "Please enter a Fan Page's name:" << endl;
            cin >> name;
            // bool found = findPage(name)
            // if not found, alert - otherwise, inherit FanPage::showStatuses
        }
    }

    void tenLastStatuses()
    {
        char* name;
        cout << "Please enter a member's name:" << endl;
        cin >> name;
        //find member
        //inherit Member::show10last
    }

    void connectMembers()
    {
        char* name1,  *name2;
        int found1, found2;
        cout << "Please enter 1st member's name:" <<endl;
        cin >> name1;
        //find
        cout << "Please enter 2nd member's name:" << endl;
        cin >> name2;
        //find

        if (found1 != -1 && found2 != -1)
        {
            //use system data & member classes
        }
        else
        {
            //didn't find
        }
    }
};


#endif //CPP_PROJECT_MENU_H
