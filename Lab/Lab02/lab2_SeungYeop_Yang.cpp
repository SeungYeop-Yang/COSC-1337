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
 *      a. Default constructor that initialized value and suit to -1 ?
 *      b. Deal
 *          - generates and assigns a value between 1 and 13,
 *          - and a suit between 1 and 4
 *          - this is the module where you should seed ?
 *      ////////////////////////////////////////////////////////////////////////
 *      Disagree if we seed with the classic time() based seed.
 *      Will try to find alternatives from the modern c++11 or later.
 *      ////////////////////////////////////////////////////////////////////////
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
 *      In this case it would be in the 'deal' method.
 *      ////////////////////////////////////////////////////////////////////////
 *      Disagree if we seed with the classic time() based seed.
 *      Will try to find alternatives from the modern c++11 or later.
 *      ////////////////////////////////////////////////////////////////////////
 *  7. return 0 at the end of the function
 *
 ********1*********2*********3*********4*********5*********6*********7*********/

#include "lab2_Card_Class_SeungYeop_Yang.cpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <limits>
using namespace std;

const int QUIT_GAME = 4; // const int (4) to quit the game

int displayMenu();    // display main menu
int highCard();       // game: highCard       (Lab2)
int lowCardOfThree(); // game: lowCardOfThree (Lab2)
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
    // version 03/06/26
    // srand(static_cast<unsigned int>(time(NULL))); // seed for rand()
    // replaced the classic standard practice with the new c++11 seeding
    // in the 'deal' method of the class Card

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
 * Function: strCard
 * Inputs: int of Ace(1) to King(13)
 * Outputs: return of string card name
 * Purpose: This function:
 *  1. get the Card value as input
 *  2. return the card name as string based on the input value
 *
 ********1*********2*********3*********4*********5*********6*********7*********/

string strCard(int card)
{
    string cardName;
    switch (card) {
    case 1:
        cardName = "Ace";
        break;
    case 2:
        cardName = "Two";
        break;
    case 3:
        cardName = "Three";
        break;
    case 4:
        cardName = "Four";
        break;
    case 5:
        cardName = "Five";
        break;
    case 6:
        cardName = "Six";
        break;
    case 7:
        cardName = "Seven";
        break;
    case 8:
        cardName = "Eight";
        break;
    case 9:
        cardName = "Nine";
        break;
    case 10:
        cardName = "Ten";
        break;
    case 11:
        cardName = "Jack";
        break;
    case 12:
        cardName = "Queen";
        break;
    case 13:
        cardName = "King";
        break;
    default:
        cout << "It should not happen." << endl;
        break;
    }
    return cardName;
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

    cout << "You chose High Card Game." << endl << endl;
    cout << "What's the first player's name: ";
    cin >> nameA;
    cout << "What's the second player's name: ";
    cin >> nameB;

    playerA.Deal();
    playerB.Deal();

    valueA = playerA.getValue();
    valueB = playerB.getValue();

    cout << "\t" << nameA << " got " << strCard(valueA) << endl;
    cout << "\t" << nameB << " got " << strCard(valueB) << endl;

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

    const int SIZE_CARD = 3;

    Card playerA[SIZE_CARD], playerB[SIZE_CARD];
    string nameA, nameB;
    int valueA, valueB;

    cout << "You chose Low Card of Three Game." << endl << endl;
    cout << "What's the first player's name: ";
    cin >> nameA;
    cout << "What's the second player's name: ";
    cin >> nameB;

    for (int i = 0; i < SIZE_CARD; i++) {
        playerA[i].Deal();
        playerB[i].Deal();
    }

    valueA = playerA[0].getValue();
    valueB = playerB[0].getValue();

    for (int i = 1; i < SIZE_CARD; i++) {
        if (valueA == 1)
            valueA = playerA[i].getValue();
        else if (playerA[i].getValue() == 1)
            ;
        else if (valueA > playerA[i].getValue())
            valueA = playerA[i].getValue();
        else
            ;
    }

    for (int i = 1; i < SIZE_CARD; i++) {
        if (valueB == 1)
            valueB = playerB[i].getValue();
        else if (playerB[i].getValue() == 1)
            ;
        else if (valueB > playerB[i].getValue())
            valueB = playerB[i].getValue();
        else
            ;
    }

    cout << "\t" << nameA << " got ";
    for (int i = 0; i < SIZE_CARD; i++) {
        cout << strCard(playerA[i].getValue()) << " ";
    }
    cout << endl;
    cout << "\t" << nameB << " got ";
    for (int i = 0; i < SIZE_CARD; i++) {
        cout << strCard(playerB[i].getValue()) << " ";
    }
    cout << endl;

    cout << "\t" << nameA << "'s lowest is " << strCard(valueA) << endl;
    cout << "\t" << nameB << "'s lowest is " << strCard(valueB) << endl;

    if (valueA == valueB)
        cout << "\t" << "It's tie." << endl;
    else if (valueA == 1)
        cout << "\t" << nameB << " wins." << endl;
    else if (valueB == 1)
        cout << "\t" << nameA << " wins." << endl;
    else if (valueA > valueB)
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
 * Lab 2: "Classes, Arrays"
 *
 * End Of Program
 ********1*********2*********3*********4*********5*********6*********7*********/
