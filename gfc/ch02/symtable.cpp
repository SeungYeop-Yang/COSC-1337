#include <cstring>
#include <iostream>

typedef int SymValue;
struct Symbol {
    char* name;
    SymValue value;
    Symbol* next;
};

class SymTable {
    Symbol** table;
    int size;
    int Hash (char*);

public:
    SymTable (int);
    Symbol* AddSym (char*, SymValue);
    Symbol* FindSym (char*);
    bool    RmvSym (char*);
    void    PrintTable ();
};

SymTable::SymTable (int sz)
{

    if (sz <= 0)
    {
        size = 0;
        table = 0;
    }
    else if ((table = new Symbol*[size=sz]) != 0)
        for (int i = 0; i < size; ++i)
            table[i] = nullptr;
    else
        size = 0;
}

int SymTable::Hash (char* name)  // the hash function
{
    int slot = 0;
    while (*name)
        slot += *name++;
    return slot % size;
}   // Hash

Symbol* SymTable::AddSym (char* name, SymValue value)
{
    Symbol* sym;
    int slot = Hash(name);
    if ((sym = new Symbol) != nullptr &&
         (sym->name = new char[strlen(name)+1]) != nullptr)
    {
        strcpy(sym->name, name);
        sym->value = value;
        sym->next = table[slot];
        table[slot] = sym;
        return sym;
    }
    else
    {
        delete sym;
        sym = nullptr;
    }

    return sym;
}   // AddSym

Symbol* SymTable::FindSym (char* name)
{
    Symbol* sym;
    for (sym = table[Hash(name)]; sym != nullptr; sym = sym->next)
        if (strcmp(sym->name, name) == 0)
            return sym;
    return nullptr;
}   // FindSym

bool SymTable::RmvSym (char* name)
{
    Symbol* sym;
    Symbol* prev = nullptr;
    int slot = Hash(name);
    for (sym = table[slot]; sym != nullptr; prev = sym, sym = sym->next)
        if (strcmp(sym->name, name) == 0)
        {
            if (prev != nullptr)
                prev->next = sym->next;
            else
                table[slot] = sym->next;
            delete[] sym->name;
            delete sym;
            return true;
        }
    return false;
}   // RmvSym

void SymTable::PrintTable ()
{
    for (int i = 0; i < size; ++i)
        for (Symbol* sym = table[i]; sym != nullptr; sym = sym->next)
            std::cout << "Slot " << i << ": " << sym->name
                      << " = " << sym->value << std::endl;
}   // PrintTable

int main()
{
    SymTable st(10);
    st.AddSym("alpha", 1);
    st.AddSym("beta", 2);
    st.AddSym("gamma", 3);
    st.PrintTable();
    std::cout << "Finding 'beta': " << st.FindSym("beta")->value << std::endl;
    st.RmvSym("beta");
    std::cout << "Finding 'beta' after removal: " << (st.FindSym("beta") ? "Found" : "Not Found") << std::endl;
    st.PrintTable();
    return 0;
}
