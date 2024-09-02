// Write a c program for modified bubble sort
#include <stdio.h>
void createArray(int arr[],int size){
	int i;
	for(i=0;i<size;i++){
		scanf("%d",&arr[i]);
	}
}

void modifiedBubbleSort(int arr[],int size){
	int i,j,temp,flag=0;
	for(i=0;i<size-1;i++){
		for(j=0;j<size-1-i;j++){
			if(arr[j]>arr[j+1]){
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
				flag = 1;
			}
		}
		if(flag==0)
			break;
	}
}
void displayArray(int arr[],int size){
	int i;
	for(i=0;i<size;i++){
		printf("%d\t",arr[i]);
	}
}
int main(){
	int i,data[20],n;
	printf("Enter the number of elements: ");
	scanf("%d",&n);
	
	printf("Enter the elements: \n");
	createArray(data,n);
	printf("Before sorting: \n");
	displayArray(data,n);
	modifiedBubbleSort(data,n);
	printf("\nAfter sorting: \n");
	displayArray(data,n);
	
	return 0;
}
