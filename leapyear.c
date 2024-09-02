// Write a C program to check whether a year is leap year or not.
#include <stdio.h>
int main()
{
	int yr;
	printf("Enter any year = ");
	scanf("%d",&yr);
	if (yr%400==0 || (yr%4==0 && yr%100!=0))
	{
		printf("The year %d is leap year",yr);
	}
	else
	{
		printf("The year %d is not leap year",yr);
	}
	return 0;
}
