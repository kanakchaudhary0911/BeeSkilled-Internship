#include <iostream>
using namespace std;

/*
====================================================
Assignment 4: Linear Probing Hash Table

Objective:
- Implement a Hash Table using Linear Probing.
- Insert keys into the hash table.
- Handle collisions using Linear Probing.
- Search for a key.
- Display the complete hash table.

Time Complexity:
Insertion : O(1) Average, O(n) Worst Case
Search    : O(1) Average, O(n) Worst Case
Display   : O(n)

Space Complexity:
O(n)

====================================================
*/

const int SIZE = 10;

// Hash Table
int hashTable[SIZE];

// Initialize Hash Table
void initializeTable()
{
    for (int i = 0; i < SIZE; i++)
        hashTable[i] = -1;
}

// Hash Function
int hashFunction(int key)
{
    return key % SIZE;
}

// Insert using Linear Probing
void insert(int key)
{
    int index = hashFunction(key);
    int originalIndex = index;

    while (hashTable[index] != -1)
    {
        index = (index + 1) % SIZE;

        if (index == originalIndex)
        {
            cout << "Hash Table is Full.\n";
            return;
        }
    }

    hashTable[index] = key;

    cout << key << " inserted at index " << index << ".\n";
}

// Search Key
void search(int key)
{
    int index = hashFunction(key);
    int originalIndex = index;

    while (hashTable[index] != -1)
    {
        if (hashTable[index] == key)
        {
            cout << key << " found at index " << index << ".\n";
            return;
        }

        index = (index + 1) % SIZE;

        if (index == originalIndex)
            break;
    }

    cout << key << " not found in the hash table.\n";
}

// Display Table
void display()
{
    cout << "\n========== HASH TABLE ==========\n";

    for (int i = 0; i < SIZE; i++)
    {
        cout << "Index " << i << " : ";

        if (hashTable[i] == -1)
            cout << "Empty";
        else
            cout << hashTable[i];

        cout << endl;
    }
}

int main()
{
    initializeTable();

    int choice, key;

    do
    {
        cout << "\n========== LINEAR PROBING ==========\n";
        cout << "1. Insert Key\n";
        cout << "2. Search Key\n";
        cout << "3. Display Hash Table\n";
        cout << "4. Exit\n";
        cout << "====================================\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:

            cout << "Enter key: ";
            cin >> key;

            insert(key);

            break;

        case 2:

            cout << "Enter key to search: ";
            cin >> key;

            search(key);

            break;

        case 3:

            display();

            break;

        case 4:

            cout << "\nProgram terminated successfully.\n";

            break;

        default:

            cout << "Invalid choice! Please try again.\n";
        }

    } while (choice != 4);

    return 0;
}