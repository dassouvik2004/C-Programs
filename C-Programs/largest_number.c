#include <stdio.h>
int main()
{
	int a,b,c;
	printf("Enter 3 integer number: ");
	scanf("%d %d %d",&a,&b,&c);
	if(a>b)
	{
		if(a>c)
		{
			printf("THE LARGEST NUMBER IS %d",a);
		}
		else
		{
			printf("THE LARGEST NUMBER IS %d",c);
		}
	}
	else
	{
		if(b>c)
		{
			printf("THE LARGEST NUMBER IS %d",b);
		}
		else
		{
			printf("THE LARGEST NUMBER IS %d",c);
		}
	}
	return 0;
}
