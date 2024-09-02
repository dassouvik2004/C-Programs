//Write a c program for selection sort
#include <stdio.h>
void printArray(int arr[],int size){
    int i;
    for(i=0;i<size;i++){
        printf("%d\t",arr[i]);
    }
    printf("\n");
}
void selectionArray(int arr[], int size){
    int i,p,j,temp;
    for(i=0;i<size-1;i++){
        p = i;
            
        for(j=i+1;j<size;j++){
            if(arr[j]<arr[p]){
                	p = j;
            }
        }
    temp = arr[i];
    arr[i] = arr[p];
    arr[p] = temp;
    }
}
int main(){
	int i,size,data[20];
	printf("Enter the number of elements: ");
	scanf("%d",&size);
	printf("Enter the elements:\n");
	for(i=0;i<size;i++)
		scanf("%d",&data[i]);
	
	printf("Unsorted array:\n");
	printArray(data,size);
    selectionArray(data,size);
    printf("Sorted array:\n");
    printArray(data,size);
    
    return 0;
}
