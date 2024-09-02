#include <stdio.h>
#include <stdlib.h>
int main(){
	int* ptr,i,n,k;
	printf("Enter the size of elements: ");
	scanf("%d",&n);
	ptr = (int*)calloc(n,sizeof(int));
	
	if(ptr==NULL){
		printf("Memory not allocated.\n");
		return 0;
	}
	else
		printf("Memory allocated successfully using calloc.\n");
		
	for(i=0;i<n;i++){
		ptr[i] = i + 1;
	}
	
	printf("The elements are: ");
	for(i=0;i<n;i++){
		printf("%d ", *(ptr+i));
	}
	printf("\n");
	
	printf("Enter the new size of the elements: ");
	scanf("%d",&k);
	
	ptr = (int*)realloc(ptr,k*sizeof(int));
	
	if(ptr==NULL){
		printf("Memory not allocated.\n");
		return 0;
	}
	else
		printf("Memory allocated successfully using realloc.\n");
	
	for(i=n;i<k;i++){
		ptr[i] = i + 1;
	}
	
	printf("The new elements are: ");
	for(i=0;i<k;i++){
		printf("%d ",*(ptr+i));
	}
	
	free(ptr);
	
	return 0;
}
