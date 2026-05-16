/********1*********2*********3*********4*********5*********6*********7*********8
 *
 * Seung Yeop Yang
 *
 * Lab 4: "Dynamic memory and recursion"
 *
 * Adding to and modifying your Lab 3 program:
 *
 * You can add a menu option for testing a poker hand.
 *
 * Your menu should have the following options:
 *  1. High Card
 *  2. Low Hand of Three
 *  3. One Hand Poker
 *  4. Test a hand
 *  5. Quit
 *
 * ********1*********2*********3*********4*********5*********6*********7*********8
 *
 * Lab 3: "Strings, sorting"
 *
 * You will modify your Low card of three game
 *      Rather than working with two arrays of card objects, the Low card of
 *      three will work with two Hand objects. The game will do the same thing
 *      only now you use Hand methods, not Card methods. to work with the cards
 *      and retrieve information about them. Your Low card of three game will
 *      not use any Card class methods.
 *
 * ********1*********2*********3*********4*********5*********6*********7*********8
 *
 * Requirements of Lab2 and Lab1
 * Program Description
 * 1. Create the "Card" class
 *  Your class definition in a separate file:
 *      lab2_Card_Class_SeungYeop_Yang.cpp
 *  The Card class will have two data attributes;
 *      a. value (an integer between 1 and 13)
 *      b. suit (an integer between 1 and 4) - will not use the suit in Lab 2
 *  The Card class will have the following methods:
 *      a. Default constructor that initialized value and suit to -1 ?
 *      b. Deal
 *          - generates and assigns a value between 1 and 13,
 *          - and a suit between 1 and 4
 *          - this is the module where you should seed
 *      c. getValue: returns the numeric value of the card
 *      d. getSuit:  returns the numeric value of the suit
 *
 * 2. You will modify your High card game
 *  Modify your code to work with a Card object
 *  Ask each player for their name. Use their name in the game output
 *  Display the face value of the card as a word rather than an integer
 *
 * 3. You will implement lowCardOfThree
 * Inputs: none
 * Outputs: return 0 if successful
 * Purpose: This function plays game: lowCardOfThree
 *  1. Ask each of the two players for their name.
 *  2. Deal each player three cards.
 *  3. Store each player's cards in an array of Card objects.
 *  4. The winner is the player that has the lowest card of the three dealt.
 *  5. Display the cards each player was dealt using their name and a message
 *      showing the card that won them the game, or if it is a tie.
 *  6. You should seed the random number generator with the system time.
 *      See it in the function or module that need it.
 *      In this case it would be in the 'Deal' method.
 *  7. return 0 at the end of the function
 *
 ********1*********2*********3*********4*********5*********6*********7*********/

#include "lab4_Card_Class_SeungYeop_Yang.cpp"
#include "lab4_Hand_Class_SeungYeop_Yang.cpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <limits>

using namespace std;

const int QUIT_GAME = 5; // const int (5) to quit the game

int displayMenu();    // display main menu
int highCard();       // game: highCard       (Lab2)
int lowCardOfThree(); // game: lowCardOfThree (Lab2, updated in Lab3)
int oneHandPoker();   // game: oneHandPoker   (Lab3)
int testHand();       // game: testHand       (Lab4)
void testHand_Prof(); // game: testHand by Professor       (Lab4)

/********1*********2*********3*********4*********5*********6*********7*********8
 *
 * Function: main
 * Inputs: none
 * Outputs: return 0 when it's successful
 * Purpose: This function is the main function of this Lab, Lab1.
 *  1. display menu and get the choice of game (If the choice is 4, then quit.)
 *  2. call highCard (if choice ==1), lowCardOfThree (2), oneHandPoker (3)
 *  3. repeat until the user wants to quit (4)
 *
 ********1*********2*********3*********4*********5*********6*********7*********/

