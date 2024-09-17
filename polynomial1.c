#include <stdio.h>
#include <ctype.h>
void createPoly(int arr[],int size){
	int c,p,max=0;
	char ch = 'Y';
	while(toupper(ch)=='Y'&&(max<size)){
		printf("Enter the exponent: ");
		scanf("%d",&p);
		printf("Enter the co-efficient: ");
		scanf("%d",&c);
		if(p>=0&&p<size){
		arr[p] = c;
		max++;
		}
		else
			printf("Exponent out range.Please try again.\n");
		
		printf("Continue(Y/N)?\n");
		while(getchar()!='\n'){}
		printf("The Poynomial expressions are: ");
		scanf("%c",&ch);
	}
}

void displayPoly(int arr[],int size){
	int i;
	for(i=size-1;i>=0;i--){
		if(arr[i]!=0)
			printf("%dx^%d ",arr[i],i);
	}
	printf("\b ");
}
int main(){
	int data[10],n,size,i;
	printf("Enter the highest order of your polynomial: ");
	scanf("%d",&n);
	
	size = n + 1;

	for(i=0;i<size;i++){
		data[i] = 0;
	}
	
	createPoly(data,size);
	displayPoly(data,size);
	
	return 0;
}