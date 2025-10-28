#include<iostream>
using namespace std;

class circularqueue
{
    public:

    int size,start,end,currsize;
    int *q;

    circularqueue(int size)
    {
        start=end=-1;
        this->size=size;
        currsize=0;

    q=new int[size];

    }


    bool isempty()
    {
       return currsize==0;
    }


    bool isfull()
    {
        return currsize==size;
    }


void enqueue(int x)
{
if(isfull())
{
    cout<<"queue is full,can't enqueue more elements"<<endl;
    return;
}
else if(isempty())
{
    start=end=0;
}
else

end=(end+1)%size;
q[end]=x;
currsize++;

}

void dequeue()
{
if(isempty())
{
    cout<<"queue is empty"<<endl;
    return ;
}

int el=q[start];

if(currsize==1)
{
    start=end=-1;
}
else

start=(start+1)%size;

currsize--;
cout<<el<<" has been dequeued"<<endl;

}

int peek()
{
    if(isempty())
    {
        cout<<"queue is empty"<<endl;
    }
    return q[start];
}

void display()
{
      if (isempty()) {
            cout << "Queue is empty"<<endl;
            return;
        }

        cout<<"queue elements:"<<endl;

    for(int i=start;i<=end;i++)
    {
        cout<<q[i]<<" ";
    }
     
    cout<<endl;


}





};



int main()
{int size;
int choice;
int value;

    cout<<"enter the size of queue you want:"<<endl;
    cin>>size;


circularqueue Q(size);


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