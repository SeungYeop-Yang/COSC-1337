#include <iostream>
#include <ctime>

using namespace std;

class Card
{
	private:
		int value;
		int suit;

	public:
		Card();
		void deal();
		int getValue();
		void setValue(int);
		int getSuit();

};

// Constructor initializes attributes to -1
// to indicate that they have not been dealt
Card::Card()
{
	value = -1;
	suit = -1;
}

void Card::deal()
{
	// Seed the random number generator
	srand((unsigned)time(0));

	// Deal the card
    value = (rand()%13)+1;
    suit = (rand()%4)+1;
}

int Card::getValue()
{ return value; }

void Card::setValue(int v)
{ value = v; }

int Card::getSuit()
{ return suit; }
