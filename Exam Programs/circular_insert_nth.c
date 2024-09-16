// Inserting element at the ending in the circular linked list
#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
    int data;
    struct Node *link;
}node;
void insertEnd(node **head,int data,int posn){
    node *newnode,*ptr;
    int i = 1;
    newnode = (node*)malloc(sizeof(node));
    newnode->data = data;
    if(*head==NULL){
        newnode->link = newnode;
        *head = newnode;
    }
    else{
        ptr = *head;
        if(posn==1){
            newnode->link = *head;
            while(ptr->link!=*head){
                ptr = ptr->link;
            }
            ptr->link = newnode;
            *head = newnode;
        }
        else{
            while(i<=posn-2 && ptr->link!=*head){
                ptr = ptr->link;
                i++;
            }
            newnode->link = ptr->link;
            ptr->link = newnode;
        }
    }
}
void displayList(node *head){
    node *ptr;
    
    ptr = head;
    do{
        printf("%d -> ",ptr->data);
        ptr = ptr->link;
    }while(ptr!=head);
    printf("NULL\n");
}
int main(){
    node *head = NULL;
    int ch,data,posn;
    printf("1. Enter element to insert at the certain positon\n");
    printf("2. Display the list\n");
    printf("3. Exit\n");
    while(1){
        printf("Enter the operation: ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                printf("Enter the position to insert: ");
                scanf("%d",&posn);
                printf("Enter the element to insert at %d positon: ",posn);
                scanf("%d",&data);
                insertEnd(&head,data,posn);
                break;
            case 2:
                printf("The list: ");
                displayList(head);
                break;
            case 3:
                printf("Exiting.....\n");
                return 0;
            default:
                printf("Invalid operation.Please try again.\n");
        }
    }
    return 0;
}