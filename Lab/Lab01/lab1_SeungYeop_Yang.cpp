/********1*********2*********3*********4*********5*********6*********7*********8
 *
 * Seung Yeop Yang
 * Lab 1: "Decisions, Loops, Functions" Solution
 * This program
 *
 * You will have a menu driven program that allows the user to play game
 *
 * 1. with options:
 *  a) High Card
 *  b) Low Card of Three
 *  c) One hand poker
 *  d) Quit
 * 2. Your program should continue display the menu and let the user choose
 *  options until they choose the option to quit.
 * 3. You will start with the "High Card" option and write fuction stubs for
 *  the other options.
 * 4. The main should call a function that plays high card when the user
 *  chooses option 1. The high card function should generate a random number
 *  between 1 (ace) and 13 (king) for each of the two players. The function
 *  should display each player's card and who wins or if it is a tie.
 * 5. You will need to find in your book where it discusses the function to
 *  generate a random number and how to use it (Ch 3).
 * 6. Your program should have at least two functions - main and highCard.
 *  You may have other functions if you think the program should have any.
 *
 *
 ********1*********2*********3*********4*********5*********6*********7*********/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>
using namespace std;

const int QUIT_GAME = 4; // const int (4) to quit the game

enum Cards // enum Cards definition: Ace=1, Card_2=2, ... K=13
{
    Ace = 1,
    Card_2,
    Card_3,
    Card_4,
    Card_5,
    Card_6,
    Card_7,
    Card_8,
    Card_9,
    Card_10,
    J,
    Q,
    K
};

int displayMenu();         // display main menu
int randomNumber1_to_13(); // return random number out of 1-13
int highCard();            // game: highCard       (Lab1)
int lowCardOfThree();      // game: lowCardOfThree (TBD)
int oneHandPoker();        // game: oneHandPoker   (TBD)

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
    int choice;                                   // the choice out of menu
    srand(static_cast<unsigned int>(time(NULL))); // seed for rand()

    do
    {
        choice = displayMenu();

        switch (choice)
        {

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
    while (!(cin >> choice))
    {
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
 * Function: randomNumber1_to_13
 * Inputs: none
 * Outputs: return int number out of 1 to 13
 * Purpose: This function:
 *  1. generates random number out of 1 to 13
 *  2. return the random int number
 *
 ********1*********2*********3*********4*********5*********6*********7*********/
int randomNumber1_to_13()
{
    return ((rand() % 13) + 1);
}

/********1*********2*********3*********4*********5*********6*********7*********8
 *
 * Function: strCard
 * Inputs: enum Cards of Ace to K
 * Outputs: return of string card name
 * Purpose: This function:
 *  1. get the enum Cards value as input
 *  2. return the card name as string based on the input value
 *
 ********1*********2*********3*********4*********5*********6*********7*********/
string strCard(Cards card)
{
    string cardName;
    switch (card)
    {
    case Ace:
        cardName = "Ace";
        break;
    case Card_2:
        cardName = "2";
        break;
    case Card_3:
        cardName = "3";
        break;
    case Card_4:
        cardName = "4";
        break;
    case Card_5:
        cardName = "5";
        break;
    case Card_6:
        cardName = "6";
        break;
    case Card_7:
        cardName = "7";
        break;
    case Card_8:
        cardName = "8";
        break;
    case Card_9:
        cardName = "9";
        break;
    case Card_10:
        cardName = "10";
        break;
    case J:
        cardName = "J";
        break;
    case Q:
        cardName = "Q";
        break;
    case K:
        cardName = "K";
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
 *  1. generate 2 random numbers out of 1 to 13 and assign to player A and B
 *  2. based on the rank, 2<3<4<5<6<7<8<9<10<J<Q<K<Ace, decide the winner
 *  3. display whether the game is tie, player A wins or play B wins.
 *  4. return 0 at the end of the function
 *
 ********1*********2*********3*********4*********5*********6*********7*********/
int highCard()
{
    Cards playerA, playerB;

    playerA = static_cast<Cards>(randomNumber1_to_13());
    playerB = static_cast<Cards>(randomNumber1_to_13());

    cout << "You chose High Card Game." << endl
         << endl;
    cout << "\t" << "Player A got " << strCard(playerA) << endl;
    cout << "\t" << "Player B got " << strCard(playerB) << endl
         << endl;

    if (playerA == playerB)
        cout << "\t" << "It's tie." << endl;
    else if (playerA == Ace)
        cout << "\t" << "Play A wins." << endl;
    else if (playerB == Ace)
        cout << "\t" << "Play B wins." << endl;
    else if (playerA > playerB)
        cout << "\t" << "Play A wins." << endl;
    else
        cout << "\t" << "Play B wins." << endl;

    return 0;
}

/********1*********2*********3*********4*********5*********6*********7*********8
 *
 * Function: lowCardOfThree
 * Inputs: none
 * Outputs: return 0 if successful
 * Purpose: This function plays game: lowCardOfThree
 *  1. TBD
 *  2. return 0 at the end of the function
 *
 ********1*********2*********3*********4*********5*********6*********7*********/
int lowCardOfThree()
{
    cout << "You chose lowCardOfThree that's not implemented yet." << endl;
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
 * Lab 1: "Decisions, Loops, Functions" Solution
 *
 * End Of Program
 ********1*********2*********3*********4*********5*********6*********7*********/
