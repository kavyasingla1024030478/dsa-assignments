//finding transpose of matrix
#include<iostream>
using namespace std;
int main()

{
    int a[10][10];
    int r1,c1;

    cout<<"enter the rows and columns for first matrix: "<<endl;
cin>>r1>>c1;

//inputting the elements of matrix whose transpose is required
cout<<"enter the elements of matrix:"<<endl;
for(int i=0;i<r1;i++)
{
    for(int j=0;j<c1;j++)
    {
        cout<<"enter the element a"<<"["<<i+1<<","<<j+1<<"]:"<<endl;
           cin>>a[i][j];

    }
}
//printing the original matrix
cout<<"the original matrix is:"<<endl;
for(int i=0;i<r1;i++)
{
    for(int j=0;j<c1;j++)
    {
        cout<<a[i][j]<<" ";


    }
    cout<<endl;

}


//printing the transpose matrix
cout<<"the transpose matrix is:"<<endl;
for(int i=0;i<c1;i++)
{
    for(int j=0;j<r1;j++)
    {
        cout<<a[j][i]<<" ";


    }
    cout<<endl;

}


return 0;

}