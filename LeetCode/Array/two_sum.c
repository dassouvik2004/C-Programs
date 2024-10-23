/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <stdlib.h>
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int *result = (int*)malloc(2*sizeof(int));
    int i,j;
    for(i=0;i<numsSize-1;i++){
       for(j=i+1;j<numsSize;j++){
            if(nums[i]+nums[j] == target){
                result[0] = i;
                result[1] = j;

                *returnSize = 2;

                return result;
            } 
        }
    }
    *returnSize = 0;
    return NULL;
}
int main(){
    int num[] ={2,7,11,15};
    int target = 9;
    int returnSize;

    int *result = twoSum(num,4,9,&returnSize);

    if(returnSize==2)
        printf("Indices: [%d, %d]\n", result[0], result[1]);
    else
        printf("No solution found\n");

    free(result);

    return 0;
}