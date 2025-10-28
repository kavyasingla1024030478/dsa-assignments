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
//printing the matrix
cout<<"the matrix is:"<<endl;
for(int i=0;i<r1;i++)
{
    for(int j=0;j<c1;j++)
    {
        cout<<a[i][j]<<" ";


    }
    cout<<endl;

}



for(int i=0;i<r1;i++)
{
    int sumrow=0;
    int sumcol=0;


    for(int j=0;j<c1;j++)
    {
        sumrow=sumrow+a[i][j];
        sumcol=sumcol+a[j][i];

    }

    cout<<"sum of row "<<i+1<< " elemnents:"<<sumrow<<endl;
    cout<<"sum of column "<<i+1<< " elemnents:"<<sumcol<<endl;

    cout<<endl;

}
    return 0;

}