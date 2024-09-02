#include <stdio.h>
int main()
{
	int n,r,s=0,rev=0;
	printf("Enter the numbers: ");
	scanf("%d",&n);
	while(n>0)
	{
		r=r%10;
		s=s+r;
		rev=rev*10+r;
		n=n/10;
	}
	printf("Sum of digits: %d\n",n);
	printf("Reverse of the number is: %d",rev);
	return 0;
}
