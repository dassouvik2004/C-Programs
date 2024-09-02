#include <stdio.h>
int prime(int);
int main()
{
	int n;
	printf("Enter the number: ");
	scanf("%d",&n);
	if(prime(n))
		printf("PRIME!");
	else
		printf("NOT PRIME!");
		
	return 0;	
}
int prime(int k)
	{
		int i;
		for(i=2;i<=k/2;i++)
		{
			if(k%i==0)
			return 0;
		}
	return 1;
	}
