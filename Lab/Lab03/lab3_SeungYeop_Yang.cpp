/********1*********2*********3*********4*********5*********6*********7*********8
 *
 * Seung Yeop Yang
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

#include "lab3_Card_Class_SeungYeop_Yang.cpp"
#include "lab3_Hand_Class_SeungYeop_Yang.cpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <limits>

using namespace std;

const int QUIT_GAME = 4; // const int (4) to quit the game

int displayMenu();    // display main menu
int highCard();       // game: highCard       (Lab2)
int lowCardOfThree(); // game: lowCardOfThree (Lab2, updated in Lab3)
int oneHandPoker();   // game: oneHandPoker   (TBD)

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
    cout << "\t" << "4. Quit" << endl;

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
    cout << "\t" << nameA << " got " << faceValueA << endl;
    cout << "\t" << nameB << " got " << faceValueB << endl;

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
    Hand handA, handB;

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

    cout << "\t" << nameA << " got ";
    for (int i = 0; i < handA.getNumCards(); i++) {
        handA.getCardFaceValues(i, faceValueName, suitValueName);
        cout << faceValueName << " ";
    }
    cout << endl;
    cout << "\t" << nameB << " got ";
    for (int i = 0; i < handB.getNumCards(); i++) {
        handB.getCardFaceValues(i, faceValueName, suitValueName);
        cout << faceValueName << " ";
    }
    cout << endl;

    handA.sortHand(); // sort the hand
    handB.sortHand();

    // since sortHand() sorts the cards in ascending order considering Ace,
    // the first card has the lowest value

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
 * Inputs: none
 * Outputs: return 0 if successful
 * Purpose: This function plays game: oneHandPoker
 *  1. TBD
 *  2. return 0 at the end of the function
 *
 ********1*********2*********3*********4*********5*********6*********7*********/

int oneHandPoker()
{
    cout << "You chose oneHandPoker that's not implemented yet." << endl;
    return 0;
}

/********1*********2*********3*********4*********5*********6*********7*********8
 *
 * Seung Yeop Yang
 * Lab 3: "Strings, sorting"
 *
 * End Of Program
 ********1*********2*********3*********4*********5*********6*********7*********/
