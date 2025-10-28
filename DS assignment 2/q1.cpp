
//binary search

#include<iostream>
using namespace std;
int  main()
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

  int low=0,high=n-1;
int key;
int mid;
cout<<"enter the key (element) you want to search";

cin>>key;

while(low<=high)
{
    mid=(low+high)/2;
    if(key==arr[mid])
    {
        cout<<"found at "<<mid<<" index ";
        return 0;
    }
   else if(key<arr[mid])
   {
    high=mid-1;
   }

else{
    low=mid+1;
}

}

cout<<"not found";
return 0;


}


