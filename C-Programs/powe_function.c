#include <stdio.h>
int power (int,int);
int main()
{
	int a,b;
	printf("Enter the number and the power of the number: ");
	scanf("%d %d",&a,&b);
	printf("%d^%d: %d",a,b,power(a,b));
	return 0;
}
int power(int p,int q)
{
	int i,po=1;
	for(i=1;i<=q;i++)
		po=po*p;
	
	return po;
}
