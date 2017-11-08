#include <iostream>
#include "banana.h"
#include "interest.h"
using namespace std;

int main()
{

    double principle, interest;
    int months;

    cout << "How much money do you have?" << endl;
    cin >> principle;
    cout << "What is your monthly interest rate?" << endl;
    cin >> interest;
    cout << "How many months?" << endl;
    cin >> months;

    double balance = simpleInterest(principle, interest / 100, months);
    cout << " You now have $" << balance << endl;
    peel();
    return 0;
}