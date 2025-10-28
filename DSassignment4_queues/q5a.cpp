#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class mystack_2queues{

    public:
    queue<int>q1; 
    queue<int>q2;

    void push(int x)       //O(n)
    { while(!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
       q1.push(x);

       while(!q2.empty())
       {
            q1.push(q2.front());
            q2.pop();
        }

       }


       int pop()
       {
        int ans=q1.front();
        q1.pop();
        return ans;
       }


       int top()
{
return q1.front();


}
bool empty()
{
    return q1.empty();
}
void display() {
        if (q1.empty()) {
            cout << "Stack is empty." << endl;
            return;
        }

        cout << "Stack elements (top to bottom): ";
        queue<int> temp = q1;

        while (!temp.empty()) {
            cout << temp.front() << " ";
            temp.pop();
        }
        cout << endl;
    }

    };



int main()
{
mystack_2queues st;

    st.push(10);
    st.push(20);
    st.push(30);

    st.display();  // Expected: 30 20 10

    cout << "Top element: " << st.top() << endl;

    st.pop();      // Removes 30
    st.display();  // Expected: 20 10

    st.pop();      // Removes 20
    st.pop();      // Removes 10
    st.pop();      // Stack empty now

    return 0;

}