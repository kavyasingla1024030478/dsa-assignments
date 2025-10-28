//program to sort the strings in alphabetical order:

#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    cout<< "Enter the number of strings: ";
    cin >> n;
    cin.ignore();
    
    string strings[100];

    cout << "Enter " << n << " strings:" << endl;
    for (int i = 0; i < n; ++i) {
         getline(cin, strings[i]);
    }

    // Bubble sort algorithm to sort strings alphabetically
    for (int i =n-1; i>=1; i--) {
        for (int j = 0; j <= i - 1; ++j) {
            if (strings[j] > strings[j + 1]) {
                // Swap if the string at j is greater than at j+1
                string temp = strings[j];
                strings[j] = strings[j + 1];
                strings[j + 1] = temp;
            }
        }
    }
    cout << "\nStrings in alphabetical order:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << strings[i] << endl;
    }



    return 0;
}
