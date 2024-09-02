#include <stdio.h>
#include <ctype.h>
void createPoly1(int a[],int m){
	char ch = 'Y';
	int c,i=0,p;
	printf("\nFor first polynomial:\n\n");
	while(toupper(ch)=='Y'&&(i<m)){
	printf("Enter the exponent: ");
	scanf("%d",&p);
	printf("Enter the co-efficient: ");
	scanf("%d",&c);
	a[p]=c;
	i++;
	printf("Contiune (Y/N)?\n");
	while(getchar()!='\n');
	scanf("%c",&ch);
	}
	printf("Full!\n");
}
void createPoly2(int a[],int n){
	char ch = 'Y';
	int c,p,i=0;
	printf("\nFor second polynomial: \n\n");
	while(toupper(ch)=='Y'&&(i<n)){
	printf("Enter the exponent: ");
	scanf("%d",&p);
	printf("Enter the co-efficient: ");
	scanf("%d",&c);
	a[p]=c;
	printf("Contiune (Y/N)?\n");
	while(getchar()!= '\n');
	scanf("%c",&ch);
	i++;
	}
	printf("Full\n");
}
void additionPoly(int a[],int b[],int m,int n){
	int size = (m>n)?m:n;
	int sum[size],i;
	
	for (i=0;i<size;i++){
		sum[i]=0;
	}
	
	for(i=0;i<m;i++){
		sum[i]=a[i];
	}
	
	for(i=0;i<n;i++){
		sum[i] += b[i];
	}
	printf("Sum of two polynomia: ");
	for (i = 0; i < size; i++){
//			printf("%dx^%d+\n",a[i],i);
//			printf("%dx^%d+\n",b[i],i);
        if(sum[i]!=0)
        	printf("%dx^%d+",sum[i],i);
    }
    printf("\b ");
}

int main(){
	int m,n,i;
	printf("Enter the number of values for first Polynomial: ");
	scanf("%d",&m);
	printf("Enter the number of values for second Polynomial: ");
	scanf("%d",&n);
	int poly1[m],poly2[n];
	for (i=0;i<m;i++){
		poly1[i]=0;
	}
	for (i=0;i<n;i++){
		poly2[i]=0;
	}
	createPoly1(poly1,m);
	createPoly2(poly2,n);
	additionPoly(poly1,poly2,m,n);
}
