#include <stdio.h>
void createMatrix(int mat[20][20],int rw,int col){
	int i,j;
	for(i=0;i<rw;i++){
		for(j=0;j<col;j++){
			scanf("%d",&mat[i][j]);
		}
	}
}
void sumMatrix(int a[20][20],int b[20][20],int c[20][20],int rw, int col){
	int i,j;
	for(i=0;i<rw;i++){
		for(j=0;j<col;j++){
			c[i][j] = a[i][j] + b[i][j];
		}
	}
}
void displayMatrix(int mat[20][20],int rw,int col){
	int i,j;
	for(i=0;i<rw;i++){
		for(j=0;j<col;j++){
			printf("%d\t",mat[i][j]);
		}
		printf("\n");
	}
}

int main(){
	int a[20][20],b[20][20],c[20][20],rw,col;
	printf("Enter the rows and columns: ");
	scanf("%d %d",&rw,&col);
	
	printf("Enter the first matrix: \n");
	createMatrix(a,rw,col);
	
	printf("Enter the second matrix: \n");
	createMatrix(b,rw,col);
	
	sumMatrix(a,b,c,rw,col);
	
	printf("The first matrix is: \n");
	displayMatrix(a,rw,col);
	
	printf("The second matrix is: \n");
	displayMatrix(b,rw,col);
	
	printf("Resultant Matrix: \n");
	displayMatrix(c,rw,col);
	
	return 0;
}
