#include<stdio.h>
int main()
{
	int row,i,j,a;
	printf("How many rows?: ");
	scanf("%d",&row);
	for(i=1;i<=row;i++)
	{
		a=1; 
		for(j=1;j<=i;j++)
		{
			printf("%d ",a);
			a=a+2;
		}
		printf("\n");
	}
	return 0;
}
