#include <stdio.h>
#define PI 3.142
int main()
{
	int r;
	float area, peri;
	printf("Enter the redius = ");
	scanf("%d",&r);
	area = PI*r*r;
	peri = 2*PI*r;
	printf("\n Value of the area = %0.2f",area);
	printf("\n Value of the perimeter = %0.3f",peri);
	return 0;
}
