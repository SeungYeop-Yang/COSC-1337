#include <iostream>

const int maxCard = 16;
enum Bool
{
    False,
    True
};
enum ErrCode
{
    noErr,
    overflow
};

class Set
{
    int elems[maxCard];
    int card;

public:
    void EmptySet() { card = 0; }
    Bool Member(int);
    ErrCode AddElem(int);
    ErrCode RmvElem(int);
    void Copy(Set *);
    Bool Equal(Set *);
    void Print();
    void Intersect(Set *, Set *);
    ErrCode Union(Set *, Set *);
};

Bool Set::Member(int elem)
{
    for (int i = 0; i < card; ++i)
        if (elems[i] == elem)
            return True;
    return False;
}

ErrCode Set::AddElem(int elem)
{
    for (int i = 0; i < card; ++i)
        if (elems[i] == elem)
            return noErr;

    if (card < maxCard)
    {
        elems[card++] = elem;
        return noErr;
    }
    else
        return overflow;
}

ErrCode Set::RmvElem(int elem)
{
    for (int i = 0; i < card; ++i)
        if (elems[i] == elem)
        {
            for (; i < card - 1; ++i)
                elems[i] = elems[i + 1];
            --card;
        }
}

void Set::Copy(Set *set)
{
    for (int i = 0; i < card; ++i)
        set->elems[i] = elems[i];
    set->card = card;
}

Bool Set::Equal(Set *set)
{
    if (card != set->card)
        return False;
    for (int i = 0; i < card; ++i)
        if (!set->Member(elems[i]))
            return False;
    return True;
}

void Set::Print()
{
    std::cout << "{";
    for (int i = 0; i < card - 1; ++i)
        std::cout << elems[i] << ",";
    if (card > 0)
        std::cout << elems[card - 1];
    std::cout << "}" << std::endl;
}

int main()
{

    Set s1, s2, s3;
    s1.EmptySet();
    s2.EmptySet();
    s3.EmptySet();
    s1.AddElem(10);
    s1.AddElem(20);
    s1.AddElem(30);
    s1.AddElem(40);
    s2.AddElem(30);
    s2.AddElem(50);
    s2.AddElem(10);
    s2.AddElem(60);
    std::cout << "s1 = ";
    s1.Print();
    std::cout << "s2 = ";
    s2.Print();

    return 0;
}
