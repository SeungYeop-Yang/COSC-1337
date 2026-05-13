/********************************************************/
/* Lab 2 Solution                                       */
/* This program plays some lame card games.             */
/*                                                      */
/* It will be implemented in stages.                    */
/* This stage has the following optiions implemented:   */
/*       1. High card                                   */
/*       2. Low card of three                           */
/*       3. One hand poker (stub only)                  */
/*       4. Quit                                        */
/*                                                      */
/********************************************************/

#include <iostream>
#include <iomanip>
#include <thread>
#include <chrono>
#include "classCard.cpp"

using namespace std;

// Function prototypes
int getValidMenuOption();
void highCard();
void lowCardOfThree();
string getFaceValue(int);
void oneHandPoker();

const int QUIT = 4;

int main()
{
    // Variable Declarations
    int option;

	// Get the first option
    option = getValidMenuOption();

    // Continue to display the main menu
    // until user chooses to quit
    while (option != QUIT)
    {
    	switch (option)
    	{
    		case 1:
    			// High card option
    			highCard();
    			break;
    		case 2:
    			// Low card of 5
    			lowCardOfThree();
    			break;
    		case 3:
    			// One hand poker option
    			oneHandPoker();
    			break;
    	}

    	// Get the next option
    	option = getValidMenuOption();

    } // end while option is not quit

} // end main

/*****************************************************/
/* Function:   getMainMenuOption                     */
/* Inputs:     none                                  */
/* Outputs:    a valid user option                   */
/* Purpose:    This function displays a menu, reads  */
/*             the user's option, validates          */
/*             and returns it.                       */
/*             Menu options:                         */
/*             1. High card                          */
/*             2. Quit                               */
/*****************************************************/
int getValidMenuOption()
{
	// Variable Declarations
    int option;

	do
	{
	    // Display main menu
	    cout << "\n*************\n";
	    cout << "Main Menu\n"
	         << "-----------\n"
		     << "1. High card\n"
		     << "2. Low card of three\n"
		     << "3. One hand poker\n"
	         << "4. Quit\n";

	    // Read the first option
	    cout << "Option: ";
	    cin >> option;

	    // Display error message for invalid options
	    if ((option < 1) || (option > QUIT))
			cout << "Invalid option\n\n";

	} while ((option < 1) || (option > QUIT));

	return option;

} // end getValidMenuOption()



/******************************************************/
/* Function:   highCard                               */
/* Inputs:     none                                   */
/* Outputs:    none                                   */
/* Purpose:    This function deals two cards for      */
/*             two players and displays which is      */
/*             the highest - Ace is high              */
/*             The suit does not matter for this game */
/******************************************************/
void highCard()
{
	// Variable declarations
	string player1, player2;
	Card card1, card2;
	string faceValue1, faceValue2;

	// Get past the newline from reading the menu option
	cin.ignore(100, '\n');

	cout << "\nHigh Card\n";
    cout << "---------\n\n";

	// Get player names and deal the cards
	cout << "Player 1 - what is your name? ";
	getline(cin, player1);
    card1.deal();

    cout << "Player 2 - what is your name? ";
	getline(cin, player2);
	card2.deal();

	// Get the face value of each card for display
	faceValue1 = getFaceValue(card1.getValue());
	faceValue2 = getFaceValue(card2.getValue());

    // Display cards
    cout << "\nCards have been drawn:\n";
    cout << player1 << " drew a " << faceValue1 << endl;
    cout << player2 << " drew a " << faceValue2 << endl;
    cout << endl;

    // Evaluate cards starting with a draw and display winner
    if(card1.getValue() == card2.getValue())
    	cout << "Neither player wins; it was a draw\n";
    else if (card1.getValue() > card2.getValue() || card1.getValue() == 1)
    	cout << player1 << " wins with a " << faceValue1 << endl;
    else
    	cout << player2 << " wins with a " << faceValue2 << endl;

} // end highCard()

