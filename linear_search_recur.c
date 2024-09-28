//  Linear Search using array in recursion form
#include <stdio.h>
int linearSearch(int arr[],int size,int key){
    int i;
    if(size==0)
        return -1;
    else if(arr[size-1]==key)
        return (size-1);
    else
        return linarSearch(arr,size-1,key);
}
int main(){
    int arr[10],key,i,size,result;
    printf("Enter the number of elements: ");
    scanf("%d",&size);
    printf("Enter the elements: ");
    for(i=0;i<size;i++)
        scanf("%d",&arr[i]);
    printf("Enter the element to search: ");
    scanf("%d",&key);
    result = linearSearch(arr,size,key);
    if(result==-1)
        printf("%d element is not found",key);
    else
        printf("Element found at %d position",result+1);
    return 0;
}