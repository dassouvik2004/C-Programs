/* A Simple Queue*/
#include <stdio.h>
#define SIZE 6
int item[SIZE], rear = -1, front = -1;
void enQueue(int value){
	if(rear == SIZE -1)
		printf("Queue is full.\n");
	else{
		if(front == -1)
			front = 0;
		rear++;
		item[rear] = value;
		printf("Inserted: %d\n",value);
	}	
}

void deQueue(){
	if(front == -1)
		printf("Queue is empty.\n");
	else{
		printf("Deleted: %d\n",item[front]);
		front++;
		
		if(front>rear)
			front = rear = -1;
	}
}
void display(){
	if(rear==-1)
		printf("Queue is empty.\n");
	else{
	int i;
	printf("Queue ELements are: ");
	for(i=front;i<=rear;i++)
		printf("%d ",item[i]);
	}
	printf("\n");
}
int peek(){
	int value;
	if(front==-1){
		printf("Queue is empty.\n");
		return -1;
	}
	else{
		value = item[front];
		printf("Front elements: %d\n",value);
	}
}
int main(){
	
	int ch,value;
	do{
		printf("1.Insert\n2.Delete\n3.Peek\n4.Print Queue\n5.Exit\n");
		printf("Enter any operation: ");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				printf("Enter a value to insert in Queue: ");
				scanf("%d",&value);
				enQueue(value);
				break;
			case 2:
				deQueue();
				break;
			case 3:
				peek();
				break;
			case 4:
				display();
				break;
			case 5:
				printf("Exiting...\n");
				break;
			default:
				printf("Invalid Operation.Please try again.\n");
		}
	}while(ch!=5);

	return 0;
}
