#include <stdio.h>
#include <ctype.h>
void createPoly(int poly[],int size){
	char ch = 'y';
	int c,p,count=0;
	while(toupper(ch)=='Y'&& (count<size)){
	printf("Enter the exponent: ");
	scanf("%d",&p);
	printf("Enter the co-efficient: ");
	scanf("%d",&c);
	if(p>=0&&p<size){
		poly[p] = c;
		count++;
	printf("Contiune (Y/N)?\n");
	while(getchar()!='\n'){}
	scanf("%c",&ch);
	}
	else
		printf("Exponent out of range.Please try again.\n");
	}
}

void sumPoly(int poly1[],int poly2[],int sum[],int size){
	int i;
	for(i=0;i<size;i++){
		sum[i] = poly1[i] + poly2[i];
	}
}

void displayPoly(int arr[],int size){
	int i;
	int first = 1;
	for(i=size-1;i>=0;i--){
		if(arr[i]!=0){
//			if(!first){
//				printf(" + ");
//			}
		printf("%dx^%d + ",*(arr+i),i);
		//first = 0;
		}
	}
	printf("\b\b  ");
}

int main(){
	int size,poly1[size],poly2[size],sum[size],i;
	printf("Enter the number of terms of the polynomial: ");
	scanf("%d",&size);
	for(i=0;i<size;i++){
		poly1[i] = 0;
		poly2[i] = 0;
		sum[i] = 0;
	}
	
	printf("Enter the first polynomial: \n");
	createPoly(poly1,size);
	printf("Enter the second polynomial: \n");
	createPoly(poly2,size);
	
	sumPoly(poly1,poly2,sum,size);
	
	printf("The first polynomials are: ");
	displayPoly(poly1,size);
	
	printf("\nThe second polynomials are: ");
	displayPoly(poly2,size);
	
	printf("\nSum of the polynomials are: ");
	displayPoly(sum,size);
	
	return 0;
}
