#include <iostream>
#include <string>
using namespace std;

/*
========================================================
Mini Project : Contact Directory (BST Based)

Objective:
- Store contacts using Binary Search Tree.
- Perform Insert, Search, Delete.
- Display contacts alphabetically using Inorder Traversal.

Operations:
1. Insert Contact
2. Search Contact
3. Delete Contact
4. Display Contacts
5. Exit

Time Complexity
Insert : O(log n) Average
Search : O(log n) Average
Delete : O(log n) Average
Traversal : O(n)

Space Complexity
O(n)
========================================================
*/

struct Contact
{
    string name;
    string phone;

    Contact *left;
    Contact *right;
};

Contact* createContact(string name, string phone)
{
    Contact* newNode = new Contact();

    newNode->name = name;
    newNode->phone = phone;
    newNode->left = nullptr;
    newNode->right = nullptr;

    return newNode;
}

Contact* insert(Contact* root, string name, string phone)
{
    if(root==nullptr)
        return createContact(name, phone);

    if(name < root->name)
        root->left = insert(root->left, name, phone);

    else if(name > root->name)
        root->right = insert(root->right, name, phone);

    return root;
}

Contact* search(Contact* root, string name)
{
    if(root==nullptr)
        return nullptr;

    if(root->name==name)
        return root;

    if(name < root->name)
        return search(root->left,name);

    return search(root->right,name);
}

void inorder(Contact* root)
{
    if(root==nullptr)
        return;

    inorder(root->left);

    cout<<"\nName  : "<<root->name;
    cout<<"\nPhone : "<<root->phone;
    cout<<"\n-------------------------";

    inorder(root->right);
}

Contact* minValue(Contact* root)
{
    Contact* current=root;

    while(current && current->left!=nullptr)
        current=current->left;

    return current;
}

Contact* deleteContact(Contact* root,string name)
{
    if(root==nullptr)
        return root;

    if(name < root->name)
        root->left=deleteContact(root->left,name);

    else if(name > root->name)
        root->right=deleteContact(root->right,name);

    else
    {
        if(root->left==nullptr)
        {
            Contact* temp=root->right;
            delete root;
            return temp;
        }

        else if(root->right==nullptr)
        {
            Contact* temp=root->left;
            delete root;
            return temp;
        }

        Contact* temp=minValue(root->right);

        root->name=temp->name;
        root->phone=temp->phone;

        root->right=deleteContact(root->right,temp->name);
    }

    return root;
}

int main()
{
    Contact* root=nullptr;

    int choice;

    string name;
    string phone;

    do
    {
        cout<<"\n========== CONTACT DIRECTORY ==========\n";
        cout<<"1. Insert Contact\n";
        cout<<"2. Search Contact\n";
        cout<<"3. Delete Contact\n";
        cout<<"4. Display Contacts\n";
        cout<<"5. Exit\n";
        cout<<"=======================================\n";

        cout<<"Enter choice : ";
        cin>>choice;

        switch(choice)
        {
        case 1:

            cout<<"Enter Name : ";
            cin>>name;

            cout<<"Enter Phone : ";
            cin>>phone;

            root=insert(root,name,phone);

            cout<<"\nContact Added Successfully.\n";

            break;

        case 2:

            cout<<"Enter Name : ";
            cin>>name;

            if(search(root,name))
                cout<<"\nContact Found.\n";
            else
                cout<<"\nContact Not Found.\n";

            break;

        case 3:

            cout<<"Enter Name : ";
            cin>>name;

            if(search(root,name))
            {
                root=deleteContact(root,name);

                cout<<"\nContact Deleted Successfully.\n";
            }
            else
            {
                cout<<"\nContact Not Found.\n";
            }

            break;

        case 4:

            if(root==nullptr)
            {
                cout<<"\nDirectory Empty.\n";
            }
            else
            {
                cout<<"\n======= CONTACT LIST =======\n";
                inorder(root);
            }

            break;

        case 5:

            cout<<"\nProgram Terminated Successfully.\n";

            break;

        default:

            cout<<"\nInvalid Choice.\n";
        }

    }while(choice!=5);

    return 0;
}