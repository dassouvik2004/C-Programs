// Binary Search using array in recursive form
#include <stdio.h>
int binarySearch(int arr[],int low,int high,int key){
    if(low<=high){
        int mid = (high+low)/2;
        if(arr[mid]==key)
            return mid;
        else if(key>arr[mid])
            return binarySearch(arr,mid+1,high,key);
        else
            return binarySearch(arr,low,mid-1,key);
    }
    return -1;
}
int main(){
    int size,arr[10],i,key,result;
    printf("Enter the number of elements: ");
    scanf("%d",&size);
    printf("Enter the elements in ascending/descending order: \n");
    for(i=0;i<size;i++)
        scanf("%d",&arr[i]);
    printf("Enter the element to search: ");
    scanf("%d",&key);
    result = binarySearch(arr,0,size-1,key);
    if(result==-1)
        printf("%d element is not found.\n",key);
    else
        printf("Element is found at postion %d.",result+1);
    return 0;
}