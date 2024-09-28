// Stack implementation using linked list
#include <stdio.h>
#include <stdlib.h>
typedef struct Stack{
    int data;
    struct Stack *link;
}stack;
int isEmpty(stack *head){
    if(head==NULL)
        return 1;
    else
        return 0;
}
void push(stack **head,int data){
    stack *newnode = (stack*)malloc(sizeof(stack));
    newnode->data = data;
    newnode->link = *head;
    *head = newnode;
}
int pop(stack **head){
    stack *ptr = *head;
    int val;
    *head = ptr->link;
    val = ptr->data;
    free(ptr);
    return val;
}
int peek(stack *head){
    stack *ptr = head;
    int val = ptr->data;
    return val;
}
void printStack(stack *head){
    while(head!=NULL){
        printf("%d ",head->data);
        head = head->link;
        if(head!=NULL)
            printf("-> ");
    }
    printf("\n");
}
int main(){
    stack *head = NULL;
    int ch,data,run=1,val,del;
    while(run){
        printf("1. Push\n2. Pop\n3. Peek\n4. Print\n5. Exit\n");
        printf("Enter an operation: ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                printf("Enter the data to push: ");
                scanf("%d",&data);
                push(&head,data);
                printf("The element %d is pushed successfully\n",data);
                break;
            case 2:
                if(isEmpty(head))
                    printf("Stack is underflow\n");
                else{
                    del = pop(&head);
                    printf("The delete element is %d\n",del);
                }
                break;
            case 3:
                if(isEmpty(head))
                    printf("Stack is underflow\n");
                else{
                    val = peek(head);
                    printf("The top element is %d\n",val);
                }
                break;
            case 4:
                if(isEmpty(head))
                    printf("Stack is underflow\n");
                else{
                    printf("Stack: ");
                    printStack(head);
                }
                break;
            case 5:
                printf("Exiting...\n");
                run = 0;
                break;
            default:
                printf("Invalid operation. Please try again.\n");
        }
    }
    return 0;
}