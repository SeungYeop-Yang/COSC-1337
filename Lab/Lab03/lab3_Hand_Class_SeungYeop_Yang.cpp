#ifndef HEADER_HAND_CLASS_H
#define HEADER_HAND_CLASS_H

/********1*********2*********3*********4*********5*********6*********7*********8
 *
 * Seung Yeop Yang
 * Lab 3: "Strings, sorting"
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
 ********1*********2*********3*********4*********5*********6*********7*********/

#include "lab3_Card_Class_SeungYeop_Yang.cpp"

using namespace std;

class Hand {
private:
    Card handOfThree[3];
    int numCards;

public:
    Hand();
    void dealHand();
    int getNumCards();
    void getCardFaceValues(int index, string& faceValueName, string& suitName);
    void getCardNumericValues(int index, int& cardValueInt, int& cardSuitInt);
    void sortHand();
};

Hand::Hand() { numCards = 3; }

void Hand::dealHand()
{
    for (int i = 0; i < numCards; i++)
        handOfThree[i].Deal(); // populate the hand with numCards * Card.Deal()
}

int Hand::getNumCards() { return numCards; }

void Hand::getCardFaceValues(int index, string& faceValueName, string& suitName)
{
    return handOfThree[index].getFaceValue(faceValueName, suitName);
}

void Hand::getCardNumericValues(int index, int& cardValueInt, int& cardSuitInt)
{
    return handOfThree[index].getNumericValue(cardValueInt, cardSuitInt);
}

void Hand::sortHand()
{
    // bubble sort considering Ace is the biggest, not optimized for swap
    for (int i = 0; i < numCards - 1; i++)
        for (int j = 0; j < numCards - 1 - i; j++)
            if (handOfThree[j].getValue() == 1) // Ace is bigger than anything
                handOfThree[j].swap(handOfThree[j + 1]); // swap if Ace
            else if (handOfThree[j].getValue() > handOfThree[j + 1].getValue())
                if (handOfThree[j + 1].getValue() != 1)
                    handOfThree[j].swap(handOfThree[j + 1]); // swap
}

#endif // HEADER_HAND_CLASS_H
