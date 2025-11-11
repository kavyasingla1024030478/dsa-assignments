#include <iostream>
using namespace std;


class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int val) {
        data = val;
        prev = NULL;
        next = NULL;
    }


    Node(int data1,Node* next1,Node *prev1)
{
    data=data1;
    next=next1;
    prev=prev1;
}

};

// Function to find the size of the doubly linked list
int sizeOfDoublyLinkedList(Node* head) {
    int count = 0;
    Node* temp = head;

    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    return count;
}

int main() {
    
    Node* head = new Node(10);
    Node* n2 = new Node(20,nullptr,head);
    Node* n3 = new Node(30,nullptr,n2);
    Node* n4 = new Node(40,nullptr,n3);

    // Link nodes
    head->next = n2;
    n2->next = n3;
    n3->next = n4;
   

    int size = sizeOfDoublyLinkedList(head);
    cout << "The size of the doubly linked list is: " << size << endl;

    return 0;
}
