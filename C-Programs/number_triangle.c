#include<stdio.h>
int main()
{
	int row,i,j;
	printf("How many rows?: ");
	scanf("%d",&row);
	for(i=1;i<=row;i++)
	{
		for(j=1;j<=row;j++)
		{
			printf("%d",j);
		}
		printf("\n");
	}
	return 0;
}
