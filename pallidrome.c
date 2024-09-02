#include<stdio.h>
int main()
{
	int n,r,p,s=0,rev=0;
	printf("Enter the number: ");
	scanf("%d",&n);
	p=n;
	while(n>0)
	{
		r=n%10;
		s=s+r;
		rev=rev*10+r;
		n=n/10;
	}
	printf("Sum of digits: %d\n",s);
	printf("Reverse of the number is: %d\n",rev);
	if(rev==p)
	{
		printf("It is a Pallidrome number.");
	}
	else
	{
		printf("It is not a Pallidrome number.");
	}
	return 0;
}
