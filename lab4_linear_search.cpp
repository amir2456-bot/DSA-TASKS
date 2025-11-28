
// lab4_linear_search.cpp
// Converted from "lab 4 by aima.pdf"
// Task: Linear Search (30 students)

#include <iostream>
using namespace std;

int main() {
    const int size = 30;
    int roll[size], pf[size], oop[size], dsa[size];
    int searchRoll, index = -1;

    cout << "Enter roll numbers and marks of 30 students:\\n";
    for (int i = 0; i < size; i++) {
        cout << "\\nStudent " << i + 1 << ":\\n";
        cout << "Roll Number: ";
        cin >> roll[i];

        cout << "PF Marks: ";
        cin >> pf[i];

        cout << "OOP Marks: ";
        cin >> oop[i];

        cout << "DSA Marks: ";
        cin >> dsa[i];
    }

    cout << "\\nEnter roll number to search: ";
    cin >> searchRoll;

    for (int i = 0; i < size; i++) {
        if (roll[i] == searchRoll) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        int total = pf[index] + oop[index] + dsa[index];
        float percentage = (total / 300.0f) * 100.0f;

        cout << "\\nRecord Found!\\n";
        cout << "Roll Number: " << roll[index] << endl;
        cout << "PF Marks: " << pf[index] << endl;
        cout << "OOP Marks: " << oop[index] << endl;
        cout << "DSA Marks: " << dsa[index] << endl;
        cout << "Total Marks: " << total << "/300" << endl;
        cout << "Percentage: " << percentage << "%" << endl;
    }
    else {
        cout << "\\nRecord Not Found!" << endl;
    }

    return 0;
}
