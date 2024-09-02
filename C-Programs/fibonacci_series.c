// Write a c program to print the fibonacci series
// 0 1 1 2 3 5 8
#include <stdio.h>
int main()
{
	int n,i,r,a,b,c;
	a=0,b=1;
	printf("Enter the range: ");
	scanf("%d",&n);
	printf("%d %d",a,b);
	for(i=3;i<=n;i++)
	{
		c=a+b;
		a=b;
		b=c;
		printf(" %d",c);
	}
	return 0;
}
