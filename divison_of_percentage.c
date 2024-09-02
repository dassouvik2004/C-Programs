#include <stdio.h>
int main()
{
	int p,i;
	printf("Enter the percentage of marks: ");
	scanf("%d",&p);
	i=p/10;
	switch(i)
	{
		case 10:
		case 9:
		case 8:
			printf("STAR!");
			break;
		case 7:
		case 6:
			printf("FIRST DIVISION!");
			break;
		case 5:
		case 4:
			printf("SECOND DIVISION!");
			break;
		default:
			printf("FAIL!");
	}
	return 0;
}
