#include <stdio.h>
#include <stdlib.h>
#define SIZE 5
typedef struct queue{
	int rear;
	int front;
	int item[SIZE];
}qu;
void createEmptyQueue(qu *q){
	q->rear = q->front = -1;
}
int isFull(qu *q){
	if(((q->rear+1)%SIZE) == q->front)
		return 1;
	else
		return 0;
}
void enqueue(qu *q,int value){
	if(isFull(q))
		printf("Queue is full.\n");
	else{
		if(q->front==-1)
			q->front = 0;
		q->rear = (q->rear+1)%SIZE;
		q->item[q->rear] = value;
		printf("Item inserted: %d",value);
	}
}
int isEmpty(qu *q){
	if(q->front == -1)	
		return 1;
	else
		return 0;
}
void dequeue(qu *q){
	int element;
	if(isEmpty(q))
		printf("Queue is empty.\n");
	else{
		element = q->item[q->front];
		if(q->front == q->rear)
			q->front = q->rear = -1;
		else
			q->front = (q->front+1)%SIZE;
		
		printf("Item deleted: %d",element);
	}
}
void peek(qu *q){
	int element;
	if(isEmpty(q))
		printf("Queue is empty.\n");
	else{
		element = q->item[q->front];
		printf("Front element is: %d",element);
	}
}
void display(qu *q){
	int i;
	printf("\n Front -> %d",q->front);
	printf("\n Items -> ");
	for(i=q->front;i!=q->rear;i=(i+1)%SIZE)
		printf("%d ",q->item[i]);
	
	printf("%d",q->item[q->rear]);
	printf("\n Rear -> %d\n",q->rear);
}
int main(){
	qu *q = (qu*)malloc(sizeof(qu));
	int value,ch;
	if(q==NULL){
		printf("Allocation is not possible.\n");
		return -1;
	}
	else{
		createEmptyQueue(q);
		
		printf("MAIN MENU\n");
		printf("----------------");
		printf("\n1.INSERT\n2.DELETE\n3.PEEK\n4.PRINT QUEUE\n5.EXIT\n");
		printf("----------------");
		while(1){
			printf("\nENTER ANY OPERATION: ");
			scanf("%d",&ch);
			switch(ch){
				case 1:
					printf("Enter the value to insert in Queue: ");
					scanf("%d",&value);
					enqueue(q,value);
					break;
				case 2:
					dequeue(q);
					break;
				case 3:
					peek(q);
					break;
				case 4:
					display(q);
					break;
				case 5:
					printf("Exiting...\n");
					return 0;
				default:
					printf("Invalid operation.Please try again.\n");
			}
		}
	}
	free(q);
	return 0;
}
