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
int countoccurences(Node*head,int key)
{
    int count=0;
    Node*temp=head;
    while(temp!=nullptr)
    {
        if(temp->data==key)
        {
            count++;
        }
      temp=temp->next;
    }
    return count;
}

Node*deletealloccurences(Node*head,int key)
{
    while(head!=nullptr && head->data==key)
    {
        Node*temp=head;
        head=head->next;
        delete temp;
    }
    
    if (head == nullptr) return nullptr;

    Node*temp=head;
    while(temp->next!=nullptr)
    {
        if(temp->next->data==key)
        {
            Node*deletenode=temp->next;
            temp->next=temp->next->next;
            delete deletenode;

        }
        else
        temp=temp->next;
    }
    return head;
}

int main()
{

    Node* head = nullptr;
    int n, value, key;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter " << n << " node values: ";
    for (int i = 0; i < n; i++) {
        cin >> value;
        insertAtEnd(head, value);
    }

    cout << "Enter key to delete: ";
    cin >> key;

    cout << "\nOriginal Linked List: ";
    displayList(head);

    int count =countoccurences(head, key);


    cout << "\nCount: " << count << endl;
    head=deletealloccurences(head,key);

    cout << "Updated Linked List: ";
    displayList(head);

    return 0;

}