#include <stdio.h>
int main()
{
	float p;
	int index;
	printf("Enter the percentage of marks: ");
	scanf("%f",&p);
	index = p/10;
	switch(index)
	{
		case 10:
		case 9:
		case 8:
			printf("STAR MARKS!!!");
			break;
		case 7:
		case 6:
			printf("FIRST DIVISION!!!");
			break;
		case 5:
		case 4:
			printf("SECOND DIVISION!!!");
			break;
		default:
			printf("FAIL!");
	}
	return 0;
}
