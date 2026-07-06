#include <iostream>
using namespace std;

/*
PRACTICE 3: Find Minimum and Maximum

Objective:
- Input an array of numbers.
- Find the smallest and largest elements.
- Display the minimum and maximum values.

Time Complexity: O(n)
Space Complexity: O(1)
*/

int main()
{
    int n;

    cout << "Enter the number of elements: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Invalid array size!" << endl;
        return 0;
    }

    int arr[100];

    cout << "Enter the array elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int minValue = arr[0];
    int maxValue = arr[0];

    for (int i = 1; i < n; i++)
    {
        if (arr[i] < minValue)
        {
            minValue = arr[i];
        }

        if (arr[i] > maxValue)
        {
            maxValue = arr[i];
        }
    }

    cout << "\nMinimum Element: " << minValue << endl;
    cout << "Maximum Element: " << maxValue << endl;

    return 0;
}