// Write a C program to check whether a number is even or odd.
#include <stdio.h>
int main()
{
	int n;
	printf("Enter any number =");
	scanf("%d",&n);
	if(n%2==0)
	{
		printf("Even Number");
	}
	else
	{
		printf("Odd Number");
	}
	return 0;
}
