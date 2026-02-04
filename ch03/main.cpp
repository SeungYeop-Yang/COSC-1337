#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    // 01
    // int age;
    // string name;

    // cout << "Enter your age: ";
    // cin >> age;

    // cin.ignore(100, '\n');
    // cout << "Enter your name: ";
    // getline(cin, name);

    // cout << "Hello " << name << ", you are " << age << " years old.\n";

    // 02
    // int a, b;
    // float c;

    // a = 5;
    // b = 2;
    // // c = static_cast<float>(a) / b;
    // c = (float)a / b;

    // cout << "c is " << c << endl;

    // 03

    const double SALES_TAX_RATE = 0.0825;
    double x, y, salesTax, total = 593.0;

    // x = y * SALES_TAX_RATE;
    salesTax = total * SALES_TAX_RATE;
    cout << setw(8) << fixed << setprecision(2) << salesTax << endl;
    cout << left << setw(8) << fixed << setprecision(2) << salesTax << endl;

    return 0;
}
