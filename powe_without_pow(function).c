#include <stdio.h>
int main(){
	int n, power, result=1;
	printf("Enter the number: ");
	scanf("%d",&n);
	printf("Enter the power: ");
	scanf("%d",&power);
	printf("%d to the power %d is = ",n,power);
	while(power > 0){
		result = n * result;
		--power;
	}
	printf("%d",result);
	return 0;
}
