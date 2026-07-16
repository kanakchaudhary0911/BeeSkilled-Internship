#include <iostream>
using namespace std;

/*
========================================================
Practice Set 5 : Recursive Array Sum

Objective:
- Find sum of array elements using recursion.

Time Complexity:
O(n)

Space Complexity:
O(n)
========================================================
*/

int arraySum(int arr[], int n)
{
    if (n == 0)
        return 0;

    return arr[n - 1] + arraySum(arr, n - 1);
}

int main()
{
    int n;

    cout << "Enter size of array: ";
    cin >> n;

    int arr[100];

    cout << "Enter elements:\n";

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Sum = " << arraySum(arr, n);

    return 0;
}