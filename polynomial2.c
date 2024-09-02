#include <stdio.h>
#include <ctype.h>
void createPoly(int arr[],int size){
	int c,p,count=0;
	char ch = 'Y';
	while(toupper(ch)=='Y'&&(count<size)){
		printf("Enter the exponent: ");
		scanf("%d",&p);
		printf("Enter the co-efficient: ");
		scanf("%d",&c);
		if(p>=0&&p<size){
		arr[p] = c;
		count++;
		}
		else
			printf("Exponent is out of range.Please try again.\n");
		
		printf("Continue(Y/N)?\n");
		while(getchar()!='\n'){}
		scanf("%c",&ch);
	}
}

void addPoly(int poly[],int poly2[],int poly3[],int size){
	int i;
	for(i=0;i<size;i++){
		poly3[i] = poly[i] + poly2[i];
	}
}

void displayPoly(int arr[],int size){
	int i;
	for(i=size-1;i>=0;i--){
		if(arr[i]!=0){
			printf("%dx^%d + ",arr[i],i);
		}
	}
	printf("\b\b ");
}
int main(){
	int n,size,i,poly[20]={0},poly2[20]={0},poly3[20]={0};
	printf("Enter the highest power of your polynomial: ");
	scanf("%d",&n);
	size = n+1;
	printf("Enter the first polynomial: \n");
	createPoly(poly,size);
	printf("Enter the second polynomial: \n");
	createPoly(poly2,size);
	
	addPoly(poly,poly2,poly3,size);
	
	printf("The first polynomial is: ");
	displayPoly(poly,size);
	printf("\nThe second polynomial is: ");
	displayPoly(poly2,size);
	printf("\nThe resultant polynomial is: ");
	displayPoly(poly3,size);
	
	return 0;
}
