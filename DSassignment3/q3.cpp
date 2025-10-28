//valid parenthesis check
#include<iostream>
#include<string.h>
#include<bits/stdc++.h>
using namespace std;
bool isvalid(string s)
{
    stack<char>st;

    for(auto it:s)
    {
        if(it=='('||it=='{'||it=='[')
        st.push(it);
       
        else{
         
            if (st.size()==0)
            return false;


            char ch=st.top();
            st.pop();


           if((it == ')'&& ch == '(') or  (it == ']' &&ch == '[') or (it == '}' && ch == '{')) 
           continue;
              
           else
            return false;
        }
    }

return st.empty();
}


int main()
{
    string s;
    cout<<"enter the string of parenthesis ypu want to check"<<endl;
    getline(cin,s);

if(isvalid(s))
{
    cout<<"true it is a valid parenthesis!"<<endl;
}
else{
    cout<<"not valid parenthesis"<<endl;
}

return 0;
}