#include <stdio.h>
#include <stdlib.h>
typedef struct stack{
    int data;
    struct stack *link;
}st;
int isEmpty(st *top){
   int temp = (top==NULL) ? 1 : 0;
   return temp;
}
void push(st **top,int data){
    st *newnode = (st*)malloc(sizeof(st));
    newnode->data = data;
    newnode->link = *top;
    *top = newnode;
}
int pop(st **top){
    st *ptr = *top;
    int temp = ptr->data;
    *top = ptr->link;
    free(ptr);
    return temp;
}
int peek(st *top){
    int temp = top->data;
    return temp;
}
void printStack(st *top){
    while(top!=NULL){
        printf("%d",top->data);
        top = top->link;
        if(top!=NULL)
            printf(" -> ");
    }
    printf("\n");
}
int main(){
    st *top = NULL;
    int ch,data,run=1,val,del;
    while(run){
        printf("1. Push\n2. Pop\n3. Peek\n4. Print\n5. Exit\n");
        printf("Enter an operation: ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                printf("Enter the data to push: ");
                scanf("%d",&data);
                push(&top,data);
                printf("The element %d is successfully pushed in the stack\n",data);
                break;
            case 2:
                if(isEmpty(top))
                    printf("Stack underflow\n");
                else{
                    del = pop(&top);
                    printf("The delete element is %d\n",del);
                }
                break;
            case 3:
                if(isEmpty(top))
                    printf("Stack underflow\n");
                else{
                    val = peek(top);
                    printf("The top element is %d\n",val);
                }
                break;
            case 4:
                if(isEmpty(top))
                    printf("Stack underflow\n");
                else{
                    printf("Stack: ");
                    printStack(top);
                }
                break;
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