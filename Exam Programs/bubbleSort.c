#include <stdio.h>
void bubbleSorting(int arr[10],int size){
    int i,temp,j;
    for(i=0;i<size-1;i++){
        for(j=0;j<size-1-i;j++){
            if(arr[j]>arr[j+1]){
                temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
        }
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

    bubbleSorting(arr,n);

    printf("\nAfter sorting the array: ");
    displayArray(arr,n);
    return 0;
}