#include <stdio.h>
#define PI 3.142
int main()
{
	float r,area,peri;
	printf("Enter the redius=");
	scanf("%f",&r);
	area=PI*r*r;
	peri=2*PI*r;
	printf("Area will be %.2f\n",area);
	printf("Perimeter will be %.3f\n",peri);
	return 0;
}
