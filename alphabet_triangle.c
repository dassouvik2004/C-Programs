#include <stdio.h>
int main()
{
	char d,ch,n,i,j;
	int a;
	printf("Enter the numbers of rows: ");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		a=1;
		for(j=1;j<=i;j++)
		{
			d=a+64;
			ch= (char)d;
			printf("%c ",ch);
			a++;
		}
		printf("\n");
	}
	return 0;
}
