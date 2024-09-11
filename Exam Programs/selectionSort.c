#include <stdio.h>
void selectionSort(int arr[10],int size){
    int i,temp,j,min_idx;
    for(i=0;i<size-1;i++){
        min_idx = i;
        for(j=i+1;j<size;j++){
            if(arr[j]<arr[min_idx]){
                min_idx = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;
    }
}
void displayArray(int arr[10],int size){
    int i;
    for(i=0;i<size;i++)
        printf("%d\t",arr[i]);
}
int main(){
    int arr[10],n,i;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    printf("Enter the elements: ");
    for(i=0;i<n;i++)
        scanf("%d",arr+i);

    printf("Before sorting the array: ");
    displayArray(arr,n);

    selectionSort(arr,n);

    printf("\nAfter sorting the array: ");
    displayArray(arr,n);
    return 0;
}