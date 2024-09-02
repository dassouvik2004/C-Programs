#include <stdio.h>
int main(){
	int a[20][20],b[20][20],c[20][20]={0},sum=0,i,j,k,r1,c1,r2,c2;
	printf("Enter the row and column for first matrix: ");
	scanf("%d %d",&r1,&c1);
	printf("Enter the first matrix: \n");
	for(i=0;i<r1;i++){
		for(j=0;j<c1;j++){
			scanf("%d",&a[i][j]);
	}
	}
	printf("\n");
	
	printf("The first matrix is: \n");
	for(i=0;i<r1;i++){
		for(j=0;j<c1;j++){
			printf("%d\t",a[i][j]);
		}
		printf("\n");
	}
	
	printf("Enter the row and column for second matrix: ");
	scanf("%d %d",&r2,&c2);
	if(r2!=c1){
		printf("Error!First matrix column & second matrix row should be equal.\n");
		return 1;
	}
	else{
	printf("Enter the second matrix: \n");
	for(i=0;i<r2;i++){
		for(j=0;j<c2;j++){
			scanf("%d",&b[i][j]);
		}
	}
	}
	printf("\n");
	
	printf("The second matrix is: \n");
	for(i=0;i<r2;i++){
		for(j=0;j<c2;j++){
			printf("%d\t",b[i][j]);
		}
		printf("\n");
	}
	
//	for(i=0;i<r2;i++){
//		for(j=0;j<c2;j++{
//			c[i][j] = 0;
//	}
	
	for(i=0;i<r1;i++){
		for(j=0;j<c2;j++){
			for(k=0;k<r2;k++){
				sum += a[i][k]*b[k][j];
			}
			c[i][j]=sum;
			sum = 0;
		}
	}
	printf("\n");
	printf("Resultant Matrix is: \n");
	for(i=0;i<r1;i++){
		for(j=0;j<c2;j++){
			printf("%d\t",c[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}
