
class X {
public:
    X();                    // default constructor
    X(Sometype);            // ordinary constructor
    X(const X&);            // copy constructor
    X(X&&);                 // move constructor
    X& operator=(const X&); // copy assignment
    X& operator=(X&&);      // move assignment
    ~X();                   // destructor
};
