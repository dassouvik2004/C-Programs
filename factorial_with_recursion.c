#include <stdio.h>
int fibo(int n){
	if(n==0)
		return 0;
	else if(n==1)
		return 1;
	else
		return (fibo(n-1)+fibo(n-2));
}
int main(){
	int i,n;
	printf("Enter the number: ");
	scanf("%d",&n);
	printf("First %d fibonacci numbers: \n",n);
	for(i=0;i<n;i++)
		printf("%d ",fibo(i));
	return 0;
}
