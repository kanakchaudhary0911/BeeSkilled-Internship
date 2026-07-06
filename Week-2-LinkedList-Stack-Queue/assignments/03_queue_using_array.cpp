#include <iostream>
using namespace std;

/*
====================================================
Assignment 3: Queue using Array

Objective:
- Implement Queue using Array.
- Perform Enqueue, Dequeue, Front and Display operations.

Time Complexity:
Enqueue : O(1)
Dequeue : O(1)
Front   : O(1)
Display : O(n)

Space Complexity:
O(n)
====================================================
*/

const int MAX = 100;

int queue[MAX];
int front = -1;
int rear = -1;

// Enqueue Operation
void enqueue(int value)
{
    if (rear == MAX - 1)
    {
        cout << "\nQueue Overflow! Queue is full.\n";
        return;
    }

    if (front == -1)
        front = 0;

    rear++;
    queue[rear] = value;

    cout << "\n" << value << " inserted into the queue.\n";
}

// Dequeue Operation
void dequeue()
{
    if (front == -1 || front > rear)
    {
        cout << "\nQueue Underflow! Queue is empty.\n";
        return;
    }

    cout << "\nDeleted Element: " << queue[front] << endl;
    front++;

    if (front > rear)
    {
        front = rear = -1;
    }
}

// Front Element
void showFront()
{
    if (front == -1)
    {
        cout << "\nQueue is empty.\n";
        return;
    }

    cout << "\nFront Element: " << queue[front] << endl;
}

// Display Queue
void display()
{
    if (front == -1)
    {
        cout << "\nQueue is empty.\n";
        return;
    }

    cout << "\nQueue Elements:\n";

    for (int i = front; i <= rear; i++)
    {
        cout << queue[i] << " ";
    }

    cout << endl;
}

int main()
{
    int choice, value;

    do
    {
        cout << "\n=====================================\n";
        cout << "        QUEUE USING ARRAY\n";
        cout << "=====================================\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Front Element\n";
        cout << "4. Display Queue\n";
        cout << "5. Exit\n";
        cout << "=====================================\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to enqueue: ";
            cin >> value;
            enqueue(value);
            break;

        case 2:
            dequeue();
            break;

        case 3:
            showFront();
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