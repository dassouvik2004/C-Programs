#include <stdio.h>
int main()
{
	int n,i,j;
	printf("How many row?: ");
	scanf("%d",&n);
	for(i=1;i<=n;i++) /// How many rows
	{
		for(j=1;j<=i;j++) // How many stars
		{
			printf("*");
		}
		printf("\n");
	}
	return 0;
}
