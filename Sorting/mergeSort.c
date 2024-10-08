#include <stdio.h>
#define SIZE 100
void merge(int arr[],int beg,int mid,int end){
    int i = beg, j = mid+1, index = beg, temp[SIZE], k;
    while((i<=mid) && (j<=end)){
        if((arr[i]) < (arr[j])){
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
        while(i<=mid){
            temp[index] = arr[i];
            i++;
            index++;
        }
    }
    for(k=beg;k<index;k++)
        arr[k] = temp[k];
}
void merge_sort(int arr[],int beg,int end){
    int mid;
    if(beg<end){
        mid = (end+beg)/2;
        merge_sort(arr,beg,mid);
        merge_sort(arr,mid+1,end);
        merge(arr,beg,mid,end);
    }
}
int main(){
    int arr[SIZE],i,n;
    printf("Enter the number of elements in the array: ");
    scanf("%d",&n);
    printf("Enter the elements of the array: ");
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    
    merge_sort(arr,0,n-1);

    printf("The sorted array is: \n");
    for(i=0;i<n;i++)
        printf("%d\t",arr[i]);
    
    return 0;
}