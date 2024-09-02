#include <stdio.h>
#include <stdlib.h>
int main(){
	int* ptr,i,n;
	printf("Enter the number of elements: ");
	scanf("%d",&n);
	ptr = (int*) malloc(n*sizeof(int));
	
	if(ptr==NULL)
		printf("Memory not allocated");
	else
		printf("Memory allocated successfully using malloc.\n");
	
	for(i=0;i<n;i++){
		ptr[i] = i+1;
	}
	
	printf("The elements are: ");
	for(i=0;i<n;i++){
		printf("%d ",*(ptr+i));
	}
	free(ptr);
	
	return 0;
}
