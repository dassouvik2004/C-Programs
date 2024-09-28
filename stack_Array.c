#include <stdio.h>
#define SIZE 5
typedef struct Stack{
    int top;
    int item[SIZE];
}stack;
int isFull(stack st){
    if(st.top==SIZE-1)
        return 1;
    else
        return 0;
}
int isEmpty(stack st){
    if(st.top==-1)
        return 1;
    else    
        return 0;
}
void push(stack *st,int data){
    st->top++;
    st->item[st->top] = data;
}
int pop(stack *st){
    int temp = st->item[st->top];
    st->top--;
    return temp;
}
int peek(stack st){
    int temp = st.item[st.top];
    return temp;
}
void printStack(stack st){
    int i;
    for(i=0;i<=st.top;i++)
        printf("%d ",st.item[i]);
    printf("\n");
}
int main(){
    stack st;
    st.top = -1;
    int data,ch,del,val,run=1;
    while(run){
        printf("1. Push\n2. Pop\n3. Peek\n4. Print\n5. Exit\n");
        printf("Enter any operation: ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                printf("Enter the data to push: ");
                scanf("%d",&data);
                if(isFull(st))
                    printf("Stack is overflow\n");
                else{
                    push(&st,data);
                    printf("%d pushed successfully in stack\n",data);
                }
                break;
            case 2:
                if(isEmpty(st))
                    printf("Stack is underflow\n");
                else{
                    del = pop(&st);
                    printf("The deleted element is %d\n",del);
                }
                break;
            case 3:
                if(isEmpty(st))
                    printf("Stack is underflow\n");
                else{
                    val = peek(st);
                    printf("The top element is %d\n",val);
                }
            case 4:
                if(isEmpty(st))
                    printf("Stack is underflow\n");
                else{
                    printf("Stack: ");
                    printStack(st);
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