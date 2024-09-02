#include <stdio.h>
#include <stdlib.h>
#define MAX 10
typedef struct stack{
	char item[MAX];
	int top;
}st;
void createEmptyStack(st *s){
	s->top = -1;
}
int isFull(st *s){
	if(s->top==MAX-1)
		return 1;
	else
		return 0;
}
void push(st *s,int newitem){
	if(isFull(s))
		printf("Stack is full.\n");
	else{
		s->top++;
		s->item[s->top] = newitem;
		printf("Item pushed = %d\n",newitem);
	}
}
int isEmpty(st *s){
	if(s->top==-1)
		return 1;
	else
		return 0;
}
void pop(st *s){
	if(isEmpty(s))
		printf("Stack is empty.\n");
	else{
		printf("Item popped = %d\n",s->item[s->top]);
		s->top--;
	}
}
void printStack(st *s){
	int i;
	for(i=0;i<=s->top;i++){
		printf("%d ",s->item[i]);
	}
	printf("\n");
}
int main(){
	st *s = (st*)malloc(sizeof(s));
	int item,ch;
	
	createEmptyStack(s);
	do{
		printf("1.Push\n2.Pop\n3.Print Stack\n4.Exit\n");
		printf("Enter an operation: ");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				printf("Enter the item you want to push: ");
				scanf("%d",&item);
				push(s,item);
				break;
			case 2:
				pop(s);
				break;
			case 3:
				printStack(s);
				break;
			case 4:
				printf("Exiting....\n");
				break;
			default:
				printf("Invalid operation.Please try again.\n");
		}
	}while(ch!=4);
	
	free(s);
	
	return 0;
}
