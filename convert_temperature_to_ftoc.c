#include <stdio.h>
int main()
{
	float f,c;
	printf("Enter the temperature in fahrenheit...\n");
	scanf("%f",&f);
	c=((f-32)*5)/9;
	printf("The temperature in centigrade is...\n%f",c);
	return 0;
}
