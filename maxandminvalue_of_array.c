#include <stdio.h>
int main(){
	int i,max,min,size,a[100];
	printf("Enter size of array: ");
	scanf("%d",&size);
	printf("Enter element of array: ");
	for(i=0;i<size;i++){
		scanf("%d",&a[i]);
	}
	max=a[0];
	for(i=1;i<size;i++){
		if(a[i]>max)
		{
			max=a[i];
		}
	}
	min=a[0];
	for(i=1;i<size;i++){
		if(a[i]<min)
		{
			min=a[i];
		}
	}
	printf("Maximum and minimum element of array: %d %d",max,min);
	return 0;
}
