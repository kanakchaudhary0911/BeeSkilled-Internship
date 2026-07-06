#include <iostream>
#include <stack>
#include <string>

using namespace std;

/*
========================================================
Mini Project: Undo-Redo Text Editor Simulation

Objective:
- Simulate a simple text editor.
- Store actions using stacks.
- Implement Undo and Redo operations.

Time Complexity:
Type Text : O(1)
Undo      : O(1)
Redo      : O(1)

Space Complexity:
O(n)
========================================================
*/

stack<string> undoStack;
stack<string> redoStack;
string currentText = "";

void typeText()
{
    string text;

    cout << "\nEnter text: ";
    cin.ignore();
    getline(cin, text);

    undoStack.push(currentText);
    currentText = text;

    // Clear redo history after new typing
    while (!redoStack.empty())
    {
        redoStack.pop();
    }

    cout << "\nText updated successfully.\n";
}

void undo()
{
    if (undoStack.empty())
    {
        cout << "\nNothing to undo.\n";
        return;
    }

    redoStack.push(currentText);
    currentText = undoStack.top();
    undoStack.pop();

    cout << "\nUndo completed.\n";
}

void redo()
{
    if (redoStack.empty())
    {
        cout << "\nNothing to redo.\n";
        return;
    }

    undoStack.push(currentText);
    currentText = redoStack.top();
    redoStack.pop();

    cout << "\nRedo completed.\n";
}

void displayText()
{
    cout << "\nCurrent Text:\n";

    if (currentText.empty())
        cout << "[Empty]\n";
    else
        cout << currentText << endl;
}

int main()
{
    int choice;

    do
    {
        cout << "\n=========================================\n";
        cout << "      UNDO-REDO TEXT EDITOR\n";
        cout << "=========================================\n";
        cout << "1. Type Text\n";
        cout << "2. Undo\n";
        cout << "3. Redo\n";
        cout << "4. Display Current Text\n";
        cout << "5. Exit\n";
        cout << "=========================================\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            typeText();
            break;

        case 2:
            undo();
            break;

        case 3:
            redo();
            break;

        case 4:
            displayText();
            break;

        case 5:
            cout << "\nProgram terminated successfully.\n";
            break;

        default:
            cout << "\nInvalid choice! Please try again.\n";
        }

    } while (choice != 5);

    return 0;
}