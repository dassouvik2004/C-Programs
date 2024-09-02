#include <stdio.h>
void fibo(int);
int main()
{
	int n;
	printf("Enter range: ");
	scanf("%d",&n);
	fibo(n);
	return 0;
}
void fibo(int n)
{
	int a=0,b=1,c,i;
	for(i=1;i<=n;i++)
	{
		printf("%d ",a);
		c=a+b;
		a=b;
		b=c;
	}
}
