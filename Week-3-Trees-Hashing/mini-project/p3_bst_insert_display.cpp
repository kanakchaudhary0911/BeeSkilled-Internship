#include <iostream>
using namespace std;

/*
========================================================
Practice Set 3 : BST Insert & Display

Objective:
- Insert nodes in BST.
- Display using Inorder Traversal.

Time Complexity:
Insert : O(log n) Average
Traversal : O(n)

Space Complexity:
O(n)
========================================================
*/

struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node* createNode(int value)
{
    Node* newNode = new Node();

    newNode->data = value;
    newNode->left = nullptr;
    newNode->right = nullptr;

    return newNode;
}

Node* insert(Node* root, int value)
{
    if (root == nullptr)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);

    return root;
}

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

    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);

    cout << "BST (Inorder): ";
    inorder(root);

    return 0;
}