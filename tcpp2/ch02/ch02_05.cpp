#include <iostream>
using namespace std;

enum class Color
{
    red = 1,
    blue,
    green
};

enum class Traffic_light
{
    green,
    yellow,
    red
};

int main()
{

    Color col = Color::red;
    Traffic_light light = Traffic_light::green;

    cout << static_cast<int>(col) << endl;
    cout << static_cast<int>(light) << endl;

    Color x = Color{5};
    Color y = Color(5);

    cout << static_cast<bool>(x == y ? true : false) << endl;
    return 0;
}
