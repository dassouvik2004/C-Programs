// Program: Program to calculate the area of a circle

#include <stdio.h>
int main()
{
	int r;
	float area;
	printf("Enter the radius of the circle..\n");
	scanf("%d",&r);
	area = 3.14*r*r;
	printf("The area of the circle is...\n%f",area);
	return 0;
}
/* Output:
   Enter the radius of the circle..
   15
   The area of the circle...
   706.500000
*/
