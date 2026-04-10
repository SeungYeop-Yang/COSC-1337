#include <iostream>

using namespace std;

void displayArray(float[], int);
void displaypArray(float*, int);
int main()
{
    float* numbers = nullptr;

    numbers = new float[5];
    float value = 1.1;
    int count = 0;

    float* oldArray = nullptr;

    // numbers[0] = 1.3;
    // numbers[1] = 2.8;

    for (int i = 0; i < 5; i++) {
        numbers[i] = value * i;
        count++;
    }

    if (count < 5) {
        numbers[count] = 99.12;
        count++;
    }
    else {
        // make the arry larger
        oldArray = numbers;
        numbers = new float[count * 2];

        for (int i = 0; i < count; i++) {
            numbers[i] = oldArray[i];
        }

        delete oldArray;
        oldArray = nullptr;

        // add a new value
        numbers[count] = 55.55;
    }

    cout << "displayArray" << endl;
    displayArray(numbers, 10);
    cout << "displaypArray" << endl;
    displaypArray(numbers, 10);

    return 0;
}

void displayArray(float values[], int count)
{
    for (int i = 0; i < count; i++) {
        cout << "at address " << values + i << endl;
        cout << values[i] << endl;
    }
}

void displaypArray(float* pArray, int count)
{
    for (int i = 0; i < count; i++) {
        cout << "at address " << pArray << endl;
        cout << *pArray++ << endl;
    }
}
