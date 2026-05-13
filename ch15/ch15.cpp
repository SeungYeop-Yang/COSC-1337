#include <iostream>
using namespace std;

int binarySearch(int[], int, int, int);
int binarySearchIterative(int[], int, int);

int main()
{
    int numbers[10] = {120, 123, 141, 148, 159, 162, 169, 177, 182, 195};
    int num;
    int result;

    cout << "Enter an integer between 100 and 200: ";
    cin >> num;

    result =
        binarySearch(numbers, num, 0, (sizeof(numbers) / __SIZEOF_INT__) - 1);

    if (result == -1)
        cout << num << " was not found\n";
    else
        cout << num << " was found at index " << result << endl;

    result =
        binarySearchIterative(numbers, num, (sizeof(numbers) / __SIZEOF_INT__));

    if (result == -1)
        cout << num << " was not found\n";
    else
        cout << num << " was found at index " << result << endl;

    return 0;
}

int binarySearch(int values[], int target, int first, int last)
{
    int mid;

    cout << target << " " << first << " " << last << " " << endl;
    if (first > last)
        return -1;
    mid = (first + last) / 2;
    if (values[mid] == target)
        return mid;

    if (values[mid] > target)
        return binarySearch(values, target, first, mid - 1);
    else
        return binarySearch(values, target, mid + 1, last);
}

int binarySearchIterative(int values[], int target, int size)
{
    int mid, first, last, result;
    bool found = false;

    first = 0;
    last = size - 1;

    while (first <= last && !found) {
        mid = (first + last) / 2;
        if (first > last) {
            result = -1;
            found = true;
        }
        else if (values[mid] == target) {
            result = mid;
            found = true;
        }
        else if (values[mid] > target)
            last = mid - 1;
        else
            first = mid + 1;

        cout << target << " " << first << " " << last << " " << mid << " "
             << found << endl;
    }

    return result;
}
