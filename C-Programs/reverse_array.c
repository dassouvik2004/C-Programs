#include <stdio.h>
int main()
{
	int a[10],n,i,sum=0,avg;
		printf("How many elements do you want: ");
		scanf("%d",&n);
		printf("Enter array input:\n");
			for(i=0;i<n;i++)
				scanf("%d",&a[i]);
		printf("Reverse list will be: \n");
			for(i=n-1;i>=0;i--)
				printf("%d\n",a[i]);
	
	return 0;
}
