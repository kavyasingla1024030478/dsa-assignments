//program to reverse the string 

#include<iostream>
#include<string>
using namespace std;

int main()
{
    string str;
    cout<<"enter the string you want to reverse: "<<endl;
    getline(cin,str);

    int st=0;
    int end=str.length()-1;

    while(st<end)
    {
        char temp =str[st];
        str[st]=str[end];
        str[end]=temp;
        st++;
        end--;


    }

  cout<<"reversed string is: "<<endl;
  cout<<str<<endl;


    return 0;

}