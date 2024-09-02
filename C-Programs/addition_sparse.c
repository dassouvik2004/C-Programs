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
            printf("%d\t", arr[i][j]);
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

void addSparse(int a[MAX][3], int b[MAX][3], int c[MAX][3]) {
    int i = 1, j = 1, k = 1;
    while (i <= a[0][2] && j <= b[0][2]) {
        if (a[i][0] < b[j][0] || (a[i][0] == b[j][0] && a[i][1] < b[j][1])) {
            c[k][0] = a[i][0];
            c[k][1] = a[i][1];
            c[k][2] = a[i][2];
            k++;
            i++;
        } else if (b[j][0] < a[i][0] || (b[j][0] == a[i][0] && b[j][1] < a[i][1])) {
            c[k][0] = b[j][0];
            c[k][1] = b[j][1];
            c[k][2] = b[j][2];
            k++;
            j++;
        } else {
            c[k][0] = a[i][0];
            c[k][1] = a[i][1];
            c[k][2] = a[i][2] + b[j][2];
            k++;
            i++;
            j++;
        }
    }

    while (i <= a[0][2]) {
        c[k][0] = a[i][0];
        c[k][1] = a[i][1];
        c[k][2] = a[i][2];
        k++;
        i++;
    }

    while (j <= b[0][2]) {
        c[k][0] = b[j][0];
        c[k][1] = b[j][1];
        c[k][2] = b[j][2];
        k++;
        j++;
    }

    c[0][0] = a[0][0]; // Number of rows
    c[0][1] = a[0][1]; // Number of columns
    c[0][2] = k - 1;   // Number of non-zero elements
}

void sparse2Original(int sparse[][3],int original[7][5]){
	int i,j;
	for(i=0;i<=sparse[0][2];i++){
		int row = sparse[i][0];
		int column = sparse[i][1];
		int value = sparse[i][2];
		original[row][column] = value;
	}
}

void display2Sparse(int sparse[MAX][3]) {
    int i,j;
    for (i = 0; i <= sparse[0][2]; i++) {
        for (j = 0; j < 3; j++)
            printf("%d ", sparse[i][j]);
        printf("\n");
    }
}

int main() {
    int x[7][5] = {0}, y[7][5] = {0}, z[7][5] = {0};
    int p[MAX][3], q[MAX][3], r[MAX][3];
    
    printf("Enter values for 1st matrix: \n");
    inputSparse(x);
    
    printf("Enter values for 2nd matrix: \n");
    inputSparse(y);

    Original2Sparse(x, p);
    Original2Sparse(y, q);
    
    addSparse(p, q, r);
    
    sparse2Original(r,z);
    
    printf("The first Sparse Matrix is: \n");
    display2Sparse(p);

    printf("The second Sparse Matrix is: \n");
    display2Sparse(q);
	
	printf("The result Sparse Matrix is: \n");
    display2Sparse(r);
	
    printf("The result original Sparse Matrix is: \n");
    displaySparse(z);

    return 0;
}
