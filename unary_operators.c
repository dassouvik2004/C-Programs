// Program to illustrate unary operator
#include <stdio.h>
int main()
{
	int i=1;
	printf("\n Prefix Operator ++i");
	printf("\n i = %d",i);
	printf("\n i = %d",++i);
	printf("\n i = %d",i);
	i=1;
	printf("\n Postfix Operator ++i");
	printf("\n i = %d",i);
	printf("\n i = %d",i++);
	printf("\n i = %d",i);
	return 0;
}