int main()
{
    int choice; // the choice out of menu

    do {
        choice = displayMenu();

        switch (choice) {

        case 1:
            highCard();
            break;
        case 2:
            lowCardOfThree();
            break;
        case 3:
            oneHandPoker();
            break;
        case 4:
            testHand(); // my own test suite
            cout << "---------------------------------------" << endl;
            cout << "The testHand() by Professor" << endl;
            testHand_Prof();
            break;
        case QUIT_GAME:
            cout << "Thanks for playing the game. Bye!!!" << endl;
            break;
        default:
            cout << "Out of Range of the Choices; please try again." << endl;
            break;
        };

    } while (choice != QUIT_GAME);
    return 0;
}

/********1*********2*********3*********4*********5*********6*********7*********8
 *
 * Function: displayMenu
 * Inputs: none
 * Outputs: return int value from cin
 * Purpose: This function:
 *  1. displays the menu
 *  2. get the input from the user and return the value as an int
 *
 ********1*********2*********3*********4*********5*********6*********7*********/

int displayMenu()
{
    int choice;
    cout << "---------------------------------------" << endl;
    cout << "Simple Card Games" << endl;
    cout << "\t" << "1. High Card" << endl;
    cout << "\t" << "2. Low Card of Three" << endl;
    cout << "\t" << "3. One Hand Poker" << endl;
    cout << "\t" << "4. Test a hand" << endl;
    cout << "\t" << "5. Quit" << endl;

    cout << "Enter a number (1-" << QUIT_GAME << "): ";
    // Keep asking until the user enters a valid number
    while (!(cin >> choice)) {
        cout << "Invalid input. Please enter an integer: ";
        cin.clear(); // Clear the error flags
        // Discard invalid input from the buffer up to the newline character
        cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
    }
    cout << "---------------------------------------" << endl;

    return choice;
}

/********1*********2*********3*********4*********5*********6*********7*********8
 *
 * Function: highCard
 * Inputs: none
 * Outputs: return 0 if successful
 * Purpose: This function plays game: highCard
 *  1. Ask each player for their name
 *  2. generate 2 random numbers out of 1 to 13 and assign to player A and B
 *  3. based on the rank, 2<3<4<5<6<7<8<9<10<J<Q<K<Ace, decide the winner
 *  4. display whether the game is tie, player A wins or play B wins.
 *  5. return 0 at the end of the function
 *
 ********1*********2*********3*********4*********5*********6*********7*********/

int highCard()
{
    Card playerA, playerB;
    string nameA, nameB;
    int valueA, valueB;
    string faceValueA, suitNameA, faceValueB, suitNameB;

    cout << "You chose High Card Game." << endl << endl;
    cout << "What's the first player's name: ";
    // 04/13/26 replaced cin with getline to get the full name
    getline(cin >> ws, nameA);
    cout << "What's the second player's name: ";
    getline(cin >> ws, nameB);

    playerA.Deal(); // random Card value from Card.Deal()
    playerB.Deal();

    // retrieve the value
    valueA = playerA.getValue();
    valueB = playerB.getValue();

    // retrieve the string (faceValue) for the value
    playerA.getFaceValue(faceValueA, suitNameA);
    playerB.getFaceValue(faceValueB, suitNameB);

    // print out faceValues
    cout << "\t" << nameA << " got " << "(" << faceValueA << ", " << suitNameA
         << ")" << endl;
    cout << "\t" << nameB << " got " << "(" << faceValueB << ", " << suitNameB
         << ")" << endl;

    // decide who wins the game.

    if (valueA == valueB)
        cout << "\t" << "It's tie." << endl;
    else if (valueA == 1)
        cout << "\t" << nameA << " wins." << endl;
    else if (valueB == 1)
        cout << "\t" << nameB << " wins." << endl;
    else if (valueA > valueB)
        cout << "\t" << nameA << " wins." << endl;
    else
        cout << "\t" << nameB << " wins." << endl;

    return 0;
}
/********1*********2*********3*********4*********5*********6*********7*********8
 *
 * Function: lowCardOfThree
 * Inputs: none
 * Outputs: return 0 if successful
 * Purpose: This function plays game: lowCardOfThree
 *  1. Ask each of the two players for their name.
 *  2. Deal each player three cards.
 *  3. Store each player's cards in an array of Card objects.
 *  4. The winner is the player that has the lowest card of the three dealt.
 *  5. Display the cards each player was dealt using their name and a message
 *      showing the card that won them the game, or if it is a tie.
 *  6. You should seed the random number generator with the system time.
 *      See it in the function or module that need it.
 *      In this case it would be in the 'deal' method.
 *  7. return 0 at the end of the function
 *
 ********1*********2*********3*********4*********5*********6*********7*********/

