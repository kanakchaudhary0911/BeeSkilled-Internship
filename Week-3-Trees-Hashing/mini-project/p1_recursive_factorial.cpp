#include <iostream>
using namespace std;

/*
========================================================
Practice Set 1 : Recursive Factorial

Objective:
- Calculate factorial using recursion.

Formula:
n! = n × (n-1)!

Example:
5! = 5×4×3×2×1 = 120

Time Complexity:
O(n)

Space Complexity:
O(n)
========================================================
*/

int factorial(int n)
{
    if (n == 0 || n == 1)
        return 1;

    return n * factorial(n - 1);
}

int main()
{
    int n;

    cout << "Enter a number: ";
    cin >> n;

    cout << "Factorial = " << factorial(n);

    return 0;
}