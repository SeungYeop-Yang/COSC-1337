#include <fstream>
#include <iomanip>
#include <iostream>

using namespace std;

class Friend {
private:
    string name;
    int age;
    string favoriteFood;

public:
    Friend();
    Friend(string, int, string);

    void setName(string);
    void setAge(int);
    void setFavoriteFood(string);

    string getName();
    int getAge();
    string getFavoriteFood();

    bool operator>(Friend& rightHandSide);
};

Friend::Friend()
{
    name = "";
    age = 0;
    favoriteFood = "";
}
Friend::Friend(string n, int a, string f)
{
    name = n;
    age = a;
    favoriteFood = f;
}

void Friend::setName(string n) { name = n; }
void Friend::setAge(int a) { age = a; }
void Friend::setFavoriteFood(string f) { favoriteFood = f; }

string Friend::getName() { return name; }
int Friend::getAge() { return age; }
string Friend::getFavoriteFood() { return favoriteFood; }

bool Friend::operator>(Friend& rightHandSide)
{
    return name > rightHandSide.getName();
}

void readFriends(Friend[], int&);
int getMenuOption();
void displayFriends(Friend[], int);
void addFriend(Friend pals[], int& count);
void removeFriend(Friend[], int&);
void sortFriends(Friend amigos[], int count);
void editFriend(Friend bears[], int& count);
void doEdit(Friend* oneFriend);

const int MAX_FRIENDS = 10;

int main()
{
    Friend friends[MAX_FRIENDS];
    int choice;
    int numFriends;

    choice = getMenuOption();
    while (choice != 7) {
        switch (choice) {
        case 1: // Read friends
            readFriends(friends, numFriends);
            break;
        case 2: // Add friend
            addFriend(friends, numFriends);
            break;
        case 3: // Remove friend
            removeFriend(friends, numFriends);
            break;
        case 4: // Display friends
            displayFriends(friends, numFriends);
            break;
        case 5: // Sort friends
            sortFriends(friends, numFriends);
            break;
        case 6: // Edit Friend
            editFriend(friends, numFriends);
        }
        choice = getMenuOption();
    }
    return 0;
}

int getMenuOption()
{
    int option;

    cout << "\n   MENU\n";
    cout << "1. Read friends\n"
         << "2. Add a friend\n"
         << "3. Remove a friend\n"
         << "4. Display friends\n"
         << "5. Sort friends\n"
         << "6. Edit a Friend\n"
         << "7. Quit\n";
    cout << "Enter option: ";
    cin >> option;

    // zzz add input validation

    return option;
}

void readFriends(Friend buddies[], int& count)
{
    ifstream friendsFile;
    string name, food;
    int age;
    int index = 0;

    friendsFile.open("friends.txt");

    if (friendsFile) {
        while (getline(friendsFile, name)) {
            friendsFile >> age;
            friendsFile.ignore(100, '\n');
            getline(friendsFile, food);

            // Store the record in the array
            buddies[index].setName(name);
            buddies[index].setAge(age);
            buddies[index].setFavoriteFood(food);

            index++;
        }
        cout << "Friends have been read\n";
        count = index;

        friendsFile.close();
    }
    else
        cout << "friendsFile could not be opened\n";
}

void displayFriends(Friend chums[], int count)
{

    cout << left << setw(35) << "Name" << left << setw(8) << "Age"
         << "Favorite Food\n";

    for (int i = 0; i < count; i++)
        cout << left << setw(35) << chums[i].getName() << left << setw(8)
             << chums[i].getAge() << chums[i].getFavoriteFood() << endl;
}

void addFriend(Friend pals[], int& count)
{
    string name, food;
    int age;

    if (count < MAX_FRIENDS) {
        cout << "Add a Friend\n";
        cout << "Enter name: ";
        cin.ignore(100, '\n');
        getline(cin, name);
        cout << "Age: ";
        cin >> age;
        cin.ignore(100, '\n');
        cout << "Favorite food: ";
        getline(cin, food);

        pals[count].setName(name);
        pals[count].setAge(age);
        pals[count].setFavoriteFood(food);

        cout << name << "has been added\n";
        count++;
    }
    else
        cout << "You have the maximum number of friends allowed";
}

void removeFriend(Friend peeps[], int& count)
{
    string name;
    int foundIndex = -1;

    cout << "\n\nRemove Friend\n";
    cin.ignore(100, '\n');
    cout << "Enter friend to remove: ";
    getline(cin, name);

    for (int i = 0; foundIndex < 0 && i < count; i++) {
        if (name == peeps[i].getName())
            foundIndex = i;
    }

    if (foundIndex >= 0) {

        count--;
        peeps[foundIndex] = peeps[count];
    }
}

void sortFriends(Friend amigos[], int count)
{
    bool swapped = true;
    Friend tempFriend;

    cout << "\n\nSorting friends by favorite food...\n";

    while (swapped) {
        swapped = false;
        for (int i = 0; i < count - 1; i++) {
            // if (amigos[i].getFavoriteFood() > amigos[i +
            // 1].getFavoriteFood()) {
            if (amigos[i] > amigos[i + 1]) {
                tempFriend = amigos[i];
                amigos[i] = amigos[i + 1];
                amigos[i + 1] = tempFriend;
                swapped = true;
            }
        }
    }

    cout << "Friends have been sorted\n";
}

void editFriend(Friend bears[], int& count)
{
    string name;
    int foundIndex = -1;

    cout << "\n\nEdit a Friend\n";
    cin.ignore(100, '\n');
    cout << "Enter friend to remove: ";
    getline(cin, name);

    for (int i = 0; foundIndex < 0 && i < count; i++) {
        if (name == bears[i].getName())
            foundIndex = i;
    }

    if (foundIndex >= 0) {

        doEdit(&bears[foundIndex]);
        cout << name << "has been edited\n";
    }
    else
        cout << name << "was not found\n";
}

void doEdit(Friend* oneFriend)
{
    string name;
    int age;
    string food;

    int option;
    do {
        cout << "\nEdit Menu\n";
        cout << "1. Name\n";
        cout << "2. Age\n";
        cout << "3. Favorite food\n";
        cout << "4. Done editing\n";
        cout << "Enter field to edit: ";
        cin >> option;

        switch (option) {
        case 1:
            cout << "Enter new name: ";
            getline(cin >> ws, name);
            // set name in object
            oneFriend->setName(name);
            break;
        case 2:
            cout << "Enter new age: ";
            cin >> age;
            // set name in object
            oneFriend->setAge(age);
            break;
        case 3:
            cout << "Enter new Favorite food: ";
            getline(cin >> ws, food);
            // set name in object
            oneFriend->setFavoriteFood(food);
            break;
        case 4:
            break;
        }

    } while (option != 4);
}
