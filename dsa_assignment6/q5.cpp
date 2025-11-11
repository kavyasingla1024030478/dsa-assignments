//Write a program to check if a linked list is Circular Linked List or not.

#include<iostream>
using namespace std;

class Node{

public:
int data;
Node*next;


Node(int val)
{
    data=val;
    next=NULL;
}

};

bool isCircular(Node* head) {
    if (head == NULL)
        return true; 

    Node* temp = head->next;

 
    while (temp != NULL && temp != head) {
        temp = temp->next;
    }

    
    return (temp == head);
}

int main()

{
  Node* head = new Node(20);
    Node* n2 = new Node(100);
    Node* n3 = new Node(40);
    Node* n4 = new Node(80);
    Node* n5 = new Node(60);



 head->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = head;



    if (isCircular(head))
        cout << "The linked list is circular." << endl;
    else
        cout << "The linked list is not circular." << endl;


    return 0;
}



