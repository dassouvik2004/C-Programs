// Summatation data in the circular linked list
#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
    int data;
    struct Node *link;
}node;
void insertBeg(node **head,int data){
    node *newnode;
    newnode = (node*)malloc(sizeof(node));
    newnode->data = data;
    if(*head==NULL){
        newnode->link = newnode;
        *head = newnode;
    }
    else{
        newnode->link = *head;
        node *ptr = *head;
        while(ptr->link!=*head){
            ptr = ptr->link;
        }
        ptr->link = newnode;
        *head = newnode;
    }
}
int Sum_Data(node *head){
    int sum;
    if(head==NULL)
        return -1;
    else{
        node *ptr;
        ptr = head;
        do{
            sum += ptr->data;
            ptr = ptr->link;
        }while(ptr!=head);

        return sum;
    }
}
void displayList(node *head){
    node *ptr = head;
    do{
        printf("%d -> ",ptr->data);
        ptr = ptr->link;
    }while(ptr!=head);

    printf("NULL\n");
}
int main(){
    node *head = NULL;
    int ch,data,sum;
    printf("1. Enter element to insert at the beginning\n");
    printf("2. Summatation of the data\n");
    printf("2. Display the list\n");
    printf("3. Exit\n");
    while(1){
        printf("Enter the operation: ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d",&data);
                insertBeg(&head,data);
                break;
            case 2:
                sum = Sum_Data(head);
                if(sum == -1)
                    printf("The list is empty");
                else 
                    printf("Summatation of data in the list: %d\n",sum);
                break;
            case 3:
                printf("The list: ");
                displayList(head);
                break;
            case 4:
                printf("Exiting.....\n");
                return 0;
            default:
                printf("Invalid operation.Please try again.\n");
        }
    }
    return 0;
}