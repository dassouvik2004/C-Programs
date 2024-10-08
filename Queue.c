#include <stdio.h>
#define SIZE 10
typedef struct Queue{
    int rear;
    int front;
    int arr[SIZE];
}queue;
void createEmptyQueue(queue *q){
    q->front = q->rear = -1;
}
int isFull(queue q){
    return (q.front == 0 && q.rear == SIZE - 1);
}
int isEmpty(queue q){
    return (q.front == -1 && q.rear == -1);
}
void enQueue(queue *q,int data){
    int i,j=0;
    if(q->front == -1 && q->rear == -1)
        q->front = q->rear = 0;
    else{
        if(q->rear == SIZE - 1){
            for(i=q->front;i<=q->rear;i++){
                q->arr[j] = q->arr[i];
                j++;
            }
        }
        else  
            q->rear++;
    }
    q->arr[q->rear] = data;
}
int deQueue(queue *q){
    int temp = q->arr[q->front];
    if(q->front == q->rear)
        q->front = q->rear = -1;
    else 
        q->front++;
    
    return temp;
}
int peek(queue q){
    int temp;
    return temp = q.arr[q.front];
}
void printQueue(queue q){
    int i;
    printf(" rear -> %d",q.rear);
    printf("\nThe Queue: ");
    for(i=q.front;i<=q.rear;i++)
        printf("%d ",q.arr[i]);
    printf("\n");
    printf(" front -> %d\n",q.front);
}
int main(){
    queue q;
    int ch,run = 1, data, del, val;
    createEmptyQueue(&q);
    while(run){
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Print\n");
        printf("5. Exit\n");
        printf("Enter an operation: ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                if(isFull(q))
                    printf("Queue is overflow\n");
                else{
                    printf("Enter the element to insert: ");
                    scanf("%d",&data);
                    enQueue(&q,data);
                    printf("%d is successfully inserted in the queue\n",data);
                }
                break;
            case 2:
                if(isEmpty(q))
                    printf("Queue is underflow\n");
                else{
                    del = deQueue(&q);
                    printf("The deleted element is %d\n",del);
                }
                break;
            case 3:
                if(isEmpty(q))
                    printf("Queue is underflow\n");
                else{
                    val = peek(q);
                    printf("The top element is %d\n",val);
                }
                break;
            case 4:
                if(isEmpty(q))
                    printf("Queue is underflow\n");
                else{
                    printQueue(q);
                    break;
                }
            case 5:
                printf("Exiting...\n");
                run = 0;
                break;
            default:
                printf("Invalid operation. Please try again\n");
        }
    }
    return 0;
}