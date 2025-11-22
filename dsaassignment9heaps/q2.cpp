#include<iostream>
using namespace std;

#include <iostream>
using namespace std;

class PriorityQueue {
public:
    int arr[100];   // heap array
    int size;

    PriorityQueue() {
        arr[0] = -1; 
        size = 0;
    }

    // Insert element into priority queue (Max Heap)
    void push(int val) {
        size++;
        int index = size;
        arr[index] = val;

        // Heapify UP
        while(index > 1) {
            int parent = index / 2;

            if(arr[parent] < arr[index]) {
                swap(arr[parent], arr[index]);
                index = parent;
            } else {
                break;
            }
        }
    }

    // Remove highest priority element (root)
    void pop() {
        if(size == 0) {
            cout << "Priority Queue is empty!\n";
            return;
        }

        // Step 1: Replace root with last element
        arr[1] = arr[size];
        size--;

        // Step 2: Heapify DOWN
        int index = 1;
        while(true) {
            int left = 2 * index;
            int right = 2 * index + 1;
            int largest = index;

            if(left <= size && arr[left] > arr[largest])
                largest = left;

            if(right <= size && arr[right] > arr[largest])
                largest = right;

            if(largest != index) {
                swap(arr[index], arr[largest]);
                index = largest;
            } else {
                break;
            }
        }
    }

    // Return highest priority element
    int top() {
        if(size == 0) {
            cout << "Priority Queue is empty!\n";
            return -1;
        }
        return arr[1];
    }

    // Print heap elements
    void print() {
        cout << "Priority Queue (Heap): ";
        for(int i = 1; i <= size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main()
 {
    PriorityQueue pq;

    pq.push(50);
    pq.push(30);
    pq.push(40);
    pq.push(70);
    pq.push(60);
    pq.push(20);

    pq.print();

    cout << "Top element: " << pq.top() << endl;

    pq.pop();
    cout << "After removing top: ";
    pq.print();

    pq.pop();
    cout << "After removing top again: ";
    pq.print();

    return 0;

}