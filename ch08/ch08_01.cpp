#include <iostream>
using namespace std;

const int SIZE = 5;

void displayNumbers(int values[])
{
    for (int i = 0; i < SIZE; i++)
        cout << values[i] << endl;
}

void displayReference(int (&values)[])
{
    for (int i = 0; i < SIZE; i++)
        cout << values[i] << endl;
}

int main()
{
    int num;
    int numbers[SIZE];

    for (int i = 0; i < SIZE; i++) {
        cout << "Enter an integer: ";
        cin >> num;

        numbers[i] = num;
    }

    displayNumbers(numbers);
    displayReference(numbers);

    return 0;
}
