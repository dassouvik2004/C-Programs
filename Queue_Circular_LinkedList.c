// Queue implementation using circular linked list
#include <stdio.h>
#include <stdlib.h>
typedef struct Queue{
    int data;
    struct Queue *next;
}queue;
void enQueue(queue **tail,int data){
    queue *ptr, *newnode;
    newnode = (queue*)malloc(sizeof(queue));
    newnode->data = data;
    if(*tail==NULL){
        newnode->next = newnode;
        *tail = newnode;
    }
    else{
        ptr = *tail;
        newnode->next = ptr->next;
        ptr->next = newnode;
        *tail = newnode;
    }
}
int deQueue(queue **tail){
    queue *ptr = *tail;
    if(ptr==NULL)
        return -1;
    else{
        queue *temp;
        int val;
        if(ptr->next==ptr){
            val = ptr->data;
            *tail = NULL;
            free(ptr);
        }
        else{
            temp = ptr->next;
            val = temp->data;
            ptr->next = temp->next;
            free(temp);
        }
        return val;
    }
}
int peek(queue *tail){
    if(tail==NULL)
        return -1;
    else
        return tail->next->data;
}
void printQueue(queue *tail){
    if(tail==NULL)
        printf("Queue is empty\n");
    else{
        queue *ptr;
        ptr = tail->next;
        do{
            printf("%d -> ",ptr->data);
            ptr = ptr->next;
        }while(ptr!=tail->next);
        printf("(tail)\n");
    }
}
int main(){
    queue *tail = NULL;
    int run = 1, ch, data, val;
    while(run){
        printf("1. Enqueue\n2. Dequeue\n3. Peek\n4. Print\n5. Exit\n");
        printf("----------------\n");
        printf("Enter an operation: ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                printf("Enter the data to insert: ");
                scanf("%d",&data);
                enQueue(&tail,data);
                break;
            case 2:
                val = deQueue(&tail);
                if(val==-1)
                    printf("Queue is empty\n");
                else
                    printf("Delete item is %d\n",val);
                break;
            case 3:
                val = peek(tail);
                if(val==-1)
                    printf("Queue is empty\n");
                else
                    printf("The front element is %d\n",val);
                break;
            case 4:
                printQueue(tail);
                break;
            case 5:
                printf("Exiting...\n");
                run = 0;
                break;
            default:
                printf("Invalid operation. Please try again...\n");
        }
    }
    return 0;
}