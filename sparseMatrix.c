#include <stdio.h>

#define MAX_SIZE 100  // Define a maximum size for the matrix dimensions

// Function to convert sparse matrix to dense matrix
void sparseToDense(int sparse[][3], int sparseSize, int dense[][MAX_SIZE], int rows, int cols) {
    // Initialize dense matrix with zeros
    int i,j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            dense[i][j] = 0;
        }
    }

    // Populate the dense matrix with non-zero values from sparse matrix
    for (i = 0; i < sparseSize; i++) {
        int row = sparse[i][0];
        int col = sparse[i][1];
        int value = sparse[i][2];
        dense[row][col] = value;
    }
}

int main() {
    // Sparse matrix representation: (row, col, value)
    // Example sparse matrix with 4 non-zero elements
    int sparseMatrix[][3] = {
        {0, 1, 10},
        {1, 0, 20},
        {2, 2, 30},
        {3, 1, 40}
    };
    int i,j;
    int sparseSize = sizeof(sparseMatrix) / sizeof(sparseMatrix[0]);  // Number of non-zero elements
    int rows = 4;  // Number of rows in the original matrix
    int cols = 3;  // Number of columns in the original matrix
    
    // Define the dense matrix
    int denseMatrix[MAX_SIZE][MAX_SIZE];
    
    // Convert sparse matrix to dense matrix
    sparseToDense(sparseMatrix, sparseSize, denseMatrix, rows, cols);
    
    // Print the dense matrix
    printf("Dense Matrix:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d ", denseMatrix[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}