int lowCardOfThree()
{
    // player names and hands
    string nameA, nameB;
    Hand handA(3), handB(3);

    // temporary variables
    string faceValueName, suitValueName;
    int cardValue, suitValue;

    // lowest values and face
    string lowestCardValueA, lowestCardValueB;
    int lowestA, lowestB;

    cout << "You chose Low Card of Three Game." << endl << endl;
    cout << "What's the first player's name: ";
    // 04/13/26 replaced cin with getline to get the full name
    getline(cin >> ws, nameA);
    cout << "What's the second player's name: ";
    getline(cin >> ws, nameB);

    handA.dealHand(); // populate the hand
    handB.dealHand();

    handA.sortHand(); // sort the hand
    handB.sortHand();

    // since sortHand() sorts the cards in ascending order considering Ace,
    // the first card has the lowest value

    cout << "\t" << nameA << " got ";
    handA.displayHand();

    cout << "\t" << nameB << " got ";
    handB.displayHand();

    // retrieve lowest CardValues from the players
    handA.getCardFaceValues(0, lowestCardValueA, suitValueName);
    handB.getCardFaceValues(0, lowestCardValueB, suitValueName);

    // retrieve lowest NumericValues from the players
    handA.getCardNumericValues(0, lowestA, suitValue);
    handB.getCardNumericValues(0, lowestB, suitValue);

    // print out
    cout << "\t" << nameA << "'s lowest is " << lowestCardValueA << endl;
    cout << "\t" << nameB << "'s lowest is " << lowestCardValueB << endl;

    // decide who wins the game.

    if (lowestA == lowestB)
        cout << "\t" << "It's tie." << endl;
    else if (lowestA == 1)
        cout << "\t" << nameB << " wins." << endl;
    else if (lowestB == 1)
        cout << "\t" << nameA << " wins." << endl;
    else if (lowestA > lowestB)
        cout << "\t" << nameB << " wins." << endl;
    else
        cout << "\t" << nameA << " wins." << endl;

    return 0;
}

/********1*********2*********3*********4*********5*********6*********7*********8
 *
 * Function: oneHandPoker
 * Inputs: name
 * Outputs: return 0 if successful
 * Purpose: This function plays game: oneHandPoker
 *  1. This game will ask each user for their name and deal a five-card hand
 *     to each of them. Each hand of cards should be displayed along with the
 *     player's name and the word values for each cards and suit.
 *     Then you will display who had the better poker hand.
 *  2. return 0 at the end of the function
 *
 ********1*********2*********3*********4*********5*********6*********7*********/

