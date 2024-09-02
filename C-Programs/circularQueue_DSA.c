#include <stdio.h>
#define SIZE 5
int rear = -1,front = -1;
int queue[SIZE];
int isfull(){
	if((rear+1)%SIZE == front)
		return 1;
	else
		return 0;
}
void enqueue(int value){
	if(isfull())
		printf("Queue is full..\n");
	else{
		if(front==-1)
			front = 0;
		rear = (rear+1)%SIZE;
		queue[rear] = value;
		printf("Value inserted = %d\n",value);
	}
}
int isempty(){
	if(front == -1)
		return 1;
	else
		return 0;
}
int dequeue(){
	int element;
	if(isempty()){
		printf("Queue is empty...\n");
		return -1;
	}
	else{
		element = queue[front];
		if(front == rear)
			front = rear = -1;
		else
			front = (front+1)%SIZE;
		
		printf("Value deleted: %d\n",element);
	}		
}

void display(){
	int i;
	if(isempty())
		printf("\nEmpty Queue\n");
	else{
		printf("\n Front -> %d",front);
		printf("\n Items -> ");
		for(i=front;i!=rear;i=(i+1)%SIZE)
			printf("%d ",queue[i]);
		
		printf("%d ",queue[rear]);
		printf("\n Rear -> %d\n",rear);
	}
}
int main(){
	int value,ch;
	do{
		printf("1. Insert\n2. Delete\n3. Print Queue\n4. Exit\n");
		printf("Enter any operation: ");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				printf("Enter value to insert in queue: ");
				scanf("%d",&value);
				enqueue(value);
				break;
			case 2:
				dequeue();
				break;
			case 3:
				display();
				break;
			case 4:
				printf("Exiting....\n");
				break;
			default:
				printf("Invalid operation..Please try again!!\n");
		}
	}while(ch!=4);
	
	return 0;
}
