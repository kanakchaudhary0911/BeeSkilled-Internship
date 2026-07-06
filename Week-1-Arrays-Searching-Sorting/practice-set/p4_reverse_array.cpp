#include <iostream>
#include <algorithm>   // For swap()
using namespace std;

/*
PRACTICE 4: Reverse an Array

Objective:
- Input an array of elements.
- Reverse the array using the two-pointer technique.
- Display both the original and reversed arrays.

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

    cout << "\nOriginal Array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    int left = 0;
    int right = n - 1;

    while (left < right)
    {
        swap(arr[left], arr[right]);
        left++;
        right--;
    }

    cout << "\nReversed Array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;

    return 0;
}