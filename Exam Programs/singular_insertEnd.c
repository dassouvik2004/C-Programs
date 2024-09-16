// Inserting element at the ending in the singular linked list
#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
    int data;
    struct Node *link;
}node;
void insertEnd(node **head,int data){
    node *newnode,*ptr;
    newnode = (node*)malloc(sizeof(node));
    newnode->data = data;
    if(*head==NULL){
        newnode->link = *head;
        *head = newnode;
    }
    else{
        ptr = *head;
        while(ptr->link!=NULL)
            ptr = ptr->link;
        
        newnode->link = ptr->link;
        ptr->link = newnode;
    }
}
void displayList(node *head){
    while(head!=NULL){
        printf("%d -> ",head->data);
        head = head->link;
    }
    printf("NULL\n");
}
int main(){
    node *head = NULL;
    int ch,data;
    printf("1. Enter element to insert at the ending\n");
    printf("2. Display the list\n");
    printf("3. Exit\n");
    while(1){
        printf("Enter the operation: ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d",&data);
                insertEnd(&head,data);
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