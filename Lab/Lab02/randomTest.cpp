/*******************************/
/* Testing the rand function   */
/*******************************/

#include <chrono>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <thread>

using namespace std;

int main()
{
    int values1[3], values2[3];

    for (int times = 1; times <= 10; times++) {
        cout << "\n\nTimes = " << times << endl;
        // Assign random ints between 1 and 100
        for (int i = 0; i < 10; i++) {
            // Seed the random number generator
            cout << "time(0) returns " << time(0) << endl;
            srand((unsigned)time(0));
            values1[i] = (rand() % 13) + 1;
            // cout << "assigned values1 " << values1[i] << endl;
        }

        // Display values
        cout << "values1:\n";
        for (int i = 0; i < 3; i++)
            cout << values1[i] << " ";
        cout << endl;

        // Assign random ints between 1 and 100
        for (int i = 0; i < 3; i++) {
            // Seed the random number generator
            cout << "time(0) returns " << time(0) << endl;
            srand((unsigned)time(0));
            values2[i] = (rand() % 13) + 1;
            // cout << "assigned values2 " << values2[i] << endl;
        }
        // Display values
        cout << "\nvalues2:\n";
        for (int i = 0; i < 3; i++)
            cout << values2[i] << " ";
        cout << endl;

        cout << "\nPress <enter> to continue... ";
        cin.get();
    }

    return 0;

} // end main
