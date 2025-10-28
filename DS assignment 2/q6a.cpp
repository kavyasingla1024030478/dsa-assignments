#include <iostream>

using namespace std;

// Struct to represent a triplet (row, col, value)
struct Triplet {
    int row;
    int col;
    int value;
};

// Function to print a sparse matrix in triplet form
void printSparseMatrix(Triplet sparseMatrix[], int numNonZero) {
    if (numNonZero < 0) {
        return;
    }
    cout << "Row\tCol\tValue" << endl;
    for (int i = 0; i <= numNonZero; ++i) {
        cout << sparseMatrix[i].row << "\t" << sparseMatrix[i].col << "\t" << sparseMatrix[i].value << endl;
    }
    cout << endl;
}

// Function to transpose a sparse matrix
void transposeSparseMatrix(Triplet original[], Triplet transposed[]) {
    int originalRows = original[0].row;
    int originalCols = original[0].col;
    int numNonZero = original[0].value;

    transposed[0].row = originalCols;
    transposed[0].col = originalRows;
    transposed[0].value = numNonZero;

    // Transpose non-zero elements by swapping row and col
    for (int i = 1; i <= numNonZero; ++i) {
        transposed[i].row = original[i].col;
        transposed[i].col = original[i].row;
        transposed[i].value = original[i].value;
    }

    // Sort the transposed matrix using the provided bubble sort logic
    // We sort the triplets from index 1 to numNonZero
    for (int i = numNonZero; i >= 1; i--) {
        for (int j = 1; j <= i - 1; j++) {
            // Compare based on row first, then column
            if (transposed[j].row > transposed[j + 1].row || 
               (transposed[j].row == transposed[j + 1].row && transposed[j].col > transposed[j + 1].col)) {
                
                // Swap the entire Triplet structs
                Triplet temp = transposed[j + 1];
                transposed[j + 1] = transposed[j];
                transposed[j] = temp;
            }
        }
    }
}

int main() {
    Triplet originalMatrix[100];
    originalMatrix[0] = {5, 6, 6};
    originalMatrix[1] = {0, 0, 15};
    originalMatrix[2] = {0, 3, 22};
    originalMatrix[3] = {0, 5, -15};
    originalMatrix[4] = {1, 1, 11};
    originalMatrix[5] = {1, 4, 3};
    originalMatrix[6] = {4, 2, 91};

    cout << "Original Sparse Matrix (Triplet Form):" << endl;
    printSparseMatrix(originalMatrix, originalMatrix[0].value); 

    Triplet transposedMatrix[100];

    transposeSparseMatrix(originalMatrix, transposedMatrix);

    cout << "Transposed Sparse Matrix (Triplet Form):" << endl;
    printSparseMatrix(transposedMatrix, transposedMatrix[0].value);

    return 0;
}