#include <stdio.h>
int main()
{
	int a,b,r,n;
	printf("Enter first number: ");
	scanf("%d",&a);
	printf("Enter second number: ");
	scanf("%d",&b);
	while(1)
	{
	printf("\n Which operation you want?\n 1:Add\n 2:Substract\n 3:Multiply\n 4:Divide\n");
	scanf("%d",&n);
	switch(n)
	{
		case 1:
			r=a+b;
			printf("%d",r);
			break;
		case 2:
			r=a-b;
			printf("%d",r);
			break;
		case 3:
			r=a*b;
			printf("%d",r);
			break;
		case 4:
			r=a/b;
			printf("%d",r);
			break;
		default:
			printf("INVALID CHOICE");
	}
	
}
	return 0;
}
