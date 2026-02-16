#include <iostream>

int main() {
    const int& x = 1;
    // ++x;
    int y = x +1;
    std::cout << y << std::endl;
    return 0;
}
