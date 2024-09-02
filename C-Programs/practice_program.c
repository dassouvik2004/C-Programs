#include <stdio.h>
int main()
{
	int r;
	float Area,Perimeter;
	printf("Enter the redius =");
	scanf("%d",&r);
	Area = 3.142*r*r;
	Perimeter = 2*3.142*r;
	printf("Area will be %0.2f\n",Area);
	printf("Perimeter will be %0.3f\n",Perimeter);
	return 0;
