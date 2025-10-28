#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter size of square matrix (n): ";
    cin >> n;

    int size = n * (n + 1) / 2;
    int arr[size];




 cout << "Enter elements of upper triangular matrix :\n";
    for (int i = 0; i < n; i++) {
        for (int j =i; j<n; j++) {
            cout << "Element at (" << i << ", " << j << "): ";
            int val;
            cin >> val;
            arr[(j* (j + 1)) / 2 + i] = val;              //mapping of 2d element to 1d element
        }
    }



  cout << "\nupper triangular matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i >j)
                cout << "0" << " ";
            else
                cout << arr[(j * (j + 1)) / 2 + i] << " ";  
        }
        cout << endl;
    }


    return 0;
}