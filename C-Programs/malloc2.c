#include <stdio.h>
#include <stdlib.h>
int main(){
	int *p,n,max,k,i;
	printf("Enter number of elements: ");
	scanf("%d",&n);
	p = (int*)malloc(n*sizeof(int));
	if(p==NULL){
		printf("Allocation not possible!\n");
		return -1;
	}
	printf("Enter %d elements: \n",n);
	for(i=0;i<n;i++)
		scanf("%d",p+i);
	
	printf("The %d elements are: \n",n);
	for(i=0;i<n;i++)
		printf("%d ",*(p+i));
	printf("\n");
	max = *p;
	for(i=1;i<n;i++){
		if(*(p+i)>max)
			max = p[i];
	}
	printf("Max element is %d\n",max); 
	
	printf("Do you want to add more elements?\nEnter the new total number of elements (current: %d): ",n);
	scanf("%d",&k);
	
	if(k>n){
		p = (int*)realloc(p,k*sizeof(int));
	
		if(p==NULL){
			printf("Allocation is not possible!");
			return 0;
		}
	printf("Enter additional %d elements: ",k-n);
	for(i=n;i<k;i++)
		scanf("%d",p+i);
	
	printf("\nNow the elements are: ");
	for(i=0;i<k;i++)
		printf("%d ",*(p+i));
	
	for(i=n;i<k;i++){
		if(p[i]>max)
			max = *(p+i);
	}
	printf("\nNow the maximum element is: %d",max);
	}
	else
		printf("No additional elements were added.\n");
	free(p);
	return 0;
}
