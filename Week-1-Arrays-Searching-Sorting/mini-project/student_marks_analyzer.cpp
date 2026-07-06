#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

/*
MINI PROJECT: Student Marks Analyzer

Objective:
- Input marks of N students.
- Sort the marks in descending order using Bubble Sort.
- Display the Top 3 highest marks.
- Calculate and display the class average.

Time Complexity:
- Sorting: O(n²)
- Average Calculation: O(n)
*/

void sortDescending(int marks[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        bool swapped = false;

        for (int j = 0; j < n - i - 1; j++)
        {
            if (marks[j] < marks[j + 1])
            {
                swap(marks[j], marks[j + 1]);
                swapped = true;
            }
        }

        if (!swapped)
            break;
    }
}

double calculateAverage(int marks[], int n)
{
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += marks[i];
    }

    return (double)sum / n;
}

int main()
{
    int n;

    cout << "=========================================\n";
    cout << "       STUDENT MARKS ANALYZER\n";
    cout << "=========================================\n";

    cout << "Enter the number of students: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "\nInvalid number of students!" << endl;
        return 0;
    }

    int marks[100];

    cout << "\nEnter marks (0 - 100):\n";

    for (int i = 0; i < n; i++)
    {
        do
        {
            cout << "Student " << i + 1 << ": ";
            cin >> marks[i];

            if (marks[i] < 0 || marks[i] > 100)
            {
                cout << "Invalid marks! Please enter a value between 0 and 100.\n";
            }

        } while (marks[i] < 0 || marks[i] > 100);
    }

    sortDescending(marks, n);

    double average = calculateAverage(marks, n);

    cout << "\n=========================================\n";
    cout << "RESULTS\n";
    cout << "=========================================\n";

    cout << "Top " << min(n, 3) << " Scores:\n";

    for (int i = 0; i < min(n, 3); i++)
    {
        cout << "Rank " << i + 1 << " : " << marks[i] << endl;
    }

    cout << "\nClass Average : "
         << fixed << setprecision(2)
         << average << endl;

    cout << "=========================================\n";

    return 0;
}