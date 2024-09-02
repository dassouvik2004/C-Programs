#include <stdio.h>
#include <stdlib.h>
int main(){
	int* ptr,i,n,sum=0;
	printf("Enter the number of terms: ");
	scanf("%d",&n);
	
	ptr = (int*)malloc(n*sizeof(int));
	
	if(ptr==NULL){
		printf("Error!Memory not allocated.\n");
	}
	
	printf("Enter the numbers: ");
	for(i=0;i<n;i++){
		scanf("%d",(ptr+i));
		sum = sum + ptr[i];
	}
	
	printf("Sum of the numbers: %d",sum);
	
	free(ptr);
	return 0;
}
