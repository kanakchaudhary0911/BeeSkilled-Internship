#include <iostream>
using namespace std;

/*
=========================================
Practice 1: Singly Linked List Display

Objective:
- Create a Singly Linked List.
- Insert nodes at the end.
- Display all nodes.

Time Complexity:
Insert  : O(n)
Display : O(n)

Space Complexity:
O(n)
=========================================
*/

struct Node
{
    int data;
    Node* next;
};

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
        temp = temp->next;

    temp->next = newNode;
}

void display(Node* head)
{
    if (head == nullptr)
    {
        cout << "\nLinked List is empty.\n";
        return;
    }

    cout << "\nLinked List:\n";

    while (head != nullptr)
    {
        cout << head->data;

        if (head->next != nullptr)
            cout << " -> ";

        head = head->next;
    }

    cout << " -> NULL\n";
}

int main()
{
    Node* head = nullptr;

    int n, value;

    cout << "=====================================\n";
    cout << " Practice 1 - Singly Linked List\n";
    cout << "=====================================\n";

    cout << "Enter the number of nodes: ";
    cin >> n;

    cout << "Enter node values:\n";

    for (int i = 0; i < n; i++)
    {
        cin >> value;
        insert(head, value);
    }

    display(head);

    return 0;
}