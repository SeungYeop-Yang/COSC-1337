#ifndef HEADER_HAND_CLASS_H
#define HEADER_HAND_CLASS_H

/********1*********2*********3*********4*********5*********6*********7*********8
 *
 * Seung Yeop Yang
 *
 * Lab 4: "Dynamic memory and recursion"
 *
 * You will first make the hand of cards dynamically allocated depending on
 * the size of hand specified when the Hand object is instantiated in your
 * client program code.
 *
 * You will then add new methods to your Hand class to check for the
 * different types of Poker hands.
 *
 * The Hand class will have two data attributes:
 *  1. handOfCards (a Card pointer)
 *  2. numCards (the number of cards in the hand will be passed when the
 *     Hand object is instantiated)
 *
 * The hand class will have the following methods:
 *  1. Parameterized constructor that initializes numCards to the value passed
 *     in and dynamically allocates the array for that number of Card objects.
 *     You need 3 cards for the Low Card of Three game and 5 cards for the
 *     One Hand Poker game.
 *  2. dealHand
 *     Invokes the deal method on each of its card objects (you will use
 *     numCards to know how many to deal)
 *  3. getNumCards
 *     returns the value of the private data attribute numCards (from Lab 3)
 *  4. getCardFaceValues
 *     returns the string value and suit for the given card. (from Lab 3)
 *  5. getCardNumericValues
 *     returns the integer value and suit for the given card. (from Lab 3)
 *  6. sortHands
 *     this method will sort the cards in the handOfCards array into ascending
 *     order. (from Lab 3)
 *  7. setCard
 *     this method will be used to test your program. You will pass in the
 *     index of the card and the two numeric values for card value and suit.
 *  8. You will need Boolean methods to test each type of Poker hand.
 *     There are 10 different hands you need to check for:
 *      bool isRoyalFlush();
 *      bool isStraightFlush();
 *      bool isFourOfAKind();
 *      bool isFullHouse();
 *      bool isFlush();
 *      bool isStraight();
 *      bool isTwoPair();
 *      bool isPair();
 *      bool is HighCard();
 *
 * *****************************************************************************
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

#include "lab4_Card_Class_SeungYeop_Yang.cpp"
#include <bitset>
#include <iostream>

using namespace std;

class Hand {
private:
    Card* handOfCards;
    int numCards;

public:
    Hand();
    Hand(int);
    ~Hand();
    void dealHand();
    int getNumCards();
    void getCardFaceValues(int index, string& faceValueName, string& suitName);
    void getCardNumericValues(int index, int& cardValueInt, int& cardSuitInt);
    int setCard(int index, int cardValueInt, int cardSuitInt);
    void sortHand();
    bool isRoyalFlush();
    bool isStraightFlush();
    bool isFourOfAKind();
    bool isFullHouse();
    bool isFlush();
    bool isThreeOfAKind();
    bool isStraight();
    bool isTwoPair();
    bool isPair();
    bool isHighCard(Hand&);
    void displayHand();
    void sortNumeric();
    int buildRankScore();
    bool isAceInHand();
    string highestHand(int);
};

Hand::Hand() { numCards = 0; }
Hand::Hand(int nCards)
{
    numCards = nCards;
    handOfCards = new Card[nCards];
}
Hand::~Hand() { delete[] handOfCards; }

void Hand::dealHand()
{
    for (int i = 0; i < numCards; i++)
        handOfCards[i].Deal(); // populate the hand with numCards * Card.Deal()
}

int Hand::getNumCards() { return numCards; }

void Hand::getCardFaceValues(int index, string& faceValueName, string& suitName)
{
    if (index >= 0 && index < numCards)
        handOfCards[index].getFaceValue(faceValueName, suitName);
    else
        faceValueName = suitName = "None";
}

void Hand::getCardNumericValues(int index, int& cardValueInt, int& cardSuitInt)
{
    if (index >= 0 && index < numCards)
        handOfCards[index].getNumericValue(cardValueInt, cardSuitInt);
    else
        cardValueInt = cardSuitInt = 0;
}

int Hand::setCard(int index, int cardValueInt, int cardSuitInt)
{
    if (index >= 0 && index < numCards) {
        handOfCards[index].setValue(cardValueInt);
        handOfCards[index].setSuit(cardSuitInt);
        return 0;
    }
    else
        return 1; // index error
}
void Hand::sortHand()
{
    // bubble sort considering Ace is the biggest, not optimized for swap
    for (int i = 0; i < numCards - 1; i++)
        for (int j = 0; j < numCards - 1 - i; j++)
            if (handOfCards[j].getValue() == 1) // Ace is bigger than anything
                handOfCards[j].swap(handOfCards[j + 1]); // swap if Ace
            else if (handOfCards[j].getValue() > handOfCards[j + 1].getValue())
                if (handOfCards[j + 1].getValue() != 1)
                    handOfCards[j].swap(handOfCards[j + 1]); // swap
}

// Royal Flush
// An ace high straight flush
bool Hand::isRoyalFlush()
{
    bool isRoyalFlush = false;

    if (isStraightFlush()) {
        sortHand();
        if (handOfCards[4].getValue() == 1)
            isRoyalFlush = true;
    }
    return isRoyalFlush;
}

// Straight Flush
// Five consecutive cards in the same suit
bool Hand::isStraightFlush() { return (isStraight() && isFlush()); }

// Four of a Kind
// Four cards of the same rank
bool Hand::isFourOfAKind()
{

    bool isFourOfAKind = false;
    const int NUMBER_OF_CARDS = 14;
    int numberOfRanks[NUMBER_OF_CARDS] = {0, 0, 0, 0, 0, 0, 0,
                                          0, 0, 0, 0, 0, 0, 0};
    for (int i = 0; i < numCards; i++)
        numberOfRanks[handOfCards[i].getValue()]++;

    for (int i = 1; i < NUMBER_OF_CARDS; i++)
        if (numberOfRanks[i] == 4) {
            isFourOfAKind = true;
            break;
        }

    return isFourOfAKind;
}

//  Full House
// Three cards of the same rank with two cards of
// another same rank
bool Hand::isFullHouse() { return isThreeOfAKind() && isPair(); }

// Flush
// Five cards in the same suit (not consecutive)
bool Hand::isFlush()
{
    bool isFlush = false;
    const int NUMBER_OF_SUITS = 5;
    int numberOfSuits[NUMBER_OF_SUITS] = {0, 0, 0, 0, 0};
    for (int i = 0; i < numCards; i++)
        numberOfSuits[handOfCards[i].getSuit()]++;

    for (int i = 1; i < NUMBER_OF_SUITS; i++)
        if (numberOfSuits[i] == NUMBER_OF_SUITS)
            isFlush = true;

    return isFlush;
}

// Straight
// Five consecutive cards of different suits.
// (Aces can count either as a high or a low card.)
bool Hand::isStraight()
{
    bool isStraight = false;
    int first = 0;
    const int NUMBER_OF_CARDS = 14;
    int numberOfRanks[NUMBER_OF_CARDS] = {0, 0, 0, 0, 0, 0, 0,
                                          0, 0, 0, 0, 0, 0, 0};
    for (int i = 0; i < numCards; i++)
        numberOfRanks[handOfCards[i].getValue()]++;
    // debug
    // cout << "isAceInHand is " << isAceInHand() << endl;

    if (isAceInHand()) {
        sortNumeric();
        first = 1; // straight starting from the Ace
        for (int i = first; i <= first + 4; i++) {
            if (numberOfRanks[i] == 1) {
                isStraight = true;
            }
            else {
                isStraight = false;
                break;
            }
        }
        if (isStraight)
            return true;
        // straight starting from 10
        for (int i = 10; i < NUMBER_OF_CARDS; i++) {
            if (numberOfRanks[i] == 1) {
                isStraight = true;
            }
            else {
                isStraight = false;
                break;
            }
        }
        if (isStraight)
            return true;
        else
            return false;
    }
    // straight without the Ace
    else {
        for (int i = 2; i < 10; i++) {
            if (numberOfRanks[i]) {
                first = i;
                break;
            }
        }
        for (int i = first; i <= first + 4; i++) {
            if (numberOfRanks[i] == 1) {
                isStraight = true;
            }
            else {
                isStraight = false;
                break;
            }
        }
    }

    return isStraight;
}

// Three of a Kind
// Three cards of the same rank
bool Hand::isThreeOfAKind()
{

    bool isThreeOfAKind = false;
    const int NUMBER_OF_CARDS = 14;
    int numberOfRanks[NUMBER_OF_CARDS] = {0, 0, 0, 0, 0, 0, 0,
                                          0, 0, 0, 0, 0, 0, 0};
    for (int i = 0; i < numCards; i++)
        numberOfRanks[handOfCards[i].getValue()]++;

    for (int i = 1; i < NUMBER_OF_CARDS; i++)
        if (numberOfRanks[i] == 3) {
            isThreeOfAKind = true;
            break;
        }
    return isThreeOfAKind;
}

// Two Pair
// Two cards of the same rank together with
// two cards of another same rank
bool Hand::isTwoPair()
{
    bool isTwoPair = false;
    const int NUMBER_OF_CARDS = 14;
    int numberOfRanks[NUMBER_OF_CARDS] = {0, 0, 0, 0, 0, 0, 0,
                                          0, 0, 0, 0, 0, 0, 0};
    int numberOfPairs = 0;

    for (int i = 0; i < numCards; i++)
        numberOfRanks[handOfCards[i].getValue()]++;

    for (int i = 1; i < NUMBER_OF_CARDS; i++)
        if (numberOfRanks[i] == 2)
            numberOfPairs++;

    if (numberOfPairs == 2)
        isTwoPair = true;

    return isTwoPair;
}

// One Pair
// Two cards of the same rank.
bool Hand::isPair()
{
    bool isPair = false;
    const int NUMBER_OF_CARDS = 14;
    int numberOfRanks[NUMBER_OF_CARDS] = {0, 0, 0, 0, 0, 0, 0,
                                          0, 0, 0, 0, 0, 0, 0};
    int numberOfPairs = 0;

    for (int i = 0; i < numCards; i++)
        numberOfRanks[handOfCards[i].getValue()]++;

    for (int i = 1; i < NUMBER_OF_CARDS; i++)
        if (numberOfRanks[i] == 2)
            numberOfPairs++;

    if (numberOfPairs == 1)
        isPair = true;
    return isPair;
}

// High Card: Five cards of different rank and suit
// (that do not form any of the other hand ranks)
// Hands are ranked by "comparing" the highest value card.
bool Hand::isHighCard(Hand& other)
{
    bool isHighCard = false;
    if (buildRankScore())
        return isHighCard;
    if (other.buildRankScore())
        return isHighCard;
    sortHand();
    other.sortHand();

    if (handOfCards[4].getValue() == other.handOfCards[4].getValue())
        return isHighCard;

    if (handOfCards[4].getValue() == 1)
        isHighCard = true;
    else if (other.handOfCards[4].getValue() == 1)
        isHighCard = false;
    else {
        if (handOfCards[4].getValue() <= other.handOfCards[4].getValue())
            isHighCard = false;
        else
            isHighCard = true;
    }

    return isHighCard;
}

void Hand::displayHand()
{
    string faceValueName, suitValueName;

    for (int i = 0; i < numCards; i++) {
        this->getCardFaceValues(i, faceValueName, suitValueName);
        cout << "(" << faceValueName << ", " << suitValueName << ") ";
    }
    cout << endl;
}

void Hand::sortNumeric()
{
    // bubble sort considering Ace is the lowest, not optimized for swap
    for (int i = 0; i < numCards - 1; i++)
        for (int j = 0; j < numCards - 1 - i; j++)
            if (handOfCards[j].getValue() > handOfCards[j + 1].getValue())
                handOfCards[j].swap(handOfCards[j + 1]); // swap
}

int Hand::buildRankScore()
{
    int rankVector = 0;

    if (isRoyalFlush()) {
        rankVector |= 1 << 9;
    }
    if (isStraightFlush()) {
        rankVector |= 1 << 8;
    }
    if (isFourOfAKind()) {
        rankVector |= 1 << 7;
    }
    if (isFullHouse()) {
        rankVector |= 1 << 6;
    }
    if (isFlush()) {
        rankVector |= 1 << 5;
    }
    if (isThreeOfAKind()) {
        rankVector |= 1 << 4;
    }
    if (isStraight()) {
        rankVector |= 1 << 3;
    }
    if (isTwoPair()) {
        rankVector |= 1 << 2;
    }
    if (isPair()) {
        rankVector |= 1 << 1;
    }

    return rankVector;
}

bool Hand::isAceInHand()
{
    bool isAceInHand = false;
    const int NUMBER_OF_CARDS = 14;
    int numberOfRanks[NUMBER_OF_CARDS] = {0, 0, 0, 0, 0, 0, 0,
                                          0, 0, 0, 0, 0, 0, 0};
    int numberOfPairs = 0;

    for (int i = 0; i < numCards; i++)
        numberOfRanks[handOfCards[i].getValue()]++;

    if (numberOfRanks[1])
        isAceInHand = true;

    return isAceInHand;
}

string Hand::highestHand(int rankVector)
{
    string highest = "nothing";

    if (rankVector & 1)
        highest = "HighCard";
    else if (rankVector & 1 << 1)
        highest = "One Pair";
    else if (rankVector & 1 << 2)
        highest = "Two Pair";
    else if (rankVector & 1 << 3)
        highest = "Straight";
    else if (rankVector & 1 << 4)
        highest = "Three of a Kind";
    else if (rankVector & 1 << 5)
        highest = "Flush";
    else if (rankVector & 1 << 6)
        highest = "Full House";
    else if (rankVector & 1 << 7)
        highest = "Four of a Kind";
    else if (rankVector & 1 << 8)
        highest = "Straight Flush";
    else if (rankVector & 1 << 9)
        highest = "Royal Flush";
    else
        highest = highest;

    return highest;
}

#endif // HEADER_HAND_CLASS_H
