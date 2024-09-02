#include <stdio.h>
int main(){
	int n,limit,i;
	printf("Enter an integer: ");
	scanf("%d",&n);
	printf("Enter the limit for the multipication table: ");
	scanf("%d",&limit);
	for(i=1;i<=limit;i++){
		printf("%d x %d = %d\n",n,i,n*i);
	}
	return 0;
}
