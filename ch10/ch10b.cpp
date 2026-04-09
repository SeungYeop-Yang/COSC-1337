#include <iostream>

using namespace std;

void doAddition();

int main()
{
    int a;

    doAddition();

    return 0;
}

void doAddition()
{
    int x, y;

    cout << "Enter an integer: ";
    cin >> x;

    cout << "Enter another integer: ";
    cin >> y;

    cout << "The sum of " << x << " and " << y << " is " << x + y << endl;
}
