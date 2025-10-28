#include <iostream>
#include <string>

using namespace std;

int main() {
    string input;
    cout << "Enter a string: ";
    getline(cin, input);

    // Convert uppercase characters to lowercase
    for (int i = 0; i < input.length(); ++i) 
    {
        if (input[i] >= 'A' && input[i] <= 'Z') {
            input[i] = input[i] + ('a' - 'A');  
        }
    }

    cout << "Converted to lowercase: " << input << endl;

    return 0;
}
