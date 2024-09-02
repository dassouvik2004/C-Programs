#include <stdio.h>
void createMatrix(int mat[20][20],int rw,int col){
	int i,j;
	for(i=0;i<rw;i++){
		for(j=0;j<col;j++){
			scanf("%d",&mat[i][j]);
		}
	}
}

void transposeMatrix(int mat[20][20],int trans[20][20],int rw,int col){
	int i,j;
	for(i=0;i<rw;i++){
		for(j=0;j<col;j++){
			trans[j][i] = mat[i][j];
		}
	}
}

void displayMatrix(int matrix[20][20],int rw,int col){
	int i,j;
	for(i=0;i<rw;i++){
		for(j=0;j<col;j++){
			printf("%d\t",matrix[i][j]);
		}
		printf("\n");
	}
}
int main(){
	int mat[20][20],trans[20][20],rw,col;
	printf("Enter the rows and columns: ");
	scanf("%d %d",&rw,&col);
	
	printf("Enter the matrix: \n");
	createMatrix(mat,rw,col);
	
	transposeMatrix(mat,trans,rw,col);
	
	printf("The matrix is: \n");
	displayMatrix(mat,rw,col);
	
	printf("The Transpose matrix is: \n");
	displayMatrix(trans,col,rw);
	
	return 0;
	
}
