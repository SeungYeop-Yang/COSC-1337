# Ch07 Multiple Inheritance

A derived class can have multiple base classes; this leads to multiple
inheritance.

If the base classes of a derived class have constructors that take arguments,
the constructor for the derived class should call these explicitly.
```
ScrollableWind::ScrollableWind(int top, int left, int bottom, int right) :
    Window(top, left, bottom, right),
    ScrollBar(top, right - 20, bottom, right)
{
    //...
}
```

## Member objects

A class object can be a data member of another class.

```
class LinEqns : public Matrix {
    int nEqns;
    Matrix solutions;
public:
   LinEqns(Matrix& soln);
   //...
};

LinEqns::LinEqns(Matrix& soln): Matrix(soln.Rows(), soln.Rows()+1), solution(soln(soln.Rows(), 1)) {

}
```

## Static members

It is possible to declare a data member of a class to be static. This ensures that there will be exactly one copy of the member, shared by all objects of the class.

```
class Window {
    static Window* windList;
    Window* next;
}
```

Here, no matter how many objects of type Window are defined, there will be only one windList and this will be initially 0.
