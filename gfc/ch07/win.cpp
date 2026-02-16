class Window
{
    //...
public:
    Window(int top, int left, int bottom, int right);
    ~Window();
    void Move(int x, int y);
};

class ScrollBar
{
    //...
public:
    ScrollBar(int top, int left, into bottom, int right);
    ~ScrollBar();
    void Move(int x, int y);
};

class ScrollableWind : Window, ScrollBar
{
    //...
public:
    ScrollableWind(int top, int left, int bottom, int right);
    ~ScrollableWind();
    void Move(int x, int y)
    {
        Window::Move(x, y);
        ScrollBar::Move(x, y);
    }
};

ScrollableWind::ScrollableWind(int top, int left, int bottom, int right) : Window(top, left, bottom, right),
                                                                           ScrollBar(top, right - 20, bottom, right)
{
    //...
}
