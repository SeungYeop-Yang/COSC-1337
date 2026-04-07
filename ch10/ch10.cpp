#include <iostream>

using namespace std;

void timesTen(int* value) { *value *= 10; }

int main()
{
    int x;
    float y;
    int* intPtr = nullptr;

    x = 6;
    intPtr = &x;

    cout << "x is " << x << endl;
    cout << "the address of x is " << &x << endl;
    cout << "intPtr is " << intPtr << endl;
    cout << "the content referenced by intPtr is " << *intPtr << endl;
    timesTen(intPtr);
    cout << "the content referenced by intPtr is " << *intPtr << endl;

    return 0;
}
