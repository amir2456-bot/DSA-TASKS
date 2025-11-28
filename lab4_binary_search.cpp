
// lab4_binary_search.cpp
// Converted from "lab 4 by aima (1).pdf"
// Task: Linear Search & Binary Search & variants

#include <iostream>
using namespace std;

int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key)
            return i;
    }
    return -1;
}

int binarySearch(int arr[], int n, int key) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

int binarySearchAsc(int arr[], int n, int key) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int binarySearchDesc(int arr[], int n, int key) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] > key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main() {
    int n, choice, key;
    cout << "Enter number of students: ";
    cin >> n;
    int roll[n];
    cout << "Enter " << n << " roll numbers:\\n";
    for (int i = 0; i < n; i++) {
        cin >> roll[i];
    }

    cout << "\\nChoose Search Method:\\n";
    cout << "1. Linear Search (Unsorted Array)\\n";
    cout << "2. Binary Search (Sorted Array)\\n";
    cout << "Enter choice: ";
    cin >> choice;
    cout << "Enter roll number to search: ";
    cin >> key;
    int result = -1;
    if (choice == 1) {
        result = linearSearch(roll, n, key);
    }
    else if (choice == 2) {
        result = binarySearch(roll, n, key);
    }
    else {
        cout << "Invalid choice.";
        return 0;
    }
    if (result != -1)
        cout << "\\nRoll number found at index: " << result << endl;
    else
        cout << "\\nRoll number NOT found in the list.\\n";

    // Extra part: detect even/odd and search accordingly
    int key2;
    cout << "\\nEnter the roll number to search (for asc/desc example): ";
    cin >> key2;
    int position;
    if (key2 % 2 == 0) {
        cout << "\\nEven number detected → Searching in ASCENDING order...\\n";
        position = binarySearchAsc(roll, n, key2);
    }
    else {
        cout << "\\nOdd number detected → Searching in DESCENDING order...\\n";
        position = binarySearchDesc(roll, n, key2);
    }
    if (position != -1)
        cout << "\\nRoll number found at position: " << position << endl;
    else
        cout << "\\nRoll number not found in the array.\\n";

    return 0;
}
