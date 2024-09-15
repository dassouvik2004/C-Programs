#include <stdio.h>
#include <ctype.h>

void inputSparse(int a[][3]){
    int rw, col, val, index = 1; 
    char ch = 'Y';
    
    printf("Enter the total rows and columns of the matrix:\n");
    scanf("%d %d", &a[0][0], &a[0][1]);  // Store row and column sizes in a[0]
    
    while(toupper(ch) == 'Y'){
        printf("Enter the row: ");
        scanf("%d", &rw);
        printf("Enter the column: ");
        scanf("%d", &col);
        printf("Enter the value: ");
        scanf("%d", &val);

        if(rw < a[0][0] && col < a[0][1]){
            if (val != 0) {
                a[index][0] = rw;
                a[index][1] = col;
                a[index][2] = val;
                index++;
            }
        } else {
            printf("Row or column exceeds matrix size. Try again.\n");
        }

        printf("Continue (Y/N)? ");
        while(getchar() != '\n') {}  // To clear the buffer
        scanf("%c", &ch);
    }

    a[0][2] = index - 1;  // Store the number of non-zero elements in a[0][2]
}

void createSparse(int a[][3], int b[30][30]){
    int i;
    for(i = 1; i <= a[0][2]; i++){
        int row = a[i][0];
        int column = a[i][1];
        int value = a[i][2];
        b[row][column] = value;
    }
}

void displayOriginal(int b[30][30], int rw, int col){
    int i, j;
 