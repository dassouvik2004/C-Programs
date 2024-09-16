#include <stdio.h>
typedef struct Date{
	int dd;
	int mm;
	int yy;
}date;
date calcAge(date d1, date d2){
	date temp;
	if(d1.dd>=d2.dd)
		temp.dd = d1.dd - d2.dd;
	else{
		temp.dd = d1.dd + 30 - d2.dd;
		d1.mm--;
	}
	if(d1.mm>=d2.mm)
		temp.mm = d1.mm - d2.mm;
	else{
		temp.mm = d1.mm + 12 - d2.mm;
		d1.yy--;
	}
	temp.yy = d1.yy - d2.yy;
	
	return temp;
}
int main(){
	date cur,dob,age;
	printf("Enter your date of birth(dd/mm/yyyy): ");
	scanf("%d/%d/%d",&dob.dd,&dob.mm,&dob.yy);
	printf("Enter the current date(dd/mm/yyyy): ");
	scanf("%d/%d/%d",&cur.dd,&cur.mm,&cur.yy);
	age = calcAge(cur,dob);
	printf("Your age is %d years %d months and %d days.",age.yy,age.mm,age.dd);
	
	return 0;
}