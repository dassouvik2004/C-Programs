#include <stdio.h>
int main()
{
	float c,f;
	printf("Enter the temperature in Fahrenheit = ");
	scanf("%f",&f);
	c=((f-32)*5)/9;
	printf("The temperature in Centigrade is %0.2f",c);
	return 0;
}
