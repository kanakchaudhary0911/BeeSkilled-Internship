#include <iostream>
#include <algorithm>   // For swap()
using namespace std;

/*
ASSIGNMENT 4: Reverse Array In-Place

- Reverses the array without using any extra array.
- Uses the two-pointer technique (left and right).
- Time Complexity: O(n)
- Space Complexity: O(1)
*/

void reverseArray(int arr[], int n)
{
    int left = 0;
    int right = n - 1;

    while (left < right)
    {
        swap(arr[left], arr[right]);
        left++;
        right--;
    }
}

int main()
{
    int n;

    cout << "Enter the number of elements: ";
    cin >> n;

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

    reverseArray(arr, n);

    cout << "\nReversed Array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;

    return 0;
}