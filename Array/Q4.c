// Write a program to find the second largest of n numbers using an array.
#include <stdio.h>
int main(){
    int n,arr[10],i,large,second_large;
    printf("Enter the number of the elements: ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("arr[%d]: ",i);
        scanf("%d",&arr[i]);
    }
    large = arr[0];
    for(i=1;i<n;i++){
        if(arr[i]>large)
            large = arr[i];
    }
    second_large = arr[1];
    for(i=0;i<n;i++){
        if(arr[i]!=large){
            if(arr[i]>second_large)
                second_large = arr[i];
        }
    }
    printf("The numbers you entered are: ");
    for(i=0;i<n;i++)
        printf("\t%d",arr[i]);
    printf("\nThe largest element of the array: %d",large);
    printf("\nThe second largest element of the array: %d",second_large);
    return 0;
}