#include <iostream>
using namespace std;

/*
  ASSIGNMENT 1: Linear Search
    - Check the elements in the array one by one.
    - If the target is found, return its index.
    - Time Complexity: O(n)
*/

int linearSearch(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            return i;  //Target found, return the index
        }
    }
    return -1;  // Not Found
}

int main() {
    int arr[] = {10, 25, 3, 47, 8, 60};
    int n = 6;
    int target;

    cout << "Array: ";
    for (int i = 0; i < n; i++)
    cout << arr[i] << " ";

    cout << "\n\nWhich number needs to be found? ";
    cin >> target;

    int result = linearSearch(arr, n, target);

    if (result != -1){
    cout << "\n" << target << " found at index " << result << "." << endl;
    }

    else{
    cout << "\n" << target << " Not in the array." << endl;
    }

    return 0;
}
