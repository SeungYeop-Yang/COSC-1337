class Point {
    int x, y;
public:
    Point(int x, int y) {Point::x = x; Point::y = y;}
    Point operator + (Point p) { return Point(x + p.x, y + p.y);}
    Point operator - (Point p) { return Point(x - p.x, y - p.y);}
}
