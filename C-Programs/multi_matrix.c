#include <stdio.h>
void createMatrix(int mat[20][20],int rw,int col){
	int i,j;
	for(i=0;i<rw;i++){
		for(j=0;j<col;j++){
			scanf("%d",&mat[i][j]);
		}
	}
}
void multiMatrix(int a[20][20],int b[20][20],int c[20][20],int r1,int c2,int r2){
	int i,sum=0,j,k;
	for(i=0;i<r1;i++){
		for(j=0;j<c2;j++){
			for(k=0;k<r2;k++){
				sum += a[i][k] * b[k][j];
			}
			c[i][j] = sum;
			sum = 0;
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
	int a[20][20],b[20][20],c[20][20],r1,r2,c1,c2;
	printf("Enter the rows and columns for first matrix: ");
	scanf("%d %d",&r1,&c1);
	printf("Enter the elements of first matrix: \n");
	createMatrix(a,r1,c1);
	
	printf("Enter the rows and columns for second matrix: ");
	scanf("%d %d",&r2,&c2);
	if(r2!=c1){
		printf("Error! First matrix column and second matrix row must be equal!");
		return 1;
	}
	else{
		printf("Enter the numbers of second matrix: \n");
		createMatrix(b,r2,c2);
	}
	multiMatrix(a,b,c,r1,c2,r2);
	
	printf("The first matrix is: \n");
	displayMatrix(a,r1,c1);
	
	printf("The second matrix is: \n");
	displayMatrix(b,r2,c2);
	
	printf("The Resultant Matrix is: \n");
	displayMatrix(c,r1,c2);
	
	return 0;
	
}
