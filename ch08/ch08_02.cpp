#include <iostream>

using namespace std;

void displayGrades(int testGrades[][2]);

int main()
{
    int grades[3][2];
    int grade;

    for (int student = 0; student < 3; student++)
        for (int test = 0; test < 2; test++) {
            cout << "Enter grade: ";
            cin >> grade;

            grades[student][test] = grade;
        }

    displayGrades(grades);

    return 0;
}

void displayGrades(int testGrades[][2])
{
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++)
            cout << testGrades[i][j] << ' ';
        cout << endl;
    }
}
