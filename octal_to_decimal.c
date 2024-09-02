#include <stdio.h>
int main(){
	int arr[10],i,n;
	printf("Enter the decimal number: ");
	scanf("%d",&n);
	for(i=0;n>0;i++){
		arr[i]=n%8;
		n=n/8;
	}
	printf("The octal number is: ");
	for(i=i-1;i>=0;i--)
		printf("%d",arr[i]);
	
	return 0;
}
