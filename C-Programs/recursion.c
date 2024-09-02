#include <stdio.h>
void a(int);
int main()
{
	a(10);
	return 0;
}
void a(int n)
{
	if(n>0)
		a(n-1);
			printf(" HELLO WORLD \n");
}
