#include <stdio.h> 
int main()
{
	int n;
	printf("Enter the number= ");
	scanf("%d",&n);
	if(n>100)
	{
		printf("ERROR!!!\nPLEASE TRY AGAIN!!");
	}
	else if(n>=90)
	{
		printf("OUTSTANDING");
	} 
	else if(n>=80)
	{
		printf("EXCELLENT");
	}
	else if(n>=70)
	{
		printf("AVERAGE");
	}
	else if(n>=60)
	{
		printf("BELOW AVERAGE");
	}
	else if(n>=50)
	{
		printf("CAREFUL");
	}
	else if(n>=40)
	{
		printf("DANGEROUS!");
	}
	else if(n<40)
	{
		printf("FAIL");
	}
	else if(n>100)
	{
		printf("ERROR!! \n PLEASE TRY AGAIN!!! \n");
	}
	return 0;
}

