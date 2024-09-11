#include <stdio.h>
void modifiedBubble(int arr[],int size){
    int step,i,temp;
    for(step=0;step<size-1;step++){
        int flag = 0;
        for(i=0;i<size-1-step;i++){
            if(arr[i]>arr[i+1]){
                temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
                flag = 1;
            }
        }
        if(flag==0)
            break;
    }
}
void displayArray(int arr[],int size){
    int i;
    for(i=0;i<size;i++)
        printf("%d\t",*(arr+i));
}
int main(){
    int size,arr[10],i;
    printf("Enter the number of elements: ");
    scanf("%d",&size);
    printf("Enter the elements: ");
    for(i=0;i<size;i++)
        scanf("%d",arr+i);

    printf("Before sorting the array: ");
    displayArray(arr,size);

    modifiedBubble(arr,size);

    printf("\nAfter sorting the array: ");
    displayArray(arr,size);
    return 0;
}