#include<iostream>
using namespace std;

class Node
{
public:
int data;
Node *prev;
Node *next;

Node(int data1,Node* next1,Node *prev1)
{
    data=data1;
    next=next1;
    prev=prev1;
}

Node(int data1)
{
    data=data1;
    next=NULL;
    prev=NULL;

}
};


class DoublyLinkedList{

Node*head;

public:

DoublyLinkedList():head(nullptr){}

void insertAtBeginning(int val) {
        Node* newhead = new Node(val,head,nullptr);
        if (!head) {
            head = newhead;
            return;
        }
        head->prev=newhead;
        newhead->next=head;
         head=newhead;
    }

void insertatend(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next)
        {
            temp = temp->next;}
        temp->next = newNode;
        newNode->prev = temp;
    

}

void insertafter(int key, int val) {
        Node* temp = head;
        while (temp && temp->data != key)
            temp = temp->next;
        if (!temp) {
            cout << "Node " << key << " not found.\n";
            return;
        }
        Node* newNode = new Node(val);
        newNode->next = temp->next;
        if (temp->next)
            temp->next->prev = newNode;
        temp->next = newNode;
        newNode->prev = temp;
    }

void insertBefore(int key, int val) {
        Node* temp = head;
        while (temp && temp->data != key)
            temp = temp->next;
        if (!temp) {
            cout << "Node " << key << " not found.\n";
            return;
        }
        Node* newNode = new Node(val);
        newNode->next = temp;
        newNode->prev = temp->prev;
        if (temp->prev)
            temp->prev->next = newNode;
        else
            head = newNode;
        temp->prev = newNode;
    }

     // Search for a node
    bool search(int key) {
        Node* temp = head;
        while (temp) {
            if (temp->data == key)
                return true;
            temp = temp->next;
        }
        return false;
    }

    void deleteNode(int key) {
        Node* temp = head;
        while (temp && temp->data != key)
            temp = temp->next;
        if (!temp) {
            cout << "Node " << key << " not found.\n";
            return;
        }
        if (temp->prev)
            temp->prev->next = temp->next;
        else
            head = temp->next;
        if (temp->next)
            temp->next->prev = temp->prev;
        delete temp;
        cout << "Node " << key << " deleted.\n";
    }



void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};



class  CircularLinkedList
{


   struct Node {
        int data;
        Node* next;
        Node(int val) : data(val), next(nullptr) {}
    };
    Node* head;

public:
    CircularLinkedList() : head(nullptr) {}

    // Insert at beginning
    void insertAtBeginning(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            head->next = head;
            return;
        }
        Node* temp = head;
        while (temp->next != head)
            temp = temp->next;
        newNode->next = head;
        temp->next = newNode;
        head = newNode;
    }

    // Insert at end
    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            head->next = head;
            return;
        }
        Node* temp = head;
        while (temp->next != head)
            temp = temp->next;
        temp->next = newNode;
        newNode->next = head;
    }

    // Insert after a specific node
    void insertAfter(int key, int val) {
        if (!head) return;
        Node* temp = head;
        do {
            if (temp->data == key) {
                Node* newNode = new Node(val);
                newNode->next = temp->next;
                temp->next = newNode;
                return;
            }
            temp = temp->next;
        } while (temp != head);
        cout << "Node " << key << " not found.\n";
    }

    // Delete a node by value
    void deleteNode(int key) {
        if (!head) return;
        Node *curr = head, *prev = nullptr;
        while (curr->data != key) {
            if (curr->next == head) {
                cout << "Node " << key << " not found.\n";
                return;
            }
            prev = curr;
            curr = curr->next;
        }
        if (curr == head && curr->next == head) {
            head = nullptr;
        } else if (curr == head) {
            Node* temp = head;
            while (temp->next != head)
                temp = temp->next;
            head = head->next;
            temp->next = head;
        } else {
            prev->next = curr->next;
        }
        delete curr;
        cout << "Node " << key << " deleted.\n";
    }

    // Search for a node
    bool search(int key) {
        if (!head) return false;
        Node* temp = head;
        do {
            if (temp->data == key)
                return true;
            temp = temp->next;
        } while (temp != head);
        return false;
    }

    // Display list
    void display() {
        if (!head) {
            cout << "List is empty.\n";
            return;
        }
        Node* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }





};





int main() {
    DoublyLinkedList dll;
    CircularLinkedList cll;
    int choice, type, val, key;

    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Doubly Linked List\n";
        cout << "2. Circular Linked List\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> type;

        if (type == 3) break;

        do {
            cout << "\n1. Insert at Beginning\n2. Insert at End\n3. Insert After\n4. Insert Before (DLL only)"
                 << "\n5. Delete Node\n6. Search\n7. Display\n8. Back\nEnter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    cout << "Enter value: ";
                    cin >> val;
                    (type == 1) ? dll.insertAtBeginning(val) : cll.insertAtBeginning(val);
                    break;
                case 2:
                    cout << "Enter value: ";
                    cin >> val;
                    (type == 1) ? dll.insertatend(val) : cll.insertAtEnd(val);
                    break;
                case 3:
                    cout << "Enter key and value: ";
                    cin >> key >> val;
                    (type == 1) ? dll.insertafter(key, val) : cll.insertAfter(key, val);
                    break;
                case 4:
                    if (type == 1) {
                        cout << "Enter key and value: ";
                        cin >> key >> val;
                        dll.insertBefore(key, val);
                    } else
                        cout << "Not supported for Circular Linked List.\n";
                    break;
                case 5:
                    cout << "Enter value to delete: ";
                    cin >> val;
                    (type == 1) ? dll.deleteNode(val) : cll.deleteNode(val);
                    break;
                case 6:
                    cout << "Enter value to search: ";
                    cin >> val;
                    cout << ((type == 1 ? dll.search(val) : cll.search(val)) ? "Found\n" : "Not Found\n");
                    break;
                case 7:
                    (type == 1) ? dll.display() : cll.display();
                    break;
            }
        } while (choice != 8);
    } while (type != 3);

    return 0;
}
