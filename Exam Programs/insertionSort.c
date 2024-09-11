#include <stdio.h>
void insertionSort(int arr[],int size){
    int step,key,i;
    for(step=1;step<size;step++){
        key = arr[step];
        for(i = step -1;i>=0 && arr[i]>key;i--)
            arr[i+1] = arr[i];
        arr[i+1] = key;
    }
}
void displayArray(int arr[],int size){
    int i;
    for(i=0;i<size;i++)
        printf("%d\t",arr[i]);
}
int main(){
    int size,i,arr[10];
    printf("Enter the number of elements: ");
    scanf("%d",&size);
    printf("Enter the elements: ");
    for(i=0;i<size;i++)
        scanf("%d",(arr+i));
    
    printf("Before sorting the array: ");
    displayArray(arr,size);

    insertionSort(arr,size);

    printf("\nAfter sorting the array: ");
    displayArray(arr,size);
    return 0;
}