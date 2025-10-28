#include<iostream>
#include<string>

using namespace std;
//declaring array and its size n as global variables

int arr[150];
int n;
//function to create an array

void create()
{
    cout<<"enter the size of array you want:"<<endl;
    cin>>n;
    cout<<"enter "<< n<<" elements of the array:"<<endl;

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];

    }
  cout<<"array is created "<<endl;
}


//function to display array:

void display()
{
    cout<<"the elements of array are:"<<endl;
      for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";

    }

}


//function creation for inserting an element
void insert()
{
    int position;
    int value;
if(n==0) {
    create ();
}
else {
cout<<"enter the location where you want to insert the new element:"<<endl;
cin>>position;
cout<<"enter the value of element you want to insert:"<<endl;
cin>>value;
for(int i=position;i>n;i++)
{
    arr[i+1]=arr[i];
}
arr[position-1]=value;
cout<<"the new array is:"<<endl;

 for(int i=0;i<=n;i++)
    {
        cout<<arr[i]<<" ";

    }
}
}


//function to delete the element:
void delete_element()
{

int position;
  

cout<<"enter the location where you want to delete the new element:"<<endl;
cin>>position;
if(position>=n+1)
cout<<"deletion not possible"<<endl;
else
for(int i=position-1;i<n-1;i++)
{
    arr[i]=arr[i+1];

}

cout<<"the new array is:"<<endl;
 for(int i=0;i<n-1;i++)
    {
        cout<<arr[i]<<" ";

    }


}


//linear search function
void linearsearch()
{
    int search;
    cout<<"enter the value you want to search: "<<endl;
    cin>>search;
    int i;
    for(i=0;i<n;i++)
    {
        if(arr[i]==search)
        {cout<<search<<" is found at "<<arr[i+1]<<endl;
          break;}

    }

    if(i==n)
    {
        cout<<"not present";

    }



}

int main()

{
    string menu[6]={"create","display","insert","delete","linearsearch","exit"};

    int num;
    cout<<"MENU>>  "<<endl;
 for(int i=0;i<6;i++)
 {
    cout<<i+1<<":"<<menu[i]<<endl;

 }
    cout<<"enter the operation you want to perform:";
	     cin>>num;
	    
          switch(num){
		     case 1:
		          cout<<"Create an array"<<endl;
                    create();
                    break;
               case 2:
          	     cout<<"display operation"<<endl;
                     create();
    	               display();
                    break;
               case 3:
          	     cout<<"insert element"<<endl;
                 create();
	               insert();  
                    break;
		     case 4:
			     cout<<"delete element"<<endl;
                    delete_element();
                    break;
               case 5:
               	cout<<"linear search"<<endl;
               	linearsearch();
               	break;
              	case 6:
              		cout<<"exiting ....";
               default:
               	cout<<"invalid operation!!";



}


}