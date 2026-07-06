#include <iostream>
#include <algorithm>   // For swap()
using namespace std;

/*
ASSIGNMENT 3: Bubble Sort with Swap Count

- Compares adjacent elements and swaps them if they are in the wrong order.
- Repeats the process until the array is completely sorted.
- Uses an optimized approach with early termination.
- Time Complexity: O(n^2)
*/

void bubbleSort(int arr[], int n)
{
    int swapCount = 0;

    for (int i = 0; i < n - 1; i++)
    {
        bool swapped = false;

        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapCount++;
                swapped = true;
            }
        }

        // Stop if the array is already sorted
        if (!swapped)
            break;
    }

    cout << "\nTotal Swaps Performed: " << swapCount << endl;
}

int main()
{
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original Array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;

    bubbleSort(arr, n);

    cout << "\nSorted Array:   ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;

    return 0;
}