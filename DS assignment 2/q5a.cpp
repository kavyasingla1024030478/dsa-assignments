//diagonal matrix
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size of square matrix: ";
    cin >> n;
  int A[n];   // store only diagonal elements

    cout << "Enter " << n << " diagonal elements: ";
    for(int i=0; i<n; i++) {
        cin >> A[i];
    }

    cout << "\nDiagonal Matrix:\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j) cout << A[i] << " ";
            else cout << "0 ";
        }
        cout << endl;
    }

    return 0;
}