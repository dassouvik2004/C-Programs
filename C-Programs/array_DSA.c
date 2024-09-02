#include <stdio.h>
#include <stdlib.h>
int main(){
    int n,i;
    printf("Enter number of elements: ");
    scanf("%d",&n);
    int *p = (int*)malloc(n*sizeof(int));
    if(p==NULL)
        printf("Allocation is not possible!");
    else{
        printf("Allocation is completed successfully using malloc.\n");
        printf("Enter the elements: ");
        for(i=0;i<n;i++)
            scanf("%d",p+i);
        printf("The elements are: ");
        for(i=0;i<n;i++)
            printf("%d ",*(p+i));
    }
    free(p);
    return 0;
}