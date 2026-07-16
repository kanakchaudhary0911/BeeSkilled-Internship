#include <iostream>
using namespace std;

/*
========================================================
Practice Set 4 : BST Minimum & Maximum

Objective:
- Find minimum and maximum element in BST.

Time Complexity:
O(log n)

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

int findMin(Node* root)
{
    while (root->left != nullptr)
        root = root->left;

    return root->data;
}

int findMax(Node* root)
{
    while (root->right != nullptr)
        root = root->right;

    return root->data;
}

int main()
{
    Node* root = nullptr;

    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 80);
    root = insert(root, 10);
    root = insert(root, 90);

    cout << "Minimum = " << findMin(root) << endl;
    cout << "Maximum = " << findMax(root);

    return 0;
}