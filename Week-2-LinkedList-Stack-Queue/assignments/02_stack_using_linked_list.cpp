#include <iostream>
using namespace std;

/*
====================================================
Assignment 2: Stack using Linked List

Objective:
- Implement Stack using Linked List.
- Perform Push, Pop, Peek and Display operations.

Time Complexity:
Push    : O(1)
Pop     : O(1)
Peek    : O(1)
Display : O(n)

Space Complexity:
O(n)
====================================================
*/

struct Node
{
    int data;
    Node* next;
};

Node* top = nullptr;

// Push Operation
void push(int value)
{
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = top;
    top = newNode;

    cout << "\n" << value << " pushed into the stack.\n";
}

// Pop Operation
void pop()
{
    if (top == nullptr)
    {
        cout << "\nStack Underflow! Stack is empty.\n";
        return;
    }

    Node* temp = top;
    cout << "\nPopped Element: " << top->data << endl;

    top = top->next;
    delete temp;
}

// Peek Operation
void peek()
{
    if (top == nullptr)
    {
        cout << "\nStack is empty.\n";
        return;
    }

    cout << "\nTop Element: " << top->data << endl;
}

// Display Stack
void display()
{
    if (top == nullptr)
    {
        cout << "\nStack is empty.\n";
        return;
    }

    cout << "\nStack (Top to Bottom):\n";

    Node* temp = top;

    while (temp != nullptr)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }
}

int main()
{
    int choice, value;

    do
    {
        cout << "\n=====================================\n";
        cout << "      STACK USING LINKED LIST\n";
        cout << "=====================================\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "4. Display Stack\n";
        cout << "5. Exit\n";
        cout << "=====================================\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to push: ";
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
            cout << "\nInvalid choice! Please try again.\n";
        }

    } while (choice != 5);

    return 0;
}