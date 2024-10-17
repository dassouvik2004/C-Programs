#include <stdio.h>
#define SIZE 10
void merge(int arr[SIZE],int beg,int mid,int end){
    int i = beg, j = mid + 1, temp[SIZE],k, index = beg;
    while(i<=mid && j<=end){
        if(arr[i]<arr[j]){
            temp[index] = arr[i];
            i++;
        }
        else{
            temp[index] = arr[j];
            j++;
        }
        index++;
    }
    if(i>mid){
        while(j<=end){
            temp[index] = arr[j];
            j++;
            index++;
        }
    }
    else{
        while(i<=end){
            temp[index] = arr[i];
            i++;
            index++;
        }
    }
    for(k=beg;k<index;k++)
        arr[k] = temp[k]; 
}
void mergeSort(int arr[SIZE],int beg,int end){
    if(beg<end){
        int mid = (beg+end)/2;
        mergeSort(arr,beg,mid);
        mergeSort(arr,mid+1,end);
        merge(arr,beg,mid,end);
    }
}
int main(){
    int i,size,arr[SIZE];
    printf("Enter the number of elements: ");
    scanf("%d",&size);
    printf("Enter the elements: \n");
    for(i=0;i<size;i++)
        scanf("%d",&arr[i]);
    
    mergeSort(arr,0,size-1);

    printf("The array after sorting: \n");
    for(i=0;i<size;i++)
        printf("%d ",arr[i]);
    return 0;
}