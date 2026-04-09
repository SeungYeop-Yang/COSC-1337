#include <iostream>

using namespace std;

int main()
{
    int* intPtr = nullptr;

    intPtr = new int;
    *intPtr = 4;

    cout << intPtr << endl;
    cout << *intPtr << endl;

    return 0;
}
