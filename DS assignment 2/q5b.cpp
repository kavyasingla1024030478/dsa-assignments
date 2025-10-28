#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size of square matrix (n=no.of rows=no.of columns): ";
    cin >> n;

    int lower[n-1], main[n], upper[n-1];

    cout << "Enter main diagonal elements (" << n << "): ";
    for (int i = 0; i < n; i++) {
        cin >> main[i];
    }

    cout << "Enter upper diagonal elements (" << n-1 << "): ";
    for (int i = 0; i < n - 1; i++) {
        cin >> upper[i];
    }

    cout << "Enter lower diagonal elements (" << n-1 << "): ";
    for (int i = 0; i < n - 1; i++) {
        cin >> lower[i];
    }

    cout << "\nTridiagonal matrix is:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j)
                cout << main[i] << " ";
            else if (j == i + 1)
                cout << upper[i] << " ";
            else if (i == j + 1)
                cout << lower[j] << " ";
            else
                cout << 0 << " ";
        }
        cout << endl;
    }

    return 0;
}
