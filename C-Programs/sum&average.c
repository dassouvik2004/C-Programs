#include <stdio.h>
int main()
{
	int a[10],n,i,sum=0,avg;
		printf("How many elements do you want: ");
		scanf("%d",&n);
		printf("Enter array input:\n");
			for(i=0;i<n;i++)
				scanf("%d",&a[i]);
			for(i=0;i<n;i++)
				{
					sum=sum+a[i];
				}
			avg=sum/n;
			printf("Summation: %d\n",sum);
			printf("Average: %d",avg);
	
	return 0;
}
