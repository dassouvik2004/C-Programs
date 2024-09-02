#include <stdio.h>
int main()
{
	int i,j,row,col;
	printf("Enter the rows: ");
	scanf("%d",&row);
	int n=row;
	for(i=1;i<=row;i++)
	{
		for(j=1;j<=n;j++)
		{
			printf("%d",j);
		}
		n--;
		printf("\n");
	}
	return 0;
}
