#include <iostream>
using namespace std;

/*
=========================================
Practice 5: Menu Driven Stack
=========================================
*/

const int MAX = 100;

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
    cout << "\nElement inserted successfully.\n";
}

void pop()
{
    if (top == -1)
    {
        cout << "\nStack Underflow!\n";
        return;
    }

    cout << "\nDeleted Element: " << stackArr[top--] << endl;
}

void peek()
{
    if (top == -1)
    {
        cout << "\nStack is empty.\n";
        return;
    }

    cout << "\nTop Element: " << stackArr[top] << endl;
}

void display()
{
    if (top == -1)
    {
        cout << "\nStack is empty.\n";
        return;
    }

    cout << "\nStack Elements:\n";

    for (int i = top; i >= 0; i--)
        cout << stackArr[i] << endl;
}

int main()
{
    int choice, value;

    do
    {
        cout << "\n============================\n";
        cout << "      MENU DRIVEN STACK\n";
        cout << "============================\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "4. Display\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            push(value);
            break;

        case 2:
            pop();
            break;

        case 3:
            peek();
            break;

        case 4:
            display();
            break;

        case 5:
            cout << "\nProgram terminated successfully.\n";
            break;

        default:
            cout << "\nInvalid choice.\n";
        }

    } while (choice != 5);

    return 0;
}