int oneHandPoker()
{
    string nameA, nameB;
    Hand handA(5), handB(5);
    // temporary variable to store poker hands and scores to compare and record
    int rankScoreA = 0, rankScoreB = 0;
    int scoreA = 0, scoreB = 0;
    int historyWinA = 0, historyWinB = 0;

    // temporary variables
    string faceValueName, suitValueName;
    int cardValue, suitValue;

    cout << "You chose One Hand Poker" << endl << endl;
    cout << "What's the first player's name: ";
    getline(cin >> ws, nameA);
    cout << "What's the second player's name: ";
    getline(cin >> ws, nameB);

    handA.dealHand(); // populate the hands
    handB.dealHand();

    handA.sortHand(); // sort the hands
    handB.sortHand();

    cout << "\t" << nameA << " got ";
    handA.displayHand();
    cout << "\t" << nameB << " got ";
    handB.displayHand();

    // build the poker hands and rank them as a relative bit position
    /**
     * +-----+-----------------+-------------------------------------------+
     * | Bit | Field Name      |  Functional Description                   |
     * +-----+-----------------+-------------------------------------------+
     * | 9   | isRoyalFlush    |  true if Royal Flush                      |
     * | 8   | isStraightFlush |  true if Straight Flush                   |
     * | 7   | isFourOfAKind   |  true if four of the same rank            |
     * | 6   | isFullHouse     |  true if FullHouse                        |
     * | 5   | isFlush         |  true if Flush                            |
     * | 4   | isStraight      |  true if Straight                         |
     * | 3   | isThreeOfAKind  |  true if there are three of the same rank |
     * | 2   | isTwoPair       |  true if there are two pairs              |
     * | 1   | isPair          |  true if there is a pair                  |
     * | 0   | isHighCard      |  true if Hand is Higher than other Hand   |
     * +-----+-----------------+-------------------------------------------+
     */
    rankScoreA = handA.buildRankScore() + handA.isHighCard(handB);
    rankScoreB = handB.buildRankScore() + handB.isHighCard(handA);

    // display the highest hand for humans
    cout << "\t" << nameA << " got " << handA.highestHand(rankScoreA) << endl;
    cout << "\t" << nameB << " got " << handB.highestHand(rankScoreB) << endl;

    // logic to choose the winner
    for (int i = 0; i < 12; i++) {
        scoreA = rankScoreA % 2;
        scoreB = rankScoreB % 2;
        if (scoreA && !scoreB) {
            historyWinA = 1;
            historyWinB = 0;
        }
        else if (!scoreA && scoreB) {
            historyWinB = 1;
            historyWinA = 0;
        }
        else {
            historyWinA = historyWinA;
            historyWinB = historyWinB;
        }
        rankScoreA >>= 1;
        rankScoreB >>= 1;
    }

    // judge the winner
    if (historyWinA == historyWinB)
        cout << "\t" << "It's tie." << endl;
    else if (historyWinA == 1)
        cout << "\t" << nameA << " wins." << endl;
    else if (historyWinB == 1)
        cout << "\t" << nameB << " wins." << endl;
    else
        cout << "\t" << "something went wrong" << endl;

    return 0;
}

/********1*********2*********3*********4*********5*********6*********7*********8
 *
 * Function: testHand
 * Inputs: none
 * Outputs: return 0 if successful
 * Purpose: No Requirements were specified in the Lab 4 Description
 *  1. I made my own test suites to validate Lab 4 requirements
 *  2. return 0 at the end of the function
 *
 ********1*********2*********3*********4*********5*********6*********7*********/
void testAllHands(Hand&);

