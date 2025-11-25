#include <iostream>
using namespace std;

// Function to perform improved selection sort (min and max in one pass)
void improvedSelectionSort(int arr[], int n) {
    int left = 0;           // Start of unsorted portion
    int right = n - 1;      // End of unsorted portion

    while (left < right) {
        int min_idx = left;
        int max_idx = left;

        // Traverse the current unsorted portion to find min and max
        for (int i = left; i <= right; i++) {
            if (arr[i] < arr[min_idx]) {
                min_idx = i;
            }
            if (arr[i] > arr[max_idx]) {
                max_idx = i;
            }
        }

        // Place the minimum element at left position
        swap(arr[left], arr[min_idx]);

        // If the maximum was originally at left (and got swapped), update max_idx
        if (max_idx == left) {
            max_idx = min_idx;  // because min_idx now holds the old left position
        }

        // Place the maximum element at right position
        swap(arr[right], arr[max_idx]);

        // Shrink the unsorted portion
        left++;
        right--;
    }
}


void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}


int main() {
    int arr[] = {64, 25, 12, 22, 11, 90, 88, 45, 33};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    printArray(arr, n);

    improvedSelectionSort(arr, n);

    cout << "Sorted array:   ";
    printArray(arr, n);

    return 0;
}