#include <stdio.h>
typedef struct number{
	float real;
	float imag;
}complex;
void addNumbers(complex c1,complex c2,complex *result){
	result->real = c1.real + c2.real;
	result->imag = c1.imag + c2.imag;
}
int main(){
	complex c1,c2,result;
	printf("Enter the first number.\n");
	printf("Enter the real number: ");
	scanf("%f",&c1.real);
	printf("Enter the imagination number: ");
	scanf("%f",&c1.imag);
	printf("Enter the second number.\n");
	printf("Enter the real number: ");
	scanf("%f",&c2.real);
	printf("Enter the imagination number: ");
	scanf("%f",&c2.imag);
	addNumbers(c1,c2,&result);
	printf("Addition of real numbers: %.2f\n",result.real);
	printf("Addition of imaginary numbers: %.2f",result.imag);
	
	return 0;
}
