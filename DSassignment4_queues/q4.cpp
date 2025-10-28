//finding first non repeating character in string
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

string first_nonrepaeating(string arr)
{
unordered_map<char,int>count;

queue<int>q;

string ans="";

for(int i=0;i<arr.length();i++)
{

char ch=arr[i];
count[ch]++ ;

q.push(ch);

while(!q.empty())
{
    if(count[q.front()]>1)
   q.pop();
   else
{
  ans.push_back(q.front());
   break;

}

}
 
if(q.empty())
{
    ans.push_back('-1');
}

}

return ans;

}

int main()
{

string s="aabc";
string ans=first_nonrepaeating(s);
cout<<ans;


    return 0;
}