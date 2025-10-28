//bubble sort

#include<iostream>
using namespace std;
void bubble_sort(int arr[],int n)
{
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


}


int main()
{

int array[]={64,34,25,12,22,11,90};
int n= sizeof(array)/sizeof(array[0]);

cout<<"original array:"<<endl;


 for(int i=0;i<n;i++)
    {
        cout<<array[i]<<"  ";

    }
cout<<endl;


bubble_sort(array,n);

cout<<"after sorting array is:"<<endl;

 for(int i=0;i<n;i++)
    {
        cout<<array[i]<<" ";

    }
cout<<endl;


return 0;

}