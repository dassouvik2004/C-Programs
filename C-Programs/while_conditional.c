#include <stdio.h>
int main()
{
	int a,b,r=1,i=1;
	printf("Enter the values of a and b: ");
	scanf("%d %d",&a,&b);
	while(i<=b)
	{
		r=r*a;
		i++;
	}
	printf("The result of %d^%d is: %d",a,b,r);
	return 0;
}
