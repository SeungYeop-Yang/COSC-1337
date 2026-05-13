#include <ctime>
#include <iostream>

using namespace std;

class Card {
private:
    int value;
    int suit;

public:
    Card();
    void deal();
    int getValue();
    int getSuit();
    void setValue(int);
    void setSuit(int);
};

Card::Card()
{
    value = -1;
    suit = -1;
}

void Card::deal()
{
    srand((unsigned)time(0));
    // seeding random number generator with system time in every time
    // the method called ... just ridiculous.
    value = (rand() % 13) + 1;
    suit = (rand() % 4) + 1;
}

int Card::getValue() { return value; }
int Card::getSuit() { return suit; }

void Card::setValue(int v) { value = v; }
void Card::setSuit(int s) { suit = s; }
