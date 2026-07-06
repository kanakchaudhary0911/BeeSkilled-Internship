#include <iostream>
using namespace std;

/*
====================================================
Assignment 1: Singly Linked List (Insert & Delete)

Objective:
- Implement a Singly Linked List.
- Insert nodes at the end.
- Delete a node by value.
- Display the linked list.

Time Complexity:
Insert  : O(n)
Delete  : O(n)
Display : O(n)

Space Complexity: O(n)
====================================================
*/

struct Node
{
    int data;
    Node* next;
};

// Insert a node at the end
void insert(Node*& head, int value)
{
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;

    if (head == nullptr)
    {
        head = newNode;
        return;
    }

    Node* temp = head;

    while (temp->next != nullptr)
    {
        temp = temp->next;
    }

    temp->next = newNode;
}

// Delete a node by value
void deleteNode(Node*& head, int value)
{
    if (head == nullptr)
    {
        cout << "\nLinked List is empty.\n";
        return;
    }

    if (head->data == value)
    {
        Node* temp = head;
        head = head->next;
        delete temp;

        cout << "\n" << value << " deleted successfully.\n";
        return;
    }

    Node* current = head;

    while (current->next != nullptr && current->next->data != value)
    {
        current = current->next;
    }

    if (current->next == nullptr)
    {
        cout << "\n" << value << " not found in the list.\n";
        return;
    }

    Node* temp = current->next;
    current->next = temp->next;
    delete temp;

    cout << "\n" << value << " deleted successfully.\n";
}

// Display linked list
void display(Node* head)
{
    if (head == nullptr)
    {
        cout << "\nLinked List is empty.\n";
        return;
    }

    cout << "\nLinked List: ";

    Node* temp = head;

    while (temp != nullptr)
    {
        cout << temp->data;

        if (temp->next != nullptr)
            cout << " -> ";

        temp = temp->next;
    }

    cout << " -> NULL\n";
}

int main()
{
    Node* head = nullptr;

    int choice, value;

    do
    {
        cout << "\n=========================================\n";
        cout << "      SINGLY LINKED LIST OPERATIONS\n";
        cout << "=========================================\n";
        cout << "1. Insert Node\n";
        cout << "2. Delete Node\n";
        cout << "3. Display Linked List\n";
        cout << "4. Exit\n";
        cout << "=========================================\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to insert: ";
            cin >> value;
            insert(head, value);
            cout << "\nNode inserted successfully.\n";
            break;

        case 2:
            cout << "Enter value to delete: ";
            cin >> value;
            deleteNode(head, value);
            break;

        case 3:
            display(head);
            break;

        case 4:
            cout << "\nThank you! Program terminated successfully.\n";
            break;

        default:
            cout << "\nInvalid choice! Please try again.\n";
        }

    } while (choice != 4);

    return 0;
}