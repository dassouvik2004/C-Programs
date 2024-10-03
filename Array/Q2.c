// Write a program to find the mean of n numbers using arrays.
#include <stdio.h>
int main(){
    int i, n, arr[10], sum=0;
    float mean = 0.0;
    printf("Enter the number of elements in the array: ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("arr[%d]: ",i);
        scanf("%d",&arr[i]);
    }
    for(i=0;i<n;i++)
        sum += arr[i];

    mean = (float)sum/n;
    printf("The sum of the elements is %d\n",sum);
    printf("The mean of the elements is %.2f\n",mean);
    return 0;
}