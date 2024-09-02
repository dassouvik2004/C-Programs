#include <stdio.h>
int main(){
	int r,c,i,j,sum;
	printf("Enter the number of rows and columns: ");
	scanf("%d %d",&r,&c);
	int arr[r][c];
	printf("Enter elements of the 2D array: \n");
	for(i=0;i<r;i++){
		for(j=0;j<c;j++){
			scanf("%d",&arr[i][j]);
		}
	}
	printf("The given array in 2D array is: \n");
	for(i=0;i<r;i++){
		for(j=0;j<c;j++){
			printf("%d\t",arr[i][j]);
		}
		printf("\n");
	}
	for(i=0;i<r;i++){
		sum=0;
		for(j=0;j<c;j++){
			sum += arr[i][j];
		
		}
		printf("Sum of elements in row %d = %d\n",i+1,sum);
	}
	return 0;
}
