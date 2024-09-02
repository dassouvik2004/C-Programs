//Write a c program for insertion sort
#include <stdio.h>
void printArray(int arr[],int size){
    int i;
    for(i=0;i<size;i++){
        printf("%d\t",arr[i]);
    }
    printf("\n");
}
void insertionArray(int arr[],int size){
    int i,key,j;
    for(i=1;i<size;i++){
        key = arr[i];
        j = i - 1;
    
    while(key<arr[j]&&j>=0){
        arr[j+1] = arr[j];
        j--;
    }
    arr[j+1] = key;
    }
}
int main(){
    int i,size,data[20];
	printf("Enter the number of elements: ");
	scanf("%d",&size);
	printf("Enter the elements:\n");
	for(i=0;i<size;i++)
		scanf("%d",&data[i]);
	printf("Before sorting: \n");
	printArray(data,size);
    insertionArray(data,size);
    printf("After sorting: \n");
    printArray(data,size);
}
