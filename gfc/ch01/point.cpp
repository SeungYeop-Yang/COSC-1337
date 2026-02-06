class Point
{
    int xVal, yVal;

public:
    void SetPt(int, int);
    void OffsetPt(int, int);
};

inline void Point::SetPt(int x, int y)
{
    xVal = x;
    yVal = y;
}

void Point::OffsetPt(int x, int y)
{
    xVal += x;
    yVal += y;
}

int main()
{
    Point pt;

    pt.SetPt(10, 20);
    pt.OffsetPt(2, 2);

    return 0;
}
