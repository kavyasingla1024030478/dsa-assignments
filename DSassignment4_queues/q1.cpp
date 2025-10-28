#include<iostream>
using namespace std;

class queue{
public:
int size,start,end,currsize;
int *q;
queue(int s)
{
size=s;
start=end=-1;
currsize=0;
q=new int[size];
}


~queue() {
    delete[] q;
}



bool isfull()
{
 return currsize==size;
}


void enqueue(int x)
{
    if(isfull())
    {
      cout<<"queue is full , can't enqueue any more elements"<<endl;
      return;
    }


    if(currsize==0)//queue is empty
    {
        start=end=0;
    }
else{
    end=end+1;

}

q[end]=x;
currsize++;

cout<<x<<" has been enqueued"<<endl;
}


bool isempty()
{

return currsize==0;

}

void dequeue()
{
if(isempty())
{
    cout<<"queue is empty hence no element present to dequeue"<<endl;
    return;
}

int el=q[start];

if (currsize==1)
{
start=end=-1;
}
else

start=start+1;
currsize--;
cout<<el<<" has been dequeued"<<endl;

}


void peek()
{
if(isempty())
{
    cout<<"queue is empty"<<endl;
    return ;
}

cout<<"front element is : "<<q[start]<<endl;
return;

}



    void display() {
        if (isempty()) {
            cout << "Queue is empty"<<endl;
            return;
        }
        cout << "Queue elements: ";
        for (int i = start; i <= end; ++i) {
            cout << q[i] << " ";
        }
        cout << endl;
    }


};


int main()
{
int size;
int choice;
int value;

    cout<<"enter the size of queue you want:"<<endl;
    cin>>size;


queue Q(size);


  do {
        cout << "\n------ Queue Menu ------"<<endl;
        cout << "1. Enqueue"<<endl;
        cout << "2. Dequeue"<<endl;
        cout << "3. Peek (Front element)"<<endl;
        cout << "4. Check if Empty"<<endl;
        cout << "5. Check if Full"<<endl;
        cout << "6. Display"<<endl;
        cout << "0. Exit"<<endl;
        cout << "Enter your choice: "<<endl;
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to enqueue: ";
            cin >> value;
            Q.enqueue(value);
            break;
        case 2:
            Q.dequeue();
            break;
        case 3:
            Q.peek();
            break;
        case 4:
            cout << (Q.isempty() ? "Queue is EMPTY.\n" : "Queue is NOT empty.\n");
            break;
        case 5:
            cout << (Q.isfull() ? "Queue is FULL.\n" : "Queue is NOT full.\n");
            break;
        case 6:
            Q.display();
            break;
        case 0:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 0);


    return 0;
}