#include <iostream>
using namespace std;

int fact1(int);
int fact2(int);

int main()
{
    int num;

    cout << "Enter an integer: ";
    cin >> num;

    cout << num << "! (iterative) is " << fact1(num) << endl;
    cout << num << "! (recursive) is " << fact2(num) << endl;

    return 0;
}

int fact1(int value)
{
    int factorial = 1;

    for (int i = value; i > 0; i--)
        factorial *= i;

    return factorial;
}

int fact2(int value)
{
    if (value == 0)
        return 1;
    else
        return value * fact2(value - 1);
}
