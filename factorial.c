#include <stdio.h>
#include <conio.h>
int factorial(int n){
    if(n==1)
        return 1;
    return (n* factorial(n-1));
}
void main(){
    int fact = 0;
    //clrscr();
    fact = factorial(5);
    printf("\n Factorial of 5 is: %d",fact);
    getch();
}