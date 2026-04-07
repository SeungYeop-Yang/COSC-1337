#include <iostream>

using namespace std;

void displayArray(int values[], int count);
void displaypArray(int* pArray, int count);

int main()
{
    int numbers[5] = {43, 92, 33, 81, 74};

    cout << "displayArray" << endl;
    displayArray(numbers, 5);
    cout << "displaypArray" << endl;
    displaypArray(numbers, 5);

    return 0;
}

void displayArray(int values[], int count)
{
    for (int i = 0; i < count; i++) {
        cout << "at address " << values + i << endl;
        cout << values[i] << endl;
    }
}

void displaypArray(int* pArray, int count)
{
    for (int i = 0; i < count; i++) {
        cout << "at address " << pArray << endl;
        cout << *pArray++ << endl;
    }
}
