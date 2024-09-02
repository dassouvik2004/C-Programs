#include <stdio.h>
int createMatrix(int mat[20][20], int rw, int col) {
    int i, j, Count = 0;
    for(i = 0; i < rw; i++) {
        for(j = 0; j < col; j++) {
            scanf("%d", &mat[i][j]);
            if(mat[i][j] == 0) {
                Count++;
            }
        }
    }
    return Count;
}

void displayMatrix(int mat[20][20], int rw, int col) {
    int i, j;
    for(i = 0; i < rw; i++) {
        for(j = 0; j < col; j++) {
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }
}
int main() {
    int mat[20][20], rw, col, count;

    printf("Enter the rows and columns of the matrix: ");
    scanf("%d %d", &rw, &col);

    printf("Enter the elements:\n");
	count = createMatrix(mat, rw, col);
	
    printf("The matrix is:\n");
    displayMatrix(mat, rw, col);
    
    if(count >(rw*col)/2)
        printf("The matrix is a sparse matrix.\n");
  	
	else
        printf("The matrix is not a sparse matrix.\n");

    return 0;
}
