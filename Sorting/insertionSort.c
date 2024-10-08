#include <stdio.h>
#define SIZE 10
void insertionSort(int arr[],int size){
    int i,j,key;
    for(i=1;i<size;i++){
        key = arr[i];
        for(j = i - 1;(j>=0 && key<arr[j]);j--)
            arr[j+1] = arr[j];
        arr[j+1] = key;
    }
}
int main(){
    int arr[SIZE],n,i;
    printf("Enter the number of elements of the array: ");
    scanf("%d",&n);
    printf("Enter the elements of the array: ");
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);

    insertionSort(arr,n);

    printf("The sorted list is: \n");
    for(i=0;i<n;i++)
        printf("%d ",arr[i]);

    return 0;
}