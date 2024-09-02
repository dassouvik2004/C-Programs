#include <stdio.h>
int main(){
	int mat[10][10],i,j,row,col;
	printf("Enter the number of rows: ");
	scanf("%d",&row);
	printf("Enter the number of columns: ");
	scanf("%d",&col);
	
	printf("Enter %d x %d numbers\n",row,col);
	for(i=0;i<row;i++){
		for(j=0;j<col;j++){
			scanf("%d", &mat[i][j]);
		}
	}
	
	printf("The matrix is: \n");
	for(i=0;i<row;i++){
		for(j=0;j<col;j++){
			printf("%d ",mat[i][j]);
		}
		printf("\n");
	}
	return 0;
}