/**********************************************************/
/* Function:   getFaceValue                               */
/* Inputs:     numeric value of a playing card            */
/* Outputs:    face value of the card as a string         */
/* Purpose:    This function converts the numeric value   */
/*             of a card to its corresponding word value  */
/**********************************************************/
string getFaceValue(int cardValue)
{
	string faceValue[] = {"Joker", "Ace", "Two", "Three", "Four", "Five",
	                      "Six", "Seven", "Eight", "Nine", "Ten", "Jack",
						  "Queen", "King"};

	return faceValue[cardValue];
}

/*******************************************************/
/* Function:   lowCardOfThree                          */
/* Inputs:     none                                    */
/* Outputs:    none                                    */
/* Purpose:    This function deals five cards to each  */
/*             of the two players and displays who has */
/*             the lowest card in their 5 cards dealt  */
/*             - Ace is high                           */
/*             The suit does not matter for this game  */
/*******************************************************/
void lowCardOfThree()
{
	// Variable declarations
	string player1, player2;
	Card cards1[3], cards2[3];
	string faceValue1, faceValue2;
	int lowCardValue1, lowCardValue2;

	// Get past the newline from reading the menu option
	cin.ignore(100, '\n');

	cout << "\nLow Card of Three\n";
    cout << "-----------------\n\n";

	// Get player names and deal the cards
	cout << "Player 1 - what is your name? ";
	getline(cin, player1);
	for(int i=0; i<3; i++)
	{
		cout << "Dealing card " << i+1 << endl;
		this_thread::sleep_for(chrono::seconds(1));
    	cards1[i].deal();
    }


    cout << "\nPlayer 2 - what is your name? ";
	getline(cin, player2);
	for(int i=0; i<3; i++)
	{
		cout << "Dealing card " << i+1 << endl;
		this_thread::sleep_for(chrono::seconds(1));
    	cards2[i].deal();
    }

    // Display cards
    cout << "\nCards have been dealt:\n";
    cout << player1 << " was dealt:\n";
	for(int i=0; i<3; i++)
		cout << "   " << getFaceValue(cards1[i].getValue()) << " ";

	cout << endl << endl << player2 << " was dealt:\n";
	for(int i=0; i<3; i++)
    	cout << "   " << getFaceValue(cards2[i].getValue()) << " ";
    cout << endl << endl;

    // Find lowest card for player 1
    lowCardValue1 = cards1[0].getValue();
    for(int i=1; i<3; i++)
    	if (lowCardValue1 == 1  ||
		   (cards1[i].getValue() != 1 && cards1[i].getValue() < lowCardValue1))
    		lowCardValue1 = cards1[i].getValue();

    // Find lowest card for player 2
    lowCardValue2 = cards2[0].getValue();
    for(int i=1; i<3; i++)
    	if (lowCardValue2 == 1 ||
		   (cards2[i].getValue() != 1 && cards2[i].getValue() < lowCardValue2))
    		lowCardValue2 = cards2[i].getValue();

	// Evaluate cards starting with a draw and display winner
	if (lowCardValue1 == lowCardValue2)
    	cout << "Neither player wins; it was a draw both having a "
		     << getFaceValue(lowCardValue1) << endl;
    else if ((lowCardValue1 < lowCardValue2 && lowCardValue1 != 1) ||
	         (lowCardValue2 == 1))
    	cout << player1 << " wins with a " << getFaceValue(lowCardValue1) << endl;
    else
    	cout << player2 << " wins with a " << getFaceValue(lowCardValue2) << endl;
}

/*****************************************************/
/* Function:   oneHandPoker                          */
/* Inputs:     none                                  */
/* Outputs:    none                                  */
/* Purpose:    This just a stub placeholder          */
/*****************************************************/
void oneHandPoker()
{
	cout << "\nOne hand poker is coming soon\n";
}
