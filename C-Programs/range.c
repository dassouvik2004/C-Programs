#include <stdio.h>
int main(){
	int n,lb,ub,i;
	printf("Enter the lower bound of the range: ");
	scanf ("%d",&lb);
	printf("Enter the upper bound of the range: ");
	scanf ("%d",&ub);
	
	for(i=lb;i<=ub;i++){
		if(i%5==0 && i%15!=0)
			printf("%d\n",i);
	}
	return 0;
}

