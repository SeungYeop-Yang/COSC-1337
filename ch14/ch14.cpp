#include <iostream>
using namespace std;

void message(int);

int main()
{
    int times;

    cout << "How many times? ";
    cin >> times;

    message(times);
    return 0;
}

void message(int t)
{
    if (t > 0) {
        cout << "Hello, how was your day?\n";
        message(t - 1);
    }

    // for (int i=0; i<t; i++)
    //     cout << "Hello, how was your day?\n"
}
