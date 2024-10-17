#include <stdio.h>
void sort012(int arr[],int size){
    int c1 = 0,c2 = 0,c3 = 0;
    int i;
    for(i=0;i<size;i++){
        if(arr[i]==0)
            c1 += 1;
        else if(arr[i]==1)
            c2 += 1;
        else
            c3 += 1;
    }
    int idx = 0;

    for(i=0;i<c1;i++){
        arr[idx] = 0;
        idx++;
    }
    for(i=0;i<c2;i++){
        arr[idx] = 1;
        idx++;
    }
    for(i=0;i<c3;i++){
        arr[idx] = 2;
        idx++;
    }
}
int main(){
    int i,size,arr[10];
    printf("Enter the number of elements: ");
    scanf("%d",&size);
    printf("Enter the elements: \n");
    for(i=0;i<size;i++)
        scanf("%d",(arr+i));

    sort012(arr,size);

    printf("After soring: \n");
    for(i=0;i<size;i++)
        printf("%d ",arr[i]);
    return 0;
}