int testHand()
{
    // cout << "You chose test a hand that's not implemented yet." << endl;
    Hand test(5);
    cout << "I made my own testHand test cases" << endl;

    // test 1. RoyalFlush
    cout << "1. isRoyalFlush(): RoyalFlush, StraightFlush, Flush, Straight"
         << endl;
    // setup RoyalFlush
    test.setCard(0, 1, 1);
    test.setCard(1, 10, 1);
    test.setCard(2, 11, 1);
    test.setCard(3, 12, 1);
    test.setCard(4, 13, 1);
    // test 1
    testAllHands(test);
    if (test.isRoyalFlush() && test.isStraightFlush() && test.isFlush() &&
        test.isStraight())
        cout << "  test 1: passed." << endl;
    else
        cout << "  test 1: failed." << endl;

    // test 2. StraightFlush
    cout << "2. isStraightFlush(): StraightFlush, Flush, Straight" << endl;
    // setup StraightFlush
    test.setCard(0, 9, 1);
    test.setCard(1, 10, 1);
    test.setCard(2, 11, 1);
    test.setCard(3, 12, 1);
    test.setCard(4, 13, 1);
    // test 2
    testAllHands(test);
    if (test.isStraightFlush() && test.isFlush() && test.isStraight())
        cout << "  test 2: passed." << endl;
    else
        cout << "  test 2: failed." << endl;

    // test 3. FourOfAKind
    cout << "3. isFourOfAKind(): FourOfAKind" << endl;
    // setup FourOfAKind
    test.setCard(0, 9, 1);
    test.setCard(1, 9, 2);
    test.setCard(2, 9, 3);
    test.setCard(3, 9, 4);
    test.setCard(4, 13, 1);
    // test 3
    testAllHands(test);
    if (test.isFourOfAKind())
        cout << "  test 3: passed." << endl;
    else
        cout << "  test 3: failed." << endl;

    // test 4. FullHouse
    cout << "4. isFullHouse(): FullHouse, ThreeOfAKind, Pair" << endl;
    // setup FullHouse
    test.setCard(0, 9, 1);
    test.setCard(1, 9, 2);
    test.setCard(2, 9, 3);
    test.setCard(3, 13, 4);
    test.setCard(4, 13, 1);
    // test 4
    testAllHands(test);
    if (test.isFullHouse())
        cout << "  test 4: passed." << endl;
    else
        cout << "  test 4: failed." << endl;

    // test 5. Flush
    cout << "5. isFlush(): Flush" << endl;
    // setup Flush
    test.setCard(0, 2, 4);
    test.setCard(1, 3, 4);
    test.setCard(2, 5, 4);
    test.setCard(3, 7, 4);
    test.setCard(4, 9, 4);
    // test 5
    testAllHands(test);
    if (test.isFlush())
        cout << "  test 5: passed." << endl;
    else
        cout << "  test 5: failed." << endl;

    // test 6. Straight
    cout << "6.a isStraight(): Straight" << endl;
    // setup Straight
    test.setCard(0, 10, 1);
    test.setCard(1, 11, 2);
    test.setCard(2, 12, 3);
    test.setCard(3, 13, 4);
    test.setCard(4, 1, 2);
    // test 6.a
    testAllHands(test);
    if (test.isStraight())
        cout << "  test 6.a: passed." << endl;
    else
        cout << "  test 6.a: failed." << endl;

    cout << "6.b isStraight(): Straight" << endl;
    // setup Straight
    test.setCard(0, 2, 1);
    test.setCard(1, 3, 2);
    test.setCard(2, 4, 3);
    test.setCard(3, 5, 4);
    test.setCard(4, 1, 2);
    // test 6.b
    testAllHands(test);
    if (test.isStraight())
        cout << "  test 6.b: passed." << endl;
    else
        cout << "  test 6.b: failed." << endl;

    cout << "6.c isStraight(): Straight" << endl;
    // setup Straight
    test.setCard(0, 2, 1);
    test.setCard(1, 3, 2);
    test.setCard(2, 4, 3);
    test.setCard(3, 5, 4);
    test.setCard(4, 6, 2);
    // test 6.c
    testAllHands(test);
    if (test.isStraight())
        cout << "  test 6.c: passed." << endl;
    else
        cout << "  test 6.c: failed." << endl;

    cout << "6.d isStraight(): Negative Test" << endl;
    // setup Straight
    test.setCard(0, 11, 1);
    test.setCard(1, 12, 2);
    test.setCard(2, 13, 3);
    test.setCard(3, 1, 4);
    test.setCard(4, 2, 2);
    // test 6.d
    testAllHands(test);
    if (test.isStraight())
        cout << "  test 6.d: failed." << endl;
    else
        cout << "  test 6.d: passed." << endl;

    // test 7. ThreeOfAKind
    cout << "7. isThreeOfAKind(): ThreeOfAKind" << endl;
    // setup ThreeOfAKind
    test.setCard(0, 1, 1);
    test.setCard(1, 1, 2);
    test.setCard(2, 1, 3);
    test.setCard(3, 2, 4);
    test.setCard(4, 3, 1);
    // test 7
    testAllHands(test);
    if (test.isThreeOfAKind())
        cout << "  test 7: passed." << endl;
    else
        cout << "  test 7: failed." << endl;

    // test 8. TwoPair
    cout << "8. isTwoPair(): TwoPair" << endl;
    // setup TwoPair
    test.setCard(0, 1, 1);
    test.setCard(1, 1, 2);
    test.setCard(2, 2, 3);
    test.setCard(3, 2, 4);
    test.setCard(4, 3, 1);
    // test 8
    testAllHands(test);
    if (test.isTwoPair())
        cout << "  test 8: passed." << endl;
    else
        cout << "  test 8: failed." << endl;

    // test 9. Pair
    cout << "9. isPair(): Pair" << endl;
    // setup Pair
    test.setCard(0, 10, 1);
    test.setCard(1, 1, 2);
    test.setCard(2, 2, 3);
    test.setCard(3, 2, 4);
    test.setCard(4, 3, 1);
    // test 9
    testAllHands(test);
    if (test.isPair())
        cout << "  test 9: passed." << endl;
    else
        cout << "  test 9: failed." << endl;

    // test 10. HighCard
    Hand other(5);
    cout << "10. isHighCard(): HighCard" << endl;
    // setup HighCard
    test.setCard(0, 10, 1);
    test.setCard(1, 1, 2);
    test.setCard(2, 2, 3);
    test.setCard(3, 4, 4);
    test.setCard(4, 5, 1);
    other.setCard(0, 13, 1);
    other.setCard(1, 6, 2);
    other.setCard(2, 2, 3);
    other.setCard(3, 4, 4);
    other.setCard(4, 5, 1);

    // test 10
    testAllHands(test);
    cout << "\t" << "isHighCard() is " << test.isHighCard(other) << endl;
    if (test.isHighCard(other))
        cout << "  test 10: passed." << endl;
    else
        cout << "  test 10: failed." << endl;

    return 0;
}

