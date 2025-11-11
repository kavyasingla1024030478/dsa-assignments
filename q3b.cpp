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

int sizeofcll(Node*head)
{

if(!head)
return 0;

if(head->next==head)
{
    return 1;
}

Node*temp=head;
int cnt=0;


 do {
        cnt++;
        temp = temp->next;
    } while (temp != head);



return cnt;

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


int size=sizeofcll(head);

cout<<"the size of circular linked list is "<<size<<endl;

    return 0;
}