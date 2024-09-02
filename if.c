#include <stdio.h>
int main()
{
	int a,b,t;
	printf("Enter two numbers: ");
	scanf("%d %d",&a,&b);
	if(a<b)
	{
		t=a;
		a=b;
		b=t;
	}
	printf("GCD: %d",t);
	return 0;
}
