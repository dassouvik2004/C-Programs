#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
    int data;
    struct Node *next;
}node;
typedef struct Queue{
    node *front;
    node *rear;
}queue;
queue* createQueue(){
    queue *q = (queue*)malloc(sizeof(queue));
    q->front = q->rear = NULL;
    return q;
}
void enQueue(queue *q,int data){
    node *newnode;
    newnode = (node*)malloc(sizeof(node));
    newnode->data = data;
    newnode->next = NULL;
    if(q->front==NULL)
        q->rear = q->front = newnode;
    
    q->rear->next = newnode;
    q->rear = newnode;
}
int deQueue(queue *q){
    if(q->front==NULL){
        printf("Queue is empty\n");
        return -1;
    }
    node *ptr = q->front;
    int data = ptr->data;
    q->front = q->front->next;
    
    if(q->front==NULL)
        q->rear = NULL;
    
    free(ptr);
    return data;
}
int peek(queue *q){
    if(q->front==NULL){
        printf("Queue is empty\n");
        return -1;
    }
    return q->front->data;
}
int printQueue(queue *q){
    if(q->front==NULL){
        printf("Queue is empty\n");
        return -1;
    }
    node *ptr = q->front;
    while(ptr!=NULL){
        printf("%d -> ",ptr->data);
        ptr = ptr->next;
    }
    printf("(NULL)\n");
}
int main(){
    queue *q = createQueue();
    int run = 1, data, val, del,ch;
    while(run){
        printf("1. Insert\n2. Delete\n3. Peek\n4. Print\n5. Exit\n");
        printf("----------------\n");
        printf("Enter an operation: ");
        scanf("%d",&ch);
        switch (ch){
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d",&data);
                enQueue(q,data);
                break;
            case 2:
                del = deQueue(q);
                if(del!= -1)
                    printf("Deleted item is: %d\n",del);
                break;
            case 3:
                val = peek(q);
                if(val!=-1)
                    printf("Front value: %d\n",val);
                break;
            case 4:
                printQueue(q);
                break;
            case 5:
                printf("Exiting....\n");
                run = 0;
                break;
            default:
                printf("Invalid operation. Please try again...\n");
        }
    }
    return 0;
}