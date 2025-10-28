#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

// Class for Singly Linked List
class SinglyLinkedList {
private:
    Node* head;

public:
    SinglyLinkedList() {
        head = nullptr;
    }

    // (a) Insertion at the beginning
    void insertAtBeginning(int value) {
        Node* newNode = new Node{value, head};
        head = newNode;
        cout << "Inserted " << value << " at the beginning.\n";
    }

    // (b) Insertion at the end
    void insertAtEnd(int value) {
        Node* newNode = new Node{value, nullptr};
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr)
                temp = temp->next;
            temp->next = newNode;
        }
        cout << "Inserted " << value << " at the end.\n";
    }

    // (c) Insertion before/after a specific node value
    void insertRelativeToValue(int value, int target, bool insertAfter) {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }

        Node* temp = head;
        Node* prev = nullptr;

        while (temp != nullptr && temp->data != target) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Node with value " << target << " not found.\n";
            return;
        }

        Node* newNode = new Node{value, nullptr};

        if (insertAfter) {
            newNode->next = temp->next;
            temp->next = newNode;
            cout << "Inserted " << value << " after " << target << ".\n";
        } else {
            if (temp == head) {
                newNode->next = head;
                head = newNode;
            } else {
                newNode->next = temp;
                prev->next = newNode;
            }
            cout << "Inserted " << value << " before " << target << ".\n";
        }
    }

    // (d) Deletion from the beginning
    void deleteFromBeginning() {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        cout << "Deleted " << temp->data << " from the beginning.\n";
        delete temp;
    }

    // (e) Deletion from the end
    void deleteFromEnd() {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }
        if (head->next == nullptr) {
            cout << "Deleted " << head->data << " from the end.\n";
            delete head;
            head = nullptr;
            return;
        }

        Node* temp = head;
        Node* prev = nullptr;
        while (temp->next != nullptr) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = nullptr;
        cout << "Deleted " << temp->data << " from the end.\n";
        delete temp;
    }

    // (f) Deletion of a specific node
    void deleteSpecificNode(int target) {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }

        Node* temp = head;
        Node* prev = nullptr;

        while (temp != nullptr && temp->data != target) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Node with value " << target << " not found.\n";
            return;
        }

        if (temp == head)
            head = head->next;
        else
            prev->next = temp->next;

        cout << "Deleted node with value " << target << ".\n";
        delete temp;
    }

    // (g) Search for a node and display its position
    void searchNode(int value) {
        Node* temp = head;
        int position = 1;
        while (temp != nullptr) {
            if (temp->data == value) {
                cout << "Node with value " << value << " found at position " << position << ".\n";
                return;
            }
            temp = temp->next;
            position++;
        }
        cout << "Node with value " << value << " not found.\n";
    }

    // (h) Display all node values
    void displayList() {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }
        Node* temp = head;
        cout << "Linked List: ";
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

// ---------------- MAIN FUNCTION ----------------
int main() {
    SinglyLinkedList list;
    int choice, value, target;
    bool after;

    do {
        cout << "\n--- Singly Linked List Menu ---\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert Before/After a Specific Node\n";
        cout << "4. Delete from Beginning\n";
        cout << "5. Delete from End\n";
        cout << "6. Delete a Specific Node\n";
        cout << "7. Search for a Node\n";
        cout << "8. Display List\n";
        cout << "9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                list.insertAtBeginning(value);
                break;

            case 2:
                cout << "Enter value: ";
                cin >> value;
                list.insertAtEnd(value);
                break;

            case 3:
                cout << "Enter value to insert: ";
                cin >> value;
                cout << "Enter target value: ";
                cin >> target;
                cout << "Insert after target? (1 = Yes, 0 = No): ";
                cin >> after;
                list.insertRelativeToValue(value, target, after);
                break;

            case 4:
                list.deleteFromBeginning();
                break;

            case 5:
                list.deleteFromEnd();
                break;

            case 6:
                cout << "Enter value to delete: ";
                cin >> target;
                list.deleteSpecificNode(target);
                break;

            case 7:
                cout << "Enter value to search: ";
                cin >> value;
                list.searchNode(value);
                break;

            case 8:
                list.displayList();
                break;

            case 9:
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 9);

    return 0;
}




































