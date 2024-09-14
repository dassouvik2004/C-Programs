#include <stdio.h>
#include <stdlib.h>
int main(){
    int *p = (int*)malloc(sizeof(int));
    int max,n,i;
    printf("Enter the number of element: ");
    scanf("%d",&n);
    printf("Enter the elements: ");
    for(i=0;i<n;i++)
        scanf("%d",p+i);
    
    max = *p;
    for(i=1;i<n;i++){
        if(*(p+i)>max)
            max = *(p+i);
    }
    printf("Max: %d",max);
    free(p);
    return 1;
}