#include <iostream>
using namespace std;

/*
====================================================
Assignment 1: Binary Search Tree (BST)

Objective:
- Create a Binary Search Tree.
- Insert nodes.
- Search a value.
- Display the tree using Inorder Traversal.

Time Complexity:
Insertion : O(log n) Average
Search    : O(log n) Average
Traversal : O(n)

Space Complexity:
O(n)

====================================================
*/

// Node Structure
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Create New Node
Node* createNode(int value)
{
    Node* newNode = new Node();

    newNode->data = value;
    newNode->left = nullptr;
    newNode->right = nullptr;

    return newNode;
}

// Insert Node
Node* insert(Node* root, int value)
{
    if (root == nullptr)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);

    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

// Search Node
bool search(Node* root, int value)
{
    if (root == nullptr)
        return false;

    if (root->data == value)
        return true;

    if (value < root->data)
        return search(root->left, value);

    return search(root->right, value);
}

// Inorder Traversal
void inorder(Node* root)
{
    if (root == nullptr)
        return;

    inorder(root->left);

    cout << root->data << " ";

    inorder(root->right);
}

int main()
{
    Node* root = nullptr;

    int choice, value;

    do
    {
        cout << "\n========== BINARY SEARCH TREE ==========\n";
        cout << "1. Insert Node\n";
        cout << "2. Search Node\n";
        cout << "3. Display Tree (Inorder)\n";
        cout << "4. Exit\n";
        cout << "========================================\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:

            cout << "Enter value: ";
            cin >> value;

            root = insert(root, value);

            cout << value << " inserted successfully.\n";

            break;

        case 2:

            cout << "Enter value to search: ";
            cin >> value;

            if (search(root, value))
                cout << value << " found in the tree.\n";
            else
                cout << value << " not found.\n";

            break;

        case 3:

            if (root == nullptr)
            {
                cout << "Tree is empty.\n";
            }
            else
            {
                cout << "Inorder Traversal: ";

                inorder(root);

                cout << endl;
            }

            break;

        case 4:

            cout << "\nProgram terminated successfully.\n";

            break;

        default:

            cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 4);

    return 0;
}