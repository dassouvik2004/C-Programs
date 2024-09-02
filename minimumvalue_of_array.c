#include <stdio.h>
int main(){
	int i,min,size,a[100];
	printf("Enter size of array: ");
	scanf("%d",&size);
	printf("Enter element of array: ");
	for(i=0;i<size;i++){
		scanf("%d",&a[i]);
	}
	min=a[0];
	for(i=0;i<size;i++){
		if(a[i]<min)
		{
			min=a[i];
		}
	}
	printf("Minimum element of array: %d",min);

	return 0;
}
