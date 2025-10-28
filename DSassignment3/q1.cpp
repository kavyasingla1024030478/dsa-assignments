#include<iostream>
using namespace std;
class stackimplement
{
   int *arr;
   int size;
   int top;

   public:

   stackimplement(){//constructor
      top = -1;
      size = 0;
      arr = nullptr;
    }
void setsize(int n) {
       
    if (n<= 0) {
            cout << "Stack size must be positive.\n";
            return;
        }

        size=n;
        arr= new int[size];
        /*new int[maxSize] creates an array of maxSize integers.

Returns a pointer to the first element of this array.

Assigning that pointer to stack means stack now points to this block of memory.*/

        cout << "Stack of size " << size << " created.\n";
    }
   
  void push(int x)
{
    if(top>=size-1)
   { cout<<"stack overflow,size exceeded hence can't push further"<<endl;
    return;
   }
    top=top+1;
    arr[top]=x;
}


int peek()
{
    if(top==-1)
    {cout<<"no element in the stack";
    return -1;}

    return arr[top];

}

void pop()
{
if(top==-1)
    {cout<<"no element in the stack to pop out";
    return ;}
top=top-1;

}


bool isFull() {
        return top == size-1;
    }

    bool isEmpty() {
        return top == -1;
    }


void display() {
        if (isEmpty()) {
            cout << "Stack is empty.\n";
        } else {
            cout << "Stack elements: ";
            for (int i = 0; i <= top; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }


};



int main()
{

  stackimplement s;

    int size;
    cout << "Enter the size of the stack: ";
    cin >> size;

    s.setsize(size);  // Using setter to initialize stack size

    s.push(10);
    s.push(20);
    s.push(30);

    s.display();
    int topVal = s.peek();
   if (topVal != -1)
      cout << "Top element is: " << topVal << endl;

    s.pop();
    s.display();

    

    return 0;
}