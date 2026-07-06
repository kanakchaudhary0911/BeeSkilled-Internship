#include <iostream>
using namespace std;

/*
=========================================
Practice 3: Queue using Linked List
=========================================
*/

struct Node
{
    int data;
    Node* next;
};

Node* front = nullptr;
Node* rear = nullptr;

void enqueue(int value)
{
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;

    if (rear == nullptr)
    {
        front = rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }

    cout << "\n" << value << " inserted successfully.\n";
}

void dequeue()
{
    if (front == nullptr)
    {
        cout << "\nQueue Underflow!\n";
        return;
    }

    Node* temp = front;

    cout << "\nDeleted Element: " << front->data << endl;

    front = front->next;

    if (front == nullptr)
        rear = nullptr;

    delete temp;
}

void display()
{
    if (front == nullptr)
    {
        cout << "\nQueue is empty.\n";
        return;
    }

    cout << "\nQueue Elements:\n";

    Node* temp = front;

    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

int main()
{
    int choice, value;

    do
    {
        cout << "\n========== QUEUE ==========\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";
        cout << "Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            enqueue(value);
            break;

        case 2:
            dequeue();
            break;

        case 3:
            display();
            break;

        case 4:
            cout << "\nProgram terminated.\n";
            break;

        default:
            cout << "\nInvalid choice.\n";
        }

    } while (choice != 4);

    return 0;
}