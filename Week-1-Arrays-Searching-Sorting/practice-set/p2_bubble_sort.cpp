#include <iostream>
#include <algorithm>   // For swap()
using namespace std;

/*
PRACTICE 2: Bubble Sort

Objective:
- Sort an array in ascending order using Bubble Sort.
- Compare adjacent elements and swap them if they are in the wrong order.

Time Complexity: O(n²)
Space Complexity: O(1)
*/

void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        bool swapped = false;

        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        // Stop early if the array is already sorted
        if (!swapped)
        {
            break;
        }
    }
}

int main()
{
    int arr[] = {29, 10, 14, 37, 13};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original Array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    bubbleSort(arr, n);

    cout << "\nSorted Array:   ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;

    return 0;
}