#include <stdio.h>
int main()
{
	int a,b,r;
	char n;
	printf("Enter two integer numbers: ");
	scanf("%d %d",&a,&b);
	printf("Select the operatiom(+,-,*,/)\nYour Choice: ");
	fflush(stdin);
	scanf("%c",&n);
	switch(n)
	{
		case '+':
			r=a+b;
			break;
		case '-':
			r=a-b;
			break;
		case '*':
			r=a*b;
			break;
		case '/':
			r=a/b;
			break;
		default:
			printf("Error!!\nYou choose wrong operation!");
	}
	printf("Result: %d",r);
	return 0;
} 
