#include <stdio.h>

#define MAX_ROWS 100
#define MAX_COLS 100
#define MAX_NON_ZERO 100

// Function to convert sparse matrix to dense matrix
void sparseToDense(int sparse[][3], int sparseSize, int rows, int cols, int dense[MAX_ROWS][MAX_COLS]) {
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
    int i,j,rows, cols, numNonZero;

    // Input the dimensions of the matrix
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    // Ensure rows and cols are within predefined limits
    if (rows > MAX_ROWS || cols > MAX_COLS) {
        printf("Matrix dimensions exceed maximum allowed sizes.\n");
        return 1;
    }

    // Input the number of non-zero elements
    printf("Enter the number of non-zero elements: ");
    scanf("%d", &numNonZero);

    // Ensure number of non-zero elements is within predefined limit
    if (numNonZero > MAX_NON_ZERO) {
        printf("Number of non-zero elements exceeds maximum allowed size.\n");
        return 1;
    }

    // Define the sparse matrix array
    int sparseMatrix[MAX_NON_ZERO][3];

    // Input sparse matrix elements
    printf("Enter the row, column, and value for each non-zero element:\n");
    for (i = 0; i < numNonZero; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d %d %d", &sparseMatrix[i][0], &sparseMatrix[i][1], &sparseMatrix[i][2]);
    }

    // Define the dense matrix array
    int denseMatrix[MAX_ROWS][MAX_COLS];

    // Convert sparse matrix to dense matrix
    sparseToDense(sparseMatrix, numNonZero, rows, cols, denseMatrix);

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

