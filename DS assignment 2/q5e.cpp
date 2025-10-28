#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size of square matrix (n): ";
    cin >> n;

    int size = n * (n + 1) / 2;
    int arr[size];

    cout << "Enter elements of symmetric matrix (lower triangular part only):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cout << "Element at (" << i << ", " << j << "): ";
            int val;
            cin >> val;
            arr[(i * (i + 1)) / 2 + j] = val;              //mapping of 2d element to 1d element
        }
    }

    cout << "\nFull symmetric matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i >= j)
                cout << arr[(i * (i + 1)) / 2 + j] << " ";
            else
                cout << arr[(j * (j + 1)) / 2 + i] << " ";  // mirror element
        }
        cout << endl;
    }

    return 0;
}
