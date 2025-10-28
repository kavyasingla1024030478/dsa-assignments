
//interleaving

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

queue<int>interleave_queue(queue<int>&q)
{
    queue<int>newq;

    int halfsize=q.size()/2;

    for(int i=0;i<halfsize;i++)
    {
        int val=q.front();
        q.pop();
        newq.push(val);

    }

    while(!newq.empty())
    {
       int val=newq.front();
       newq.pop();
       q.push(val);
       val=q.front();
       q.pop();
       q.push(val);

    }
return q ;    
}

int main()
{
    int size;
 cout<<"enter the no. of  elements in the queue "<<endl;
cin>>size;
    queue<int>q;

    int arr[size];

    for(int i=0;i<size;i++)
    {

        cout<<"enter element "<<i+1<<endl;
       cin>>arr[i];
    }

for(int val:arr)
{

    q.push(val);
}

if(q.size()%2!=0)
{
    cout<<"queue size must be even "<<endl;
    return 0;
}

queue<int>result=interleave_queue(q);

while(!result.empty())
{
    cout<<result.front()<<" ";
    result.pop();
}

    return 0;
}

