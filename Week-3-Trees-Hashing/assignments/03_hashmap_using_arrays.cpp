#include <iostream>
using namespace std;

/*
====================================================
Assignment 3: HashMap Using Arrays

Objective:
- Implement a simple HashMap using an array.
- Insert key-value pairs.
- Search values using keys.
- Display all stored key-value pairs.

Time Complexity:
Insertion : O(1) Average
Search    : O(1) Average
Display   : O(n)

Space Complexity:
O(n)

====================================================
*/

const int SIZE = 10;

// Hash Node
struct HashNode
{
    int key;
    int value;
    bool occupied;
};

// Hash Function
int hashFunction(int key)
{
    return key % SIZE;
}

// Insert Key-Value Pair
void insert(HashNode table[], int key, int value)
{
    int index = hashFunction(key);

    if (!table[index].occupied)
    {
        table[index].key = key;
        table[index].value = value;
        table[index].occupied = true;

        cout << "Key inserted successfully.\n";
    }
    else
    {
        cout << "Collision occurred! Slot already occupied.\n";
    }
}

// Search Key
void search(HashNode table[], int key)
{
    int index = hashFunction(key);

    if (table[index].occupied && table[index].key == key)
    {
        cout << "Key Found\n";
        cout << "Value = " << table[index].value << endl;
    }
    else
    {
        cout << "Key not found.\n";
    }
}

// Display Hash Table
void display(HashNode table[])
{
    cout << "\n========== HASH TABLE ==========\n";

    for (int i = 0; i < SIZE; i++)
    {
        cout << "Index " << i << " : ";

        if (table[i].occupied)
            cout << "(" << table[i].key << ", " << table[i].value << ")";
        else
            cout << "Empty";

        cout << endl;
    }
}

int main()
{
    HashNode table[SIZE];

    for (int i = 0; i < SIZE; i++)
        table[i].occupied = false;

    int choice, key, value;

    do
    {
        cout << "\n========== HASH MAP ==========\n";
        cout << "1. Insert\n";
        cout << "2. Search\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";
        cout << "==============================\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:

            cout << "Enter Key: ";
            cin >> key;

            cout << "Enter Value: ";
            cin >> value;

            insert(table, key, value);

            break;

        case 2:

            cout << "Enter Key to Search: ";
            cin >> key;

            search(table, key);

            break;

        case 3:

            display(table);

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