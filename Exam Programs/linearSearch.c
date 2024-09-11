#include <stdio.h>
int linearSearch(int arr[],int size,int key){
    int i;
    for(i=0;i<size;i++){
        if(arr[i]==key)
            return i;
    }
    return -1;
}
int main(){
    int result,arr[10],size,key,i;
    printf("Enter the number of elements: ");
    scanf("%d",&size);
    printf("Enter the elements: ");
    for(i=0;i<size;i++)
        scanf("%d",(arr+i));

    printf("Enter the element to search: ");
    scanf("%d",&key);

    result = linearSearch(arr,size,key);

    if(result==-1)
        printf("Element is not found.\n");
    else   
        printf("Element found at index no. %d",result);

    return 0;
}