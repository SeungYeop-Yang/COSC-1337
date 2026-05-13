#include "lab2_Card_Class_professor.cpp"
#include <iostream>
#include <string>

using namespace std;

string getFaceValue(int cardValue)
{
    string faceValue[] = {"Joker", "Ace",  "Two",   "Three", "Four",
                          "Five",  "Six",  "Seven", "Eight", "Nine",
                          "Ten",   "Jack", "Queen", "King"};

    return faceValue[cardValue];
}

void highCard()
{
    Card card1, card2;
    string player1, player2;
    string faceValue1, faceValue2;

    cout << "\nHigh Card\n\n";

    cout << "Player 1 name: ";
    getline(cin, player1);
    card1.deal();

    cout << "Player 2 name: ";
    getline(cin, player2);
    card2.deal();

    faceValue1 = getFaceValue(card1.getValue());
    faceValue2 = getFaceValue(card2.getValue());

    cout << "Cards have been drawn:\n";

    cout << player1 << " drew a " << faceValue1 << endl;
    cout << player2 << " drew a " << faceValue2 << endl;
    cout << endl;
}

void lowCardOfThree()
{
    Card cards1[3], cards2[3];
    string player1, player2;
    int lowCardValue1, lowCardValue2;

    cout << "\nLow Card of Three\n\n";

    // cin.ignore(100, '\n');
    cout << "Player 1 name: ";
    getline(cin, player1);

    for (int i = 0; i < 3; i++) {
        cards1[i].deal();
    }

    cout << "Player 2 name: ";
    getline(cin, player2);

    for (int i = 0; i < 3; i++) {
        cards2[i].deal();
    }

    cout << player1 << " was dealt: \n";
    for (int i = 0; i < 3; i++) {
        cout << "     " << getFaceValue(cards1[i].getValue()) << endl;
    }
    cout << player2 << " was dealt: \n";
    for (int i = 0; i < 3; i++) {
        cout << "     " << getFaceValue(cards2[i].getValue()) << endl;
    }
}

int main()
{
    lowCardOfThree();
    return 0;
}
