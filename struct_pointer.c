#include <stdio.h>
typedef struct student{
    int roll;
}stu;
int main(){
    stu *s1;
    printf("Enter the roll: ");
    scanf("%lld",&s1);
    printf("The roll number is %lld\n",s1);
    return 0;
}