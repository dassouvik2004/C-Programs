#include <stdio.h>
int main()
{
	int n,i,s=0;
	printf("Enter the number: ");
	scanf("%d",&n);
	for(i=1;i<n;i++)
	{
		if(n%i==0)
		s=s+i;
	}
	if(s==n)
		printf("PERFECT NUMBER!!");
	else
	printf("NOT PERFECT NUMBER!!");
	return 0;
}
