#include <iostream>
using namespace std;

/*
========================================================
Practice Set 2 : Recursive Fibonacci

Objective:
- Generate Fibonacci Series using Recursion.

Example:
0 1 1 2 3 5 8 13 ...

Time Complexity:
O(2^n)

Space Complexity:
O(n)
========================================================
*/

int fibonacci(int n)
{
    if (n == 0)
        return 0;

    if (n == 1)
        return 1;

    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
    int n;

    cout << "Enter number of terms: ";
    cin >> n;

    cout << "Fibonacci Series:\n";

    for (int i = 0; i < n; i++)
        cout << fibonacci(i) << " ";

    return 0;
}