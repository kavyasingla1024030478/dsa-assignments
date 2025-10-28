#include<iostream>
using namespace std;
int main()
{
    int arr[]={1,2,4,5};

    int n=sizeof(arr)/sizeof(arr[0]);
    int N=n+1;

    int sum1=(N*(N+1))/2 ;

int sum2=0;
for(int i=0;i<n;i++)
{
    sum2+=arr[i];
}

int result=sum1-sum2;

cout<<"the missing number is :"<<result<<endl;

    return 0;
}