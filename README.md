#include <iostream>
using namespace std;

struct Node {
    int patientID;
    Node* next;
    Node(int id) : patientID(id), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;
public:
    LinkedList() : head(nullptr) {}

    // Insert at beginning (emergency)
    void insertAtBeginning(int id) {
        Node* newNode = new Node(id);
        newNode->next = head;
        head = newNode;
        cout << "Inserted at beginning: " << id << endl;
    }

    // Insert at end (normal)
    void insertAtEnd(int id) {
        Node* newNode = new Node(id);
        if (head == nullptr) {
            head = newNode;
            cout << "Inserted at end (first node): " << id << endl;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = newNode;
        cout << "Inserted at end: " << id << endl;
    }

    // Display all
    void displayAll() const {
        if (head == nullptr) {
            cout << "No patients in the list.\n";
            return;
        }
        Node* temp = head;
        cout << "Patients: ";
        while (temp != nullptr) {
            cout << temp->patientID;
            if (temp->next != nullptr) cout << " -> ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Remove patient
    bool removePatient(int id) {
        if (head == nullptr) return false;

        if (head->patientID == id) {
            Node* toDelete = head;
            head = head->next;
            delete toDelete;
            return true;
        }

        Node* cur = head;
        while (cur->next != nullptr && cur->next->patientID != id)
            cur = cur->next;

        if (cur->next == nullptr) return false;

        Node* toDelete = cur->next;
        cur->next = toDelete->next;
        delete toDelete;
        return true;
    }

    // Search
    Node* search(int id) const {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->patientID == id) return temp;
            temp = temp->next;
        }
        return nullptr;
    }

    // Destructor
    ~LinkedList() {
        Node* cur = head;
        while (cur != nullptr) {
            Node* nxt = cur->next;
            delete cur;
            cur = nxt;
        }
    }
};

int main() {
    LinkedList list;
    int choice, id;

    while (true) {
        cout << "\nMenu\n"
             << "1. Insert patient at end\n"
             << "2. Insert patient at beginning\n"
             << "3. Display all patients\n"
             << "4. Remove treated patient\n"
             << "5. Search patient\n"
             << "0. Exit\n"
             << "Your choice: ";

        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter ID: ";
                cin >> id;
                list.insertAtEnd(id);
                break;
            case 2:
                cout << "Enter ID: ";
                cin >> id;
                list.insertAtBeginning(id);
                break;
            case 3:
                list.displayAll();
                break;
            case 4:
                cout << "Enter ID: ";
                cin >> id;
                if (list.removePatient(id)) cout << "Removed.\n";
                else cout << "Not found.\n";
                break;
            case 5:
                cout << "Enter ID: ";
                cin >> id;
                if (list.search(id)) cout << "Found.\n";
                else cout << "Not found.\n";
                break;
            case 0:
                return 0;
            default:
                cout << "Invalid choice.\n";
        }
    }
}
