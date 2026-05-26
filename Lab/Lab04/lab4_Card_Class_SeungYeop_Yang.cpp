#ifndef HEADER_CARD_CLASS_H
#define HEADER_CARD_CLASS_H

/********1*********2*********3*********4*********5*********6*********7*********8
 *
 * Seung Yeop Yang
 * Lab 4: "Dynamic memory and recursion"
 *
 * Feedback from Lab3:
 * In your card class, members like 'swap' and 'seeded' that are only
 * used by your class code should be private and inaccessible to the
 * client program code.
 *
 * Actions on feedback:
 * 1. moved seeded variable as private
 * 2. swap method was used outside of the class code and was kept as public
 *
 *
 * Lab 3: "Strings, sorting"
 *
 * Adding and modifying Lab2 program:
 * First modify the "Card" class
 * The Card class will still have just two data attributes:
 * 1. value (an integer between 1 and 13)
 * 2. suit (an integer between 1 and 4)
 *
 * You will add one method to the Card class, giving you 5 methods:
 * 1. Default constructor that initialized value and suit to -1
 * 2. Deal - generates and assigns a value between 1 and 13,
 *           and a suit between 1 and 4
 * 3. getValue - returns the numeric value of the card
 * 4. getSuit - returns the numeric value of the suit
 * 5. getFaceValue - returns two strings, via the parameter list, which are the
 *                   face value of the card as a word (noth the digits) and the
 *                   name of the suit. The suit values are:
 *                  1 - Clubs
 *                  2 - Diamonds
 *                  3 - Hearts
 *                  4 - Spades
 *
 * You will create the Hand class to be used for a hand of cards.
 * The Hand class with have two data attributes:
 *     handOfThree(an array of 3 Card objects)
 *     numCards (the number of cards in the hand, for this lab it will be 3)
 *
 * The Hand class will have the following methods:
 * 1. Default constructor that initializes numCards to 3
 * 2. dealHand - invokes the deal method on each of its 3 card objects
 * 3. getNumCards - returns the value of the private data attribute numCards
 * 4. getCardFaceValues - returns the string value and suit for the given card.
 *    The card is specified by passing in an index. Valid values for an index
 *    are 0, 1, 2. You will also have to pass two string place holder variables
 *    to return the string face values in. If the index is invalid, assign to
 *    the value "None" to indicate the index was not valid.
 *    If the index is valid, you will assign the two string variables the word
 *    face value and suit. Your parameter list should look like this:
 *        (int index, string &faceValueName, string&suitName)
 * 5. getCardNumeric Values - returns the integer value and suit for the given
 *    card. The card is specified by passing in an index. Valid values for an
 *    index are 0, 1, 2. You will also have to pass two integer place holder
 *    variables to return the integer values in. If the index is invalid,
 *    assign to the two integer variables the value zero to indicate the index
 *    was not valid. If the index is valid, you will assign the two integer
 *    variables the numeric value and suit. So your parameter list should look
 *    like this:
 *        (int index, int &cardValueInt, int &cardSuitInt)
 * 6. sortHands - this method will sort the cards in the handOfThree array
 *    into ascending order. Make sure you remember that 1 (Ace) is the highest
 *    card and sort accordingly. You can use the Bubble Sort or the Selection
 *    Sort.
 *
 *
 ********1*********2*********3*********4*********5*********6*********7*********8
 * Requirements of Lab2 and Lab1
 * Program Description
 * 1. Create the "Card" class
 *  Your class definition in a separate file:
 *      lab3_Card_Class_SeungYeop_Yang.cpp
 *  The Card class will have two data attributes;
 *      a. value (an integer between 1 and 13)
 *      b. suit (an integer between 1 and 4) - will not use the suit in Lab 2
 *  The Card class will have the following methods:
 *      a. Default constructor that initialized value and suit to -1
 *      b. Deal
 *          - generates and assigns a value between 1 and 13,
 *          - and a suit between 1 and 4
 *          - this is the module where you should seed
 *      c. getValue: returns the numeric value of the card
 *      d. getSuit:  returns the numeric value of the suit
 *
 ********1*********2*********3*********4*********5*********6*********7*********/

#include <ctime>
#include <random>
using namespace std;

const int MAX_VALUE = 13;
const int MAX_SUIT = 4;

class Card {
private:
    int value;
    int suit;
    static bool seeded; // flag to seed once when not seeded

public:
    void Deal(); // The method name starting with capital letter to adhere the
                 // requirements
    Card();
    int getValue();
    int getSuit();
    void getFaceValue(string& faceValue, string& suitName);
    void getNumericValue(int& cardValue, int& cardSuit);
    void setValue(int valueInt);
    void setSuit(int suitInt);
    void swap(Card& other);
};

bool Card::seeded = false; // for all modern c++ (C++11 or later)

Card::Card()
{
    value = -1;
    suit = -1;
}

void Card::Deal()
{
    if (!Card::seeded) {                              // if not seeded,
        srand(static_cast<unsigned int>(time(NULL))); // seed for rand()
        Card::seeded = true;                          // once is enough
    }
    value = (rand() % MAX_VALUE) + 1;
    suit = (rand() % MAX_SUIT) + 1;
}

int Card::getValue() { return value; }

int Card::getSuit() { return suit; }

void Card::getFaceValue(string& faceValue, string& suitName)
{
    // return the string value for the card and suit
    switch (value) {
    case 1:
        faceValue = "Ace";
        break;
    case 2:
        faceValue = "Two";
        break;
    case 3:
        faceValue = "Three";
        break;
    case 4:
        faceValue = "Four";
        break;
    case 5:
        faceValue = "Five";
        break;
    case 6:
        faceValue = "Six";
        break;
    case 7:
        faceValue = "Seven";
        break;
    case 8:
        faceValue = "Eight";
        break;
    case 9:
        faceValue = "Nine";
        break;
    case 10:
        faceValue = "Ten";
        break;
    case 11:
        faceValue = "Jack";
        break;
    case 12:
        faceValue = "Queen";
        break;
    case 13:
        faceValue = "King";
        break;
    default:
        faceValue = "None";
    }

    switch (suit) {
    case 1:
        suitName = "Clubs";
        break;
    case 2:
        suitName = "Diamonds";
        break;
    case 3:
        suitName = "Hearts";
        break;
    case 4:
        suitName = "Spades";
        break;
    default:
        suitName = "None";
    }
}

void Card::getNumericValue(int& cardValue, int& cardSuit)
{
    // return the valid card value or 0
    if (value >= 1 && value <= 13)
        cardValue = value;
    else
        cardValue = 0;

    // return the valid suit value or 0
    if (suit >= 1 && suit <= 4)
        cardSuit = suit;
    else
        cardSuit = 0;
}

void Card::setValue(int valueInt) { value = valueInt; }
void Card::setSuit(int suitInt) { suit = suitInt; }

void Card::swap(Card& other)
{
    Card temp;

    // swap *this and other
    // by storing other to temp
    //            *this to other
    //             temp to *this
    temp = other;
    other = *this;
    *this = temp;
}

#endif // HEADER_CARD_CLASS_H
