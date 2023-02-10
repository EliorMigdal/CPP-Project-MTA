#include "../Headers/System.h"
//Tests
#include "../Headers/FanPage.h"
#include "../Headers/Member.h"
//End of Tests

int main()
{
    System Facebook;
    Facebook.Start();
    //Tests
    FanPage page1, page2;
    Member m1, m2;
    page1 > page2 ? cout << "Da" << endl : cout << "Bla" << endl;
    page1 += m1;
    page1 > page2 ? cout << "Da" << endl : cout << "Bla" << endl;
    //End of Tests
    return 0;
}