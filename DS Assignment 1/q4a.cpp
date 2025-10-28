//a)reversing elements of an array

#include<iostream>
using namespace std;
int main(){
int n;

cout<<"enter the size of array you want:"<<endl;
    cin>>n;
    cout<<"enter "<< n<<" elements of the array:"<<endl;

    int arr[n];

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];

    }


    cout<<"the elements of array are:"<<endl;
      for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";

    }


    //reversing the array:
for(int i=0;i<=n/2;i++)
    {
         int temp = arr[i];
        arr[i] = arr[n - i - 1];
        arr[n - i - 1] = temp;

    }

        cout<<"the reversed array is:"<<endl;
      for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";

    }

    return 0;
}




