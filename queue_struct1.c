#include <stdio.h>
#include <stdlib.h>
#define MAX 10
typedef struct queue{
	int queue[MAX];
	int rear;
	int front;
}qu;
createQueueEmpty(qu *q){
	q->rear = q->front = -1;
} 
int isFull(qu *q){
	if(q->rear == MAX - 1)
		return 1;
	else
		return 0;
}
void enqueue(qu *q,int value){
	if(isFull(q))
		printf("Queue is full.\n");
	else{
		if(q->front == -1)
			q->front = 0;
		q->rear++;
		q->queue[q->rear] = value;
		printf("Value inserted = %d\n",value);
	}
}
int isEmpty(qu *q){
	if(q->front == -1)
		return 1;
	else
		return 0;
}
void dequeue(qu *q){
	if(isEmpty(q))
		printf("Queue is empty.\n");
	else{
		printf("Value deleted: %d\n",q->queue[q->front]);
		q->front++;
		if(q->front==q->rear)
			createQueueEmpty(q);
	}
}
void peek(qu *q){
	if(isEmpty(q))
		printf("Queue is empty.\n");
	else{
		printf("Front elements: %d\n",q->queue[q->front]);
	}
}
void displayQueue(qu *q){
	if(q->rear==-1)
		printf("Queue is empty.\n");
	else{
		int i;
		printf("Front -> %d\n",q->front);
		printf("Queue: ");
		for(i=q->front;i<=q->rear;i++)
			printf("%d ",q->queue[i]);
		printf("\nRear -> %d\n",q->rear);
	}
}
int main(){
	int ch,value;
	qu *q = (qu*)malloc(sizeof(qu));
	
	createQueueEmpty(q);
	if(q==NULL){
		printf("Allocation is not possible\n");
		return -1;
	}
	else
		printf("Allocation is successfully completed using malloc.\n");
	
	printf("MAIN MENU\n");
	printf("---------------------");
	printf("\n1.INSERT\n2.DELETE\n3.PEEK\n4.PRINT QUEUE\n5.EXIT\n");
	printf("------------------");
	while(1){
		printf("\nENTER ANY OPERATION: ");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				printf("Enter the value to insert: ");
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
				displayQueue(q);
				break;
			case 5:
				printf("Exiting...\n");
				return 0;
			default:
				printf("Invalid operation.Please try again.\n");
		}
	}
	free(q);
	return 0;
}
