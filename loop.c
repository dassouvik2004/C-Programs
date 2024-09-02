#include <stdio.h>
int main()
{
	int n,s=0,r;
	printf("Enter the number: ");
	scanf("%d",&n); // n=13
	while(n>0) // 13>0
	{
		r=n%10; // r=13%10=3  // r=1%10=1
		s=s+r; // s=0+3=3     // s=3+1=4
		n=n/10; // n=13/10 = 1 // n=1/10=0
	}
	printf("Sum of digits: %d",s);
	return 0;
}
