#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"enter the number of elements you want in the array";
    cin>>n;

    int arr[n];
    cout<<"enter the elements:";

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];

    }

      //sorting the array
       for(int i=n-1;i>=0;i--)
    {
       for(int j=0;j<=i-1;j++)
       {
        if(arr[j]>arr[j+1])
        {

             int temp=arr[j+1];
             arr[j+1]=arr[j];
             arr[j]=temp;

        }
       }

    }
int count=1;//keeping count as 1 for first distimct element

for(int i=1;i<n;i++)
{
if(arr[i]!=arr[i-1])
{count++ ;
}

}

cout<<"the no. of distinct elements in the array are: "<<count<<endl;


}