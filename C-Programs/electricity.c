#include <stdio.h>
int main()
{
	int units;
	float sc=0,bill;
	printf("Enter Units: ");
	scanf("%d",&units);
	if(units>=200)
	{
		bill=units*0.8;
	}
	else if(units<=300)
	{
		bill=(200*0.8)+(units-200)*0.9;
	}
	else
	{
		bill=(200*0.8)+(100*0.9)+(units-300);
	}
	if(units>400)
	{
		sc=bill*0.15;
	}
	bill=bill+100+sc;
	printf("Total Bill: %.2f",bill);
	return 0;
}
