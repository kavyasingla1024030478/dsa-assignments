//postfix evaluation
#include<iostream>
#include<bits/stdc++.h>
#include<string.h>

using namespace std;

int postfixeval(string s)
{
stack<int>st;

for (int i = 0; i < s.length(); i++) 
{
    char c = s[i];
    if(s[i]>='0'&&s[i]<='9')
    st.push(s[i]-'0');//pushing char into stack but first we need to convert it into int
                       ///which can be done by subtracting zero ascii value from 
    else
    {
        int op2=st.top();
        st.pop();
        int op1=st.top();
        st.pop();

        switch(s[i])
        {
        case '+':
        st.push(op1+op2);
        break;

        case '-':
        st.push(op1-op2);
        break;

        case '*':
        st.push(op1*op2);
        break;
         
        case '/':
        st.push(op1/op2);
        break;
         
        case '^':
        st.push(pow(op1,op2));
        break;


        default:
        break;

        }
    }

 
}
return st.top();
}



int main()
{ string input;
    cout<<"enter the postfix expression you want to evaluate:"<<endl;
    cin>>input;

    cout<<postfixeval(input)<<endl;

    return 0;
}