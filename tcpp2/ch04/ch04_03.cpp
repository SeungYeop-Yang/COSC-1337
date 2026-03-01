/********1*********2*********3*********4*********5*********6*********7********/
#include <iostream>
#include <list>
#include <vector>
using namespace std;

class Container {
public:
    virtual double& operator[](int) = 0;
    virtual int size() const = 0;
    virtual ~Container() {}
    // `virtual` means may be redefined later in a class derived from this one.
    // `= 0` syntax says the function is pure virtual; that is, some class
    // derived from Container must define the function.

    // A Container can only serve as the interface to a class that implements
    // its operator[]() and size() function.

    // A class with a pure virtual function is called an `abstract class`.
};

void use(Container& c)
{
    const int sz = c.size();

    for (int i = 0; i < sz; i++)
        cout << c[i] << endl;
}

/********1*********2*********3*********4*********5*********6*********7********/

// Note how use() uses the Container interface in complete ignorance of
// implmenetation details. It uses size() and [] without any idea of exactly
// which type provides their implementation.

// As is common for abstract classes, Container does not have a constructor.
// On the other hand, Containerr does have a destructor and that destructor is
// virtual.

class Vector {
private:
    double* elem;
    int sz;

public:
    Vector(int s) : elem(new double[s]), sz(s)
    {
        for (int i = 0; i < s; i++)
            elem[i] = 0;
    }

    Vector() { Vector(0); }

    // Vector(initializer_list<double>);
    // void push_back(double);

    ~Vector() { delete[] elem; }
    // Plain `delete` deletes an individual object,
    // `delete[]` deletes an array.

    double& operator[](int i) { return elem[i]; }
    int size() const { return sz; }
};

/********1*********2*********3*********4*********5*********6*********7********/

class Vector_container : public Container {
public:
    Vector_container(int s) : v(s) {}
    ~Vector_container() {}
    // The destructor ~Vector_container() overrides the base class destructor
    // ~Container(). Note that the member destructor (~Vector()) is implicitly
    // invoked by its class's destructor (~Vector_container())

    double& operator[](int i) override { return v[i]; }
    int size() const override { return v.size(); }
    // override the corresponding members in the base class Container.

private:
    Vector v;
};

/********1*********2*********3*********4*********5*********6*********7********/

class List_container : public Container {
private:
    list<double> ld;

public:
    List_container() {}
    List_container(initializer_list<double> il) : ld(il) {}
    ~List_container() {}
    double& operator[](int i) override;
    int size() const override { return ld.size(); };
};

double& List_container::operator[](int i)
{
    for (auto& x : ld) {
        if (i == 0)
            return x;
        --i;
    }
    throw out_of_range{"List container"};
}

int main()
{
    Vector_container vc(10);

    for (int i = 0; i < 10; i++)
        vc[i] = i;

    use(vc);

    List_container lc = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    use(lc);

    return 0;
}
