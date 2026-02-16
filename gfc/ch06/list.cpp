struct Element {
    int value;
    Element* next;
};

class List {
    Element* elems;
public:
    List();
    ~List();
    bool Insert(int);
    bool Delete(int);
    bool Contains(int);
};
