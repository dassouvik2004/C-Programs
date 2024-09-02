#include <stdio.h>
int main(){
	int mat[20][20], trans[20][20],row,col,i,j;
	printf("Enter the number of rows and columns: ");
	scanf("%d %d",&row,&col);
	
	printf("\n");
	
	printf("Enter the elements of matrix: \n");
	for(i=0;i<row;i++){
		for(j=0;j<col;j++){
			scanf("%d",&mat[i][j]);
		}
	}
	
	printf("\n");
	
	printf("The matrix is: \n");
	for(i=0;i<row;i++){
		for(j=0;j<col;j++){
			printf("%d\t",mat[i][j]);
		}
		printf("\n");
	}
	
	for(i=0;i<row;i++){
		for(j=0;j<col;j++){
			trans[j][i] = mat[i][j];
		}
	}
	
	printf("\n");
	
	printf("The transpose matrix is: \n");
	for(i=0;i<col;i++){
		for(j=0;j<row;j++){
			printf("%d\t",trans[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}
