// Write a program to print the position of the smallest number of n numbers using arrays.
#include <stdio.h>
int main(){
    int n,small,arr[10],i,pos;
    printf("Enter the number of elements of the array: ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("arr[%d]: ",i);
        scanf("%d",&arr[i]);
    }
    small = arr[0];
    pos = 0;
    for(i=1;i<n;i++){
        if(arr[i]<small){
            small = arr[i];
            pos = i;
        }
    }
    printf("The smallest element of the array: %d\n",small);
    printf("The position of the smallest element of the array: %d\n",pos+1);
    return 0;
}