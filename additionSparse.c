#include <stdio.h>
#define MAX 100

void inputSparse(int arr[7][5]) {
    int i, j;
    for (i = 0; i < 7; i++) {
        for (j = 0; j < 5; j++)
            scanf("%d", &arr[i][j]);
    }
}

void displaySparse(int arr[7][5]) {
    int i, j;
    for (i = 0; i < 7; i++) {
        for (j = 0; j < 5; j++)
            printf("%d ", arr[i][j]);
        printf("\n");
    }
}

void Original2Sparse(int original[7][5], int sparse[MAX][3]) {
    int i, j, k = 1;
    sparse[0][0] = 7; // Number of rows
    sparse[0][1] = 5; // Number of columns
    sparse[0][2] = 0; // Initialize number of non-zero elements to 0

    for (i = 0; i < 7; i++) {
        for (j = 0; j < 5; j++) {
            if (original[i][j] != 0) {
                sparse[k][0] = i;
                sparse[k][1] = j;
                sparse[k][2] = original[i][j];
                k++;
                sparse[0][2]++;
            }
        }
    }
}

void display2Sparse(int p[MAX][3]) {
    int i, j;
    for (i = 0; i <= p[0][2]; i++) {
        for (j = 0; j < 3; j++)
            printf("%d ", p[i][j]);
        printf("\n");
    }
}

int main() {
    int x[7][5] = {0}, y[7][5] = {0}, z[7][5] = {0};
    int p[MAX][3], q[MAX][3], r[MAX][3];
    
    printf("Enter values for 1st matrix: \n");
    inputSparse(x);

    Original2Sparse(x, p);

    printf("The Original Sparse is: \n");
    displaySparse(x);

    printf("The converted Sparse is: \n");
    display2Sparse(p);

    return 0;
}
