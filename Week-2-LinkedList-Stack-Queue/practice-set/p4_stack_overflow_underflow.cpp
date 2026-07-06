#include <iostream>
using namespace std;

/*
=========================================
Practice 4: Stack Overflow & Underflow
=========================================
*/

const int MAX = 5;

int stackArr[MAX];
int top = -1;

void push(int value)
{
    if (top == MAX - 1)
    {
        cout << "\nStack Overflow!\n";
        return;
    }

    stackArr[++top] = value;
    cout << value << " pushed successfully.\n";
}

void pop()
{
    if (top == -1)
    {
        cout << "\nStack Underflow!\n";
        return;
    }

    cout << "Deleted Element: " << stackArr[top--] << endl;
}

void display()
{
    if (top == -1)
    {
        cout << "\nStack is empty.\n";
        return;
    }

    cout << "\nCurrent Stack:\n";

    for (int i = top; i >= 0; i--)
        cout << stackArr[i] << endl;
}

int main()
{
    cout << "===== STACK OVERFLOW =====\n";

    for (int i = 1; i <= 6; i++)
        push(i * 10);

    display();

    cout << "\n===== STACK UNDERFLOW =====\n";

    for (int i = 1; i <= 6; i++)
        pop();

    return 0;
}
