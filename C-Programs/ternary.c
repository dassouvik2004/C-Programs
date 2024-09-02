#include <stdio.h>
int findMax(int x,int y){
    return x>y?x:y;
}
int main(){
    int a,b;
    printf("Enter the first number: ");
    scanf("%d",&a);
    printf("Enter the second number: ");
    scanf("%d",&b);
    int max = findMax(a,b);
    printf("Maximum is %d",max);
    return 0;
}