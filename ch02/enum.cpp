#include <iostream>
using namespace std;

enum Days
{
    Sunday,
    Monday,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday
};

int main()
{

    Days day;
    int intDay;

    cout << "Enter a day of the week (0=Sunday, 6=Saturday): ";
    cin >> intDay;
    day = static_cast<Days>(intDay);
    cout << "day is " << day << endl;

    switch (intDay)
    {
    case Sunday:
        cout << "Sunday\n";
        break;
    case Monday:
        cout << "Monday\n";
        break;
    case Tuesday:
        cout << "Tuesday\n";
        break;
    case Wednesday:
        cout << "Wednesday\n";
        break;
    case Thursday:
        cout << "Thursday\n";
        break;
    case Friday:
        cout << "Friday\n";
        break;
    case Saturday:
        cout << "Saturday\n";
        break;
    default:
        break;
    }

    return 0;
}
