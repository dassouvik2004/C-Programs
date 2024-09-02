/* Program: Program to calculate the net salary of an employee
   Author: SOUVIK DAS
   Date: 31/08/2023
*/
#include <stdio.h>
int main()
{
	float basic,dap,da,ma,hra,ptax,net_salary;
	printf("Enter the basic salary: ");
	scanf("%f",&basic);
	printf("Enter The DA Percentage: ");
	scanf("%f",&dap);
	da=(dap/100)*basic;
	ma=(5/100)*basic;
	hra=(3/100)*basic;
	ptax=(0.5/100)*basic;
	net_salary=basic+da+ma+hra-ptax;
	printf("The Net Salary of the Employee: %.2f/-",net_salary);
	return 0;
}
