#include <stdio.h>
int maxSum(int arr[],int size, int k){
    int max_sum = 0,current_sum = 0;
    if(size<=k){
        printf("Invalid\n");
        return -1;
    }
    int i;
    for(i=0;i<k;i++)
        max_sum += arr[i];
    
    current_sum = max_sum;
    
    for(i = k;i < size; i++){
        current_sum += arr[i] - arr[i-k];
        if(current_sum>max_sum)
            max_sum = current_sum;
    }
    return max_sum;
}
int main(){
    int i,size,arr[10],k;
    printf("Enter the number of elements: ");
    scanf("%d",&size);
    printf("Enter the elements: \n");
    for(i=0;i<size;i++)
        scanf("%d",(arr+i));
    printf("Enter the size of sub-array: ");
    scanf("%d",&k);
    printf("The maximum sum of subarray size of %d: %d\n",k,maxSum(arr,size,k));
    return 0;
}