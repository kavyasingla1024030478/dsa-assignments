//Write a program to check if a doubly linked list of characters is palindrome or not.

#include <iostream>
using namespace std;


class Node {
public:
    char data;
    Node* prev;
    Node* next;

    Node(char c) {
        data=c;
        prev = NULL;
        next = NULL;
    }


    Node(char c,Node* next1,Node *prev1)
{
     data=c;
    next=next1;
    prev=prev1;
}

};


bool isPalindrome(Node* head) {
    if (!head || !head->next)
        return true; // Empty or single-node list is palindrome

    
    Node* tail = head;
    while (tail->next != NULL)
        tail = tail->next;

    
    while (head != tail && tail->next != head) {
        if (head->data != tail->data)
            return false;
        head = head->next;
        tail = tail->prev;
    }

    return true;
}


int main() {
    
    Node* head = new Node('r');
    Node* n2 = new Node('a',nullptr,head);
    Node* n3 = new Node('d',nullptr,n2);
    Node* n4 = new Node('a',nullptr,n3);
    Node* n5 = new Node('r',nullptr,n4);

    // Link nodes
    head->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next=n5;
   

    
     if (isPalindrome(head))
        cout << "The doubly linked list is a palindrome." << endl;
    else
        cout << "The doubly linked list is not a palindrome." << endl;

    return 0;
}
