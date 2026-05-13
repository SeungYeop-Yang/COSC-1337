/********1*********2*********3*********4*********5*********6*********7*********8
 *
 * Seung Yeop Yang
 * Lab 2: "Classes, Arrays"
 *
 * Program Description
 * 1. Create the "Card" class
 *  Your class definition in a separate file:
 *      lab2_Card_Class_SeungYeop_Yang.cpp
 *  The Card class will have two data attributes;
 *      a. value (an integer between 1 and 13)
 *      b. suit (an integer between 1 and 4) - will not use the suit in Lab 2
 *  The Card class will have the following methods:
 *      a. Default constructor that initialized value and suit to -1
 *      b. Deal
 *          - generates and assigns a value between 1 and 13,
 *          - and a suit between 1 and 4
 *          - this is the module where you should seed ?
 *      c. getValue: returns the numeric value of the card
 *      d. getSuit:  returns the numeric value of the suit
 *
 ********1*********2*********3*********4*********5*********6*********7*********/

// version 03/06/26
// #include <cstdlib>

#include <random>
using namespace std;

const int MAX_VALUE = 13;
const int MAX_SUIT = 4;

class Card {
private:
    int value;
    int suit;

public:
    Card()
    {
        value = -1;
        suit = -1;
    }

    void Deal()
    {
        // version 03/06/26
        // value = (rand() % MAX_VALUE) + 1;
        // suit = (rand() % MAX_SUIT) + 1;
        // replaced the classic standard practice with the new c++11 seeding
        // in the 'deal' method of the class Card to adhere the requirements

        random_device rdev;
        mt19937 engine(rdev());
        uniform_int_distribution<int> random_value(1, 13);
        uniform_int_distribution<int> random_suit(1, 4);

        value = random_value(engine);
        suit = random_suit(engine);
    }

    int getValue() { return value; }

    int getSuit() { return suit; }
};
