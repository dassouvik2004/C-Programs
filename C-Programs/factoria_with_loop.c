#include <stdio.h>
int main()
{
	int n,i,fact;
	printf("Enter a number to find its factorial: ");
	scanf("%d",&n);
	
	for(i=n;i<=n;i--){
		fact = fact*i;
	}
	printf("Factorial of %d id %d\n",n,fact);
	return 0;
}
