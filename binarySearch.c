// Write a c program for binary Search
#include <stdio.h>
int binarySearch(int arr[],int n,int item){
	int low = 0;
	int high = n - 1;
	int mid;
	while(low<=high){
		mid = low + (high-low)/2;
		
		if(arr[mid]==item)
			return mid;
		
		else if(arr[mid]<item)
			low = mid + 1;
		
		else
			high = mid - 1;
	}
	
	return -1;
}
int main(){
	int n,item,i,arr[20];
	printf("Enter the number of elements: ");
	scanf("%d",&n);
	printf("Enter the elements in sorted way: \n");
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	
	printf("Enter the number you want to search: ");
	scanf("%d",&item);
	
	int result = binarySearch(arr,n,item);
	
	if(result==-1)
		printf("Element is not found!");
	else
		printf("Element is found in index no. %d",result);
		
	return 0;
}
