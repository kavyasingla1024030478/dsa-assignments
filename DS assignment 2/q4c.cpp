//program to remove vowels of string

#include<iostream>
#include<string>
using namespace std;

int main()
{
    string str;
    cout<<"enter the string you want to remove vowels from : "<<endl;
    getline(cin,str);
    int n=str.length();

    for(int i=0;i<n;)
    {
        char ch=tolower(str[i]);

        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')//give condition carefully
        {
            for(int j=i;j<=n-2;j++)

     {
    str[j]=str[j+1];
           }     
           n--; 
           str.resize(n);//imp to resize!!!
 }
    else i++;

    }

    cout<<"after removal of vowels resultant string is: "<<endl;

    cout<<str;


    return 0;

}