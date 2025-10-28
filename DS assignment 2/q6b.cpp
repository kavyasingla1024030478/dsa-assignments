#include <iostream>
#include <vector>

using namespace std;

// Struct to represent a triplet (row, col, value)
struct Triplet {
    int row;
    int col;
    int value;
};

// Function to print a sparse matrix in triplet form
void printSparseMatrix(vector<Triplet>& sparseMatrix) {
    if (sparseMatrix.empty()) {
        cout << "Matrix is empty." << endl;
        return;
    }
    cout << "Row\tCol\tValue" << endl;
    for (size_t i = 0; i < sparseMatrix.size(); ++i) {
        cout << sparseMatrix[i].row << "\t" << sparseMatrix[i].col << "\t" << sparseMatrix[i].value << endl;
    }
    cout << endl;
}

// Function to add two sparse matrices
vector<Triplet> addSparseMatrices(vector<Triplet>& matrix1, vector<Triplet>& matrix2) {
    // Check for dimension compatibility
    if (matrix1.empty() || matrix2.empty() ||
        matrix1[0].row != matrix2[0].row ||
        matrix1[0].col != matrix2[0].col) {
        cout << "Error: Matrices have incompatible dimensions." << endl;
        return {};
    }

    vector<Triplet> result;
    
    // The header of the result matrix will have the same dimensions
    result.push_back({matrix1[0].row, matrix1[0].col, 0});

    size_t i = 1, j = 1;
    int numNonZero = 0;

    // Merge the non-zero elements from both matrices
    while (i < matrix1.size() && j < matrix2.size()) 
    {
        if (matrix1[i].row < matrix2[j].row ||
            (matrix1[i].row == matrix2[j].row && matrix1[i].col < matrix2[j].col)) {
            // Add element from matrix1
            result.push_back(matrix1[i]);
            numNonZero++;
            i++;
        } else if (matrix2[j].row < matrix1[i].row ||
                   (matrix2[j].row == matrix1[i].row && matrix2[j].col < matrix1[i].col)) {
            // Add element from matrix2
            result.push_back(matrix2[j]);
            numNonZero++;
            j++;
        } else {
            // Both matrices have a non-zero element at the same position. Add their values.
            int sum = matrix1[i].value + matrix2[j].value;
            if (sum != 0) {
                result.push_back({matrix1[i].row, matrix1[i].col, sum});
                numNonZero++;
            }
            i++;
            j++;
        }
    }

    // Add any remaining elements from matrix1
    while (i < matrix1.size()) {
        result.push_back(matrix1[i]);
        numNonZero++;
        i++;
    }

    // Add any remaining elements from matrix2
    while (j < matrix2.size()) {
        result.push_back(matrix2[j]);
        numNonZero++;
        j++;
    }

    // Update the header with the final count of non-zero elements
    result[0].value = numNonZero;

    return result;
}

int main() {
    // Matrix 1: 4x5 with 4 non-zero elements
    vector<Triplet> matrix1 = {
        {4, 5, 4},
        {0, 0, 10},
        {1, 2, 20},
        {2, 3, 30},
        {3, 4, 40}
    };

    // Matrix 2: 4x5 with 4 non-zero elements
    vector<Triplet> matrix2 = {
        {4, 5, 4},
        {0, 0, 15},
        {1, 3, 25},
        {2, 3, 35},
        {3, 4, 45}
    };

    cout << "Matrix 1:" << endl;
    printSparseMatrix(matrix1);

    cout << "Matrix 2:" << endl;
    printSparseMatrix(matrix2);

    vector<Triplet> sumMatrix = addSparseMatrices(matrix1, matrix2);

    if (!sumMatrix.empty()) {
        cout << "Sum Matrix:" << endl;
        printSparseMatrix(sumMatrix);
    }

    return 0;
}