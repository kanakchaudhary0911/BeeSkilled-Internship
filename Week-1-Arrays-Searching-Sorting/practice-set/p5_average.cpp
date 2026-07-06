#include <iostream>
#include <iomanip>
using namespace std;

/*
PRACTICE 5: Sum and Average of Array Elements

Objective:
- Input an array of numbers.
- Calculate the sum of all elements.
- Calculate and display the average.

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
    double sum = 0;

    cout << "Enter the array elements: ";

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }

    double average = sum / n;

    cout << "\nSum of Elements: " << sum << endl;
    cout << "Average Value : "
         << fixed << setprecision(2)
         << average << endl;

    return 0;
}