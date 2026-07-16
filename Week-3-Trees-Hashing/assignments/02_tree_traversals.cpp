#include <iostream>
using namespace std;

/*
====================================================
Assignment 2: Tree Traversals

Objective:
- Create a Binary Search Tree (BST).
- Insert nodes into the tree.
- Perform Inorder Traversal.
- Perform Preorder Traversal.
- Perform Postorder Traversal.

Time Complexity:
Insertion           : O(log n) Average
Inorder Traversal   : O(n)
Preorder Traversal  : O(n)
Postorder Traversal : O(n)

Space Complexity:
O(n)

====================================================
*/

// Node structure
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Create a new node
Node* createNode(int value)
{
    Node* newNode = new Node();
    newNode->data = value;
    newNode->left = nullptr;
    newNode->right = nullptr;

    return newNode;
}

// Insert into BST
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

// Inorder Traversal
void inorder(Node* root)
{
    if (root == nullptr)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Preorder Traversal
void preorder(Node* root)
{
    if (root == nullptr)
        return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// Postorder Traversal
void postorder(Node* root)
{
    if (root == nullptr)
        return;

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main()
{
    Node* root = nullptr;

    int n, value;

    cout << "========== TREE TRAVERSALS ==========\n";

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter node values:\n";

    for (int i = 0; i < n; i++)
    {
        cin >> value;
        root = insert(root, value);
    }

    cout << "\nInorder Traversal:\n";
    inorder(root);

    cout << "\n\nPreorder Traversal:\n";
    preorder(root);

    cout << "\n\nPostorder Traversal:\n";
    postorder(root);

    cout << "\n\nProgram completed successfully.\n";

    return 0;
}