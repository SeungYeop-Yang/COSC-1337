#include <iostream>
#include <string>
#include <variant>
using namespace std;

class Node
{
};

struct Entry
{
    string name;
    variant<Node *, int> v;
};

void f(Entry *pe)
{
    if (holds_alternative<int>(pe->v))
        cout << get<int>(pe->v);
    else
        cout << get<Node *>(pe->v);
}
