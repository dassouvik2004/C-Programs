#include <stdio.h>
int main(){
	int n,i,j,sum=0;
	printf("Enter the number of terms: ");
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			sum +=j;
		}
	}
	printf("Sum of series: %d\n",sum);
	return 0;
}
