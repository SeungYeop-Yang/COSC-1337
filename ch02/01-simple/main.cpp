// This program displays a message

#include <iostream>

using namespace std;

int main() {
    auto age = 98;
    float num;
    char letter;
    string userName;
    float quotient;
    int a, b;

    a = 5;
    b = 2;
    quotient = a / b;

    cout << quotient << endl;

    age = 98;
    num = 4.0;
    letter = 'm';
    userName = "Clovis Bagwell";

    cout << "int is " << sizeof(int) << " bytes\n";
    cout << "Hi, my favorite color" << " is purple" << endl;
    cout << "and I am " << age << "years old.\n";
    cout << "User Name is " << userName << endl;

    return 0;
}
