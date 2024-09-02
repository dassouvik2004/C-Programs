#include <stdio.h>
int main()
{
	int x,y,a;
	printf("\n Enter 1st Number = ");
	scanf("%d",&x);
	printf("\n Enter 2nd Number = ");
	scanf("%d",&y);
	a = x + y;
	printf("\n %d + %d = %d",x,y,a);
	a = x - y;
	printf("\n %d - %d = %d",x,y,a);
	a = x * y;
	printf("\n %d * %d = %d",x,y,a);
	a = x / y;
	printf("\n %d / %d = %d",x,y,a);
	a = x % y;
	printf("\n %d mod %d = %d",x,y,a);
	return 0;
}
