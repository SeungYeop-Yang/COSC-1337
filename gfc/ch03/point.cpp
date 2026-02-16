#include <math.h>

class Point
{
    int xVal, yVal;

public:
    Point(int x, int y) {xVal = x; yVal = y;} // constructor
    Point(float, float); // polar coordinates constructor
    Point() {xVal = 0; yVal = 0;} // default constructor

    void SetPt(int, int);
    void OffsetPt(int, int);
};


// A constructor requires no return type; the return type is implicit and
// is a pointer to the class itself.
Point::Point(float r, float theta)
{
    xVal = int(r * cos(theta));
    yVal = int(r * sin(theta));
}

inline void Point::SetPt(int x, int y)
{
    xVal = x;
    yVal = y;
}

void Point::OffsetPt(int x, int y)
{
    this->xVal += x;
    this->yVal += y;
}


int main()
{
    Point pt1 = Point(10, 20);
    Point pt2(10, 20);
    Point pt3(1.0f, 2.0f);
    Point pt4;

    pt1.OffsetPt(2, 2);
    pt2.OffsetPt(2, 2);
    pt3.OffsetPt(2, 2);
    pt4.OffsetPt(2, 2);

    return 0;
}