void testAllHands(Hand& test)
{
    cout << "\t" << "isRoyalFlush() is " << test.isRoyalFlush() << endl;
    cout << "\t" << "isStraightFlush() is " << test.isStraightFlush() << endl;
    cout << "\t" << "isFourOfAKind() is " << test.isFourOfAKind() << endl;
    cout << "\t" << "isFullHouse() is " << test.isFullHouse() << endl;
    cout << "\t" << "isFlush() is " << test.isFlush() << endl;
    cout << "\t" << "isStraight() is " << test.isStraight() << endl;
    cout << "\t" << "isThreeOfAKind() is " << test.isThreeOfAKind() << endl;
    cout << "\t" << "isTwoPair() is " << test.isTwoPair() << endl;
    cout << "\t" << "isPair() is " << test.isPair() << endl;
}

void testHand_Prof()
{
    Hand testHand(5);
    int value, suit;
    string cardFace, cardSuit;

    cout << "\nTest Hand\n";

    /* missing the init of suit*/
    suit = 4;

    testHand.setCard(0, 9, suit);
    testHand.setCard(1, 9, suit);
    testHand.setCard(2, 11, suit);
    testHand.setCard(3, 12, suit);
    testHand.setCard(4, 11, suit);

    for (int i = 0; i < testHand.getNumCards(); i++) {
        testHand.getCardFaceValues(i, cardFace, cardSuit);
        cout << "   " << cardFace << " of " << cardSuit << endl;
    }
    cout << endl;

    cout << "is royal flush: " << testHand.isRoyalFlush() << endl;
    cout << "is straight flush " << testHand.isStraightFlush() << endl;
    cout << "is four of a kind " << testHand.isFourOfAKind() << endl;
    cout << "is full house " << testHand.isFullHouse() << endl;
    cout << "is flush: " << testHand.isFlush() << endl;
    cout << "is straight: " << testHand.isStraight() << endl;
    cout << "is three of a kind " << testHand.isThreeOfAKind() << endl;
    cout << "is two pair " << testHand.isTwoPair() << endl;
    cout << "is pair " << testHand.isPair() << endl;
    // cout << "is high card " << testHand.isHighCard() << endl;
    // commented out isHighCard since the method is not comparing
    // Definiton provided:
    //      Hands are ranked by "comparing" the highest value card.
}

/********1*********2*********3*********4*********5*********6*********7*********8
 *
 * Seung Yeop Yang
 * Lab 4: "Dynamic memory and recursion"
 *
 * End Of Program
 ********1*********2*********3*********4*********5*********6*********7*********/
