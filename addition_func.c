#include <stdio.h>
void swap(int *x,int *y){
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}
int main(){
	int a,b,c;
	printf("Enter the first number: ");
	scanf("%d",&a);
	printf("Enter the second number: ");
	scanf("%d",&b);
	
	swap(&a,&b);
	printf("After swapping: %d %d",a,b);
	return 0;
}
