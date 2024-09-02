// Write a c program to print the tribonacci series
#include <stdio.h>
int main()
{
	int a,b,c,d,i,r,n;
	a=0,b=1,c=1;
	printf("Enter the range: ");
	scanf("%d",&n);
	printf("%d %d %d",a,b,c);
	for(i=4;i<=n;i++)
	{
		d=a+b+c;
		a=b;
		b=c;
		c=d;
		printf(" %d",d);
	}
	return 0;
}
