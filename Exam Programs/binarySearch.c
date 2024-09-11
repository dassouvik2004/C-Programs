#include <stdio.h>
int binarySearch(int arr[],int size,int key){
    int low = 0, high = size - 1, mid;
    while(low<=high){
        mid = low + (high-low)/2;
        if(arr[mid]==key)
            return mid;
        else if(arr[mid]<key)
            low = mid + 1;
        else   
            high = mid - 1;
    }
    return -1;
}
int main(){
    int result,size,arr[10],key,i;
    printf("Enter the number of elements: ");
    scanf("%d",&size);
    printf("Enter the elements in sorted way: ");
    for(i=0;i<size;i++)
        scanf("%d",(arr+i));
    
    printf("Enter the element to search: ");
    scanf("%d",&key);

    result = binarySearch(arr,size,key);

    if(result==-1)
        printf("Element is not found.\n");
    else   
        printf("Element is found at index no. %d",result);

    return 0;
}