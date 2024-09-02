#include <stdio.h>
int main(){
	int n,rem,rev=0,a;
	printf("Enter a number: ");
	scanf("%d",&n);
	a=n;
	while(n>0){
		rem=n%10;
		rev=rev*10+rem;
		n=n/10;
	}
	printf("Reverse: %d",rev);
	printf("\n Difference: %d",(a-rev));
	return 0;
}
