#include <iostream>
using namespace std;

/*
ASSIGNMENT 2: Binary Search

- Binary Search works only on a sorted array.
- It repeatedly divides the search space into two halves.
- Time Complexity: O(log n)
*/

int binarySearch(int arr[], int n, int target)
{
    int low = 0;
    int high = n - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target)
        {
            return mid;
        }
        else if (arr[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return -1;
}

int main()
{
    int arr[] = {3, 8, 10, 25, 47, 60};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target;

    cout << "Sorted Array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << "\n\nEnter the number to search: ";
    cin >> target;

    int result = binarySearch(arr, n, target);

    if (result != -1)
    {
        cout << "\n" << target << " found at index " << result << "." << endl;
    }
    
    else
    {
        cout << "\n" << target << " not found in the array." << endl;
    }

    return 0;
}