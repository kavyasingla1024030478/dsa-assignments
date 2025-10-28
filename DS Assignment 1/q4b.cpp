#include<iostream>
using namespace std;
int main()
{
int a[10][10],b[10][10],mult[10][10],r1,c1,r2,c2,i,j,k;

cout<<"enter the rows and columns for first matrix: "<<endl;
cin>>r1>>c1;

cout<<"enter the rows and columns for second matrix: "<<endl;
cin>>r2>>c2;

if(c1!=r2)
{
    cout<<"multiplication not possible"<<endl;
       return 0;
}

//input first matrix
cout<<"enter the elements off first matrix:"<<endl;
for(int i=0;i<r1;i++)
{
    for(int j=0;j<c1;j++)
    {
        cout<<"enter the element a"<<"["<<i+1<<","<<j+1<<"]:"<<endl;
           cin>>a[i][j];

    }
}

//input second matrix
cout<<"enter the elements of second matrix:"<<endl;
for(int i=0;i<r2;i++)
{
    for(int j=0;j<c2;j++)
    {
        cout<<"enter the element b"<<"["<<i+1<<","<<j+1<<"]:"<<endl;
           cin>>b[i][j];

    }
}
//printing first matrix
cout<<"the first matrix is:"<<endl;
for(int i=0;i<r1;i++)
{
    for(int j=0;j<c1;j++)
    {
        cout<<a[i][j]<<" ";


    }
    cout<<endl;

}

//printing second matrix
cout<<"the second matrix is:"<<endl;
for(int i=0;i<r2;i++)
{
    for(int j=0;j<c2;j++)
    {
        cout<<b[i][j]<<" ";


    }
    cout<<endl;

}

for(int i=0;i<r1;i++)
{
    for(int j=0;j<c2;j++)
    {

        mult[i][j]=0;
        for(int k=0;k<c1;k++)
        {
            mult[i][j]+=a[i][k]*b[k][j];

        }

    }
}

cout<<"the resultant multiplication matrix is:"<<endl;
for(int i=0;i<r2;i++)
{
    for(int j=0;j<c1;j++)
    {
        cout<<mult[i][j]<<" ";


    }
    cout<<endl;

}

    return 0;

}