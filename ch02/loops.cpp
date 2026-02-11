#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int num;

    num = 5;
    cout << num++ << endl;
    cout << "no num is " << num << endl;

    while (num != -1)
    {
        cout << "The square root of " << num << " is " << sqrt(num--) << endl;
    }

    return 0;
}
