// Write a program to read and display n numbers using an array.
#include <stdio.h>
int main(){
    int n,i,arr[10];
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("arr[%d] = ",i);
        scanf("%d",&arr[i]);
    }
    printf("The array elements are:");
    for(i=0;i<n;i++)
        printf("\t%d",arr[i]);
    printf("\n");

    return 0;
}