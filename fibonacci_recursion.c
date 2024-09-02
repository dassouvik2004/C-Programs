#include <stdio.h>
void fibo(int);
int main()
{
	int n;
	printf("Enter Range: ");
	scanf("%d",&n);
	fibo(n);
	return 0;
}
void fibo(int a,int b,int n)
{
	if(n>=0)
	{
		printf("%d",a);
		fibo(b,a+b,n-1);
	}
}
