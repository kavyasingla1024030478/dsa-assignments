//reversal using stack
#include<iostream>
#include<string.h>
#include<bits/stdc++.h>
using namespace std;

int main() {
    string input, reversed;

    cout << "Enter a string: ";
    getline(cin, input);  // Get full line including spaces

    stack<char>s;

    // Push all characters onto the stack
    for (char ch : input) {
        s.push(ch);
    }

    // Pop characters to get reversed string
    while (!s.empty()) {
        reversed += s.top();
        s.pop();
    }

    cout << "Reversed string: " << reversed << endl;

    return 0;
}



   