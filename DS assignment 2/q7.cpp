//counting the number of inversions
#include<iostream>
using namespace std;
int main()
{
  int n;
    cout<<"enter the number of elements you want in the array"<<endl;
    cin>>n;

    int arr[n];
    cout<<"enter the elements:"<<endl;

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];

    }
    int count=0;

for(int i=0;i<n;i++)
{
 for(int j=i+1;j<n;j++)
 {

    if(arr[i]>arr[j])
    {
        count++;
    }
 }

}
cout<<count;


    return 0;
}

///more optimal way is merge sort!!