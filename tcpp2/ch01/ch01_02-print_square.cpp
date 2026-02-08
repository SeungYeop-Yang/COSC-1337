#include <iostream>
using namespace std;

double square(double x)
{
    return x * x;
}

void print_square(double x)
{
    cout << "the square of " << x << " is " << square(x) << "\n";
}

int main()
{
    print_square(1.234);
    return 0;
}

// sajang@macpro:~/Learning/COSC-1337/tcpp2/ch01$ ./a.out
// the square of 1.234 is 1.52276
// sajang@macpro:~/Learning/COSC-1337/tcpp2/ch01$
