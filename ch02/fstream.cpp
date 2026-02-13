#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    ofstream outFile;
    ifstream inFile;
    string name;

    outFile.open("names.txt");

    outFile << "Clovis Bagwell\n";
    outFile << "Archibald Beechcroft\n";

    outFile.close();

    cout << "File has been written\n";

    inFile.open("names.txt");

    // getline(inFile, name);
    // cout << name << endl;
    // getline(inFile, name);
    // cout << name << endl;

    if (inFile)
    {
        while (getline(inFile, name))
            cout << name << endl;
    }

    inFile.close();

    return 0;
}
