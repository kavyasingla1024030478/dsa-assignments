//converting infix expression to postfix expression
#include<iostream>
#include<string.h>
#include<bits/stdc++.h>
using namespace std;


//making a priority function for operators
int priority(char ch)
{
 if(ch=='^')
 return 3;

 else if(ch=='*'||ch=='/')
return 2;

else if(ch=='+'||ch=='-')
return 1;

else
return -1;
}

void infixtopostfix(string s) 
{

  stack < char > st; 
  string result;

  for (int i = 0; i < s.length(); i++) {
    char c = s[i];

    // If the scanned character is
    // an operand, add it to output string.

    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
      result += c;

    // If the scanned character is an
    // ‘(‘, push it to the stack.


    else if (c == '(')
      st.push('(');

    // If the scanned character is an ‘)’,
    // pop and to output string from the stack
    // until an ‘(‘ is encountered.


    else if (c == ')') {
      while (st.top() != '(') {
        result += st.top();
        st.pop();
      }
      st.pop();
    }

    //If an operator is scanned
    else {
      while (!st.empty() && priority(s[i]) <= priority(st.top())) {
        result += st.top();
        st.pop();
      }
      st.push(c);
    }
  }

  // Pop all the remaining elements from the stack
  while (!st.empty()) {
    result += st.top();
    st.pop();
  }

  cout << "Postfix expression: " << result << endl;
}



using namespace std;
int main()
{
    string input;
  cout<<"enter the infix expression you want to convert to postfix"<<endl;
  getline(cin,input);

   infixtopostfix(input);

    return 0;
}