#include <stdio.h>
int main()
{
	int a,b,r=0;
	char n;
	printf("Enter two integer numbers: ");
	scanf("%d %d",&a,&b);
	printf("Select the Operation(+,-,*,/)\nYour Choice: ");
	fflush(stdin);
	scanf("%c",&n);
	switch(n)
	{
		case '+':
			r=a+b;
			break;
		case'-':
			r=a-b;
			break;
		case '*':
			r=a*b;
			break;
		case '/':
			r=a/b;
			break;
	}
	printf("Result: %d",r); 
	return 0;
}
