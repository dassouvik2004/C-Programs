#include <stdio.h>
int main()
{
	int a[10][10],b[10][10],sum[10][10],rw,co,i,j;
	printf("Enter the rows & columns: ");
	scanf("%d %d",&rw,&co);
	printf("Enter the data for first matrix:\n");
	for(i=0;i<rw;i++)
	{
		for(j=0;j<co;j++)
			scanf("%d",&a[i][j]);
	}
	printf("Enter the data for second matrix:\n");
	for(i=0;i<rw;i++)
	{
		for(j=0;j<co;j++)
			scanf("%d",&b[i][j]);
	}
	for(i=0;i<rw;i++)
	{
		for(j=0;j<co;j++)
			sum[i][j]=a[i][j]+b[i][j];
	}
	printf("The addition matrix is...\n");
	for(i=0;i<rw;i++)
	{
		for(j=0;j<co;j++)
			printf("%d\t",sum[i][j]);
		
		printf("\n");
	}
	return 0;
}
