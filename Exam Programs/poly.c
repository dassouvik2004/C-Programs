#include <stdio.h>
#include <ctype.h>
void create_Poly(int poly[30],int size){
    int cf,p,count = 0;
    char ch = 'Y';
    while(toupper(ch)=='Y' && count<size){
        printf("Enter the exponent: ");
        scanf("%d",&p);
        printf("Enter the co-efficient: ");
        scanf("%d",&cf);
        if(p>=0 && p<size){
            poly[p] = cf;
            count++;
        }
        else
            printf("Invalid exponent.Please try again.\n");
        
        printf("Continue(Y/N)?\n");
        while(getchar()!='\n'){}
        scanf("%s",&ch);
    }
}
void add_Poly(int poly1[],int poly2[],int poly3[],int size){
    int i;
    for(i=0;i<size;i++){
        poly3[i] = poly1[i] + poly2[i];
    }
}
void display_Poly(int poly[],int size){
    int i;
	for(i=size-1;i>=0;i--){
		if(poly[i]!=0){
			printf("%dx^%d + ",poly[i],i);
		}
	}
	printf("\b\b ");
}
int main(){
    int num,n1,poly1[30]={0},poly2[30]={0},poly3[30]={0};
    printf("Enter the highest order of your first polynomial: ");
    scanf("%d",&num);
    n1 = num + 1;
    printf("Enter the first polynomial: \n");
    create_Poly(poly1,n1);
    printf("Enter the second polynomial: \n");
    create_Poly(poly2,n1);

    add_Poly(poly1,poly2,poly3,n1);

    printf("The first polynomial: ");
    display_Poly(poly1,n1);
    printf("\nThe second polynomial: ");
    display_Poly(poly2,n1);
    printf("\nThe resultant polynomial: ");
    display_Poly(poly3,n1);
    return 0;
}