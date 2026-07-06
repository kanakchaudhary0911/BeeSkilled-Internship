#include <iostream>
#include <stack>
using namespace std;

/*
====================================================
Assignment 4: Reverse Linked List using Stack

Objective:
- Create a Singly Linked List.
- Reverse the Linked List using Stack.
- Display Original and Reversed List.

Time Complexity:
Create List : O(n)
Reverse     : O(n)
Display     : O(n)

Space Complexity:
O(n)
====================================================
*/

struct Node
{
    int data;
    Node* next;
};

// Insert node at end
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

// Display Linked List
void display(Node* head)
{
    if (head == nullptr)
    {
        cout << "Linked List is empty.\n";
        return;
    }

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

// Reverse using Stack
void reverseList(Node*& head)
{
    if (head == nullptr || head->next == nullptr)
        return;

    stack<Node*> s;

    Node* temp = head;

    while (temp != nullptr)
    {
        s.push(temp);
        temp = temp->next;
    }

    head = s.top();
    s.pop();

    temp = head;

    while (!s.empty())
    {
        temp->next = s.top();
        s.pop();
        temp = temp->next;
    }

    temp->next = nullptr;
}

int main()
{
    Node* head = nullptr;

    int n, value;

    cout << "=========================================\n";
    cout << " Reverse Linked List using Stack\n";
    cout << "=========================================\n";

    cout << "Enter the number of nodes: ";
    cin >> n;

    cout << "Enter the node values:\n";

    for (int i = 0; i < n; i++)
    {
        cin >> value;
        insert(head, value);
    }

    cout << "\nOriginal Linked List:\n";
    display(head);

    reverseList(head);

    cout << "\nReversed Linked List:\n";
    display(head);

    cout << "\nProgram executed successfully.\n";

    return 0;
}