#include<stdio.h>
int main()
{
	float p;
	int index;
	printf("Enter the percentage of marks: ");
	scanf("%f",&p);
	index=(int)p/10;
	switch(index)
	{
		case 10:
		case 9:
		case 8:
			printf("Star Marks!");
			break;
		case 7:
		case 6:
			printf("First Division!");
			break;
		case 5:
		case 4:
			printf("Second Division!");
			break;
		default:
			printf("FAIL!!!");
	}
	return 0;
}
