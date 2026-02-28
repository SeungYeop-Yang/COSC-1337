#include <iostream>
#include <string>
using namespace std;

/********1*********2*********3*********4*********5*********6*********7********/
class Complex {
    double re, im;

public:
    Complex(double r, double i) : re(r), im(i) {}
    Complex(double r) : re(r), im(0) {}
    Complex() : re(0), im(0) {}

    double real() const { return re; }
    // A C++ method definition suffixed with `const`
    // const member function promising that the function will not modify
    // the object's data members.

    void real(double d) { re = d; }
    double imag() const { return im; }
    void imag(double d) { im = d; }

    Complex& operator+=(Complex z)
    {
        re += z.re;
        im += z.im;
        return *this;
    }

    Complex& operator-=(Complex z)
    {
        re -= z.re;
        im -= z.im;
        return *this;
    }

    bool operator==(Complex b) { return re == b.real() && im == b.imag(); }
};

/********1*********2*********3*********4*********5*********6*********7********/

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

    ~Vector() { delete[] elem; }
    // Plain `delete` deletes an individual object,
    // `delete[]` deletes an array.

    double& operator[](int i) { return elem[i]; }
    int size() const { return sz; }
};

int main()
{
    Complex a{2.3};
    Complex b = Complex(2, 3);

    cout << static_cast<string>(a == b ? "True" : "False") << endl;
    if (a == b) {
        cout << "True" << endl;
    }
    else {
        cout << "False" << endl;
    }
    return 0;
}
