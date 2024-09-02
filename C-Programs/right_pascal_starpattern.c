#include <stdio.h>
int main()
{
	int i,j,row;
	printf("Enter the rows: ");
	scanf("%d",&row);
	for(   ;i<=row;i++)
	{
		for(j=row;j>=i;j--)
		{
			printf("*");
		}
		printf("\n");
	}
	return 0;
}
