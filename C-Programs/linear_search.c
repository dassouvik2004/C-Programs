// Write a c program for linear search
#include <stdio.h>
int linearSearch(int arr[],int n, int item){
    int i;
    for(i=0;i<n;i++){
        if(arr[i]==item)
            return i;
    }
    return -1;
}
int main(){
    int n,item,i,data[20];
	printf("Enter the number of elements: ");
	scanf("%d",&n);
	printf("Enter the elements in unsorted/sorted way: \n");
	for(i=0;i<n;i++)
		scanf("%d",&data[i]);
	printf("Enter the element you want to search: ");
	scanf("%d",&item);
    int result = linearSearch(data,n,item);
    if(result==-1){
        printf("Element is not found");
    }
    else{
        printf("Element is found in index no. %d",result);
    }
}
