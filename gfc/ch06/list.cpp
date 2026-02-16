struct Element
{
    int value;
    Element *next;
};

class List
{
    Element *elems;

public:
    List();
    ~List();
    virtual bool Insert(int);
    virtual bool Delete(int);
    bool Contains(int);
};

class Set : public List
{
    int card;

public:
    bool Insert(int);
    bool Delete(int);
};

bool List::Insert(int val)
{
    Element *elem = new Element;
    if (elem != 0)
    {
        elem->value = val;
        elem->next = elems;
        elems = elem;
    }
    return elem != 0;
}

bool List::Delete(int val)
{
    if (elems == 0)
        return false;
    Element *tmp = elems;
    if (elems->value == val)
    {
        elems = elems->next;
        delete tmp;
        return true;
    }
    else
        for (Element *elem = elems; elem->next != 0; elem = elem->next)
            if (elem->next->value == val)
            {
                tmp = elem->next;
                elem->next = tmp->next;
                delete tmp;
                return true;
            }
    return false;
}

bool Set::Insert(int val)
{
    if (!Contains(val) && List::Insert(val))
    {
        ++card;
        return true;
    }
    return false;
}

bool Set::Delete(int val)
{
    if (List::Delete(val))
    {
        --card;
        return true;
    }
    return false;
}
