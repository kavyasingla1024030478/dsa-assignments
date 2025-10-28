#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;


    Node(int data1,Node* next1)
    {
        data=data1;
        next=next1;
    }

    Node(int data1)
    {
        data=data1;
        next=nullptr;
    }
};
void insertAtEnd(Node*& head, int value) {
    Node* newNode = new Node{value, nullptr};
    if (head == nullptr) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr)
        temp = temp->next;
    temp->next = newNode;
}

// Function to display the linked list
void displayList(Node* head) {
    if (head == nullptr) {
        cout << "List is empty.\n";
        return;
    }
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data;
        if (temp->next) cout << "->";
        temp = temp->next;
    }
    cout << endl;
}

Node* reverselinkedlist(Node*head)
{
    Node*temp=head;
    Node*prev=NULL;

    while(temp!=NULL)
    {
        Node*front=temp->next;
        temp->next=prev;
        prev=temp;
        temp=front;
    }

    return prev;
}

int main()
{

    Node* head = nullptr;
    int n, value;
    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter " << n << " node values: ";
    for (int i = 0; i < n; i++) {
        cin >> value;
        insertAtEnd(head, value);
    }

    cout << "\nOriginal Linked List: ";
    displayList(head);


    head=reverselinkedlist(head);

    cout << "Updated Linked List: ";
    displayList(head);

    return 0;

}