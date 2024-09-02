#include <stdio.h>
int main()
{
	int n,k,i,j;
	printf("Enter the numbers of rows: ");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		for(j=n;j=i;j--)
		{
			printf("*");
		}
		printf("\n");
	}
	return 0;
}
