//implementing stack using one queue

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class mystack{

    queue<int>q;

    public:
    void push(int x)
    {
        int s=q.size();
        q.push(x);

        for(int i=0;i<s;i++)
        {
            q.push(q.front());
            q.pop();
        }
    }

    void pop()
    {
        if (q.empty()) {
            cout << "Stack is empty. Cannot pop." << endl;
            return;
        }

        q.pop();
    }

    int top()
    {
         if (q.empty()) {
            cout << "Stack is empty. Returning -1." << endl;
            return -1;
        }

        return q.front();
    }

    int size()
    {
        return q.size();
    }

    void display() {
        if (q.empty()) {
            cout << "Stack is empty." << endl;
            return;
        }

        cout << "Stack elements (top to bottom): ";

        int s = q.size();
        queue<int> temp = q;  // Copy the queue to preserve original

        while (!temp.empty()) {
            cout << temp.front() << " ";
            temp.pop();
        }
        cout << endl;
    }

};

int main()

{
 mystack st;
 st.push(10);
    st.push(20);
    st.push(30);

    st.display();

cout << "Top element: " << st.top() << endl; // 30

    st.pop();
    cout << "Top element after one pop: " << st.top() << endl; // 20

    st.pop();
    cout << "Top element after another pop: " << st.top() << endl; // 10





    return 0;
}