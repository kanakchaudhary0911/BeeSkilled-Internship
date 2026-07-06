#include <iostream>
using namespace std;

/*
PRACTICE 1: Linear Search vs Binary Search

Objective:
- Compare Linear Search and Binary Search.
- Search for the same target using both algorithms.
- Display the index returned by each search.

Time Complexity:
- Linear Search : O(n)
- Binary Search : O(log n)
*/

// Linear Search
int linearSearch(int arr[], int n, int target)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == target)
        {
            return i;
        }
    }

    return -1;
}

// Binary Search (Array must be sorted)
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
    int arr[] = {5, 12, 19, 25, 33, 41, 58};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 33;

    cout << "Array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << "\n\nTarget Element: " << target << endl;

    int linearResult = linearSearch(arr, n, target);
    int binaryResult = binarySearch(arr, n, target);

    cout << "\nLinear Search Result: ";
    if (linearResult != -1)
    {
        cout << "Element found at index " << linearResult << endl;
    }
    else
    {
        cout << "Element not found." << endl;
    }

    cout << "\nBinary Search Result: ";
    if (binaryResult != -1)
    {
        cout << "Element found at index " << binaryResult << endl;
    }
    else
    {
        cout << "Element not found." << endl;
    }

    return 0;
}