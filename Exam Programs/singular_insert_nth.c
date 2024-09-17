// Inserting element at the certain position in the singular linked list
#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
    int data;
    struct Node *link;
}node;
void insertEnd(node **head,int data,int posn){
    node *newnode,*ptr;
    int i=1;
    newnode = (node*)malloc(sizeof(node));
    newnode->data = data;
    if(*head==NULL || posn==1){
        newnode->link = *head;
        *head = newnode;
    }
    else{
        ptr = *head;
        while(i<=posn-2 && ptr->link!=NULL){
            ptr = ptr->link;
            i++;
        }
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
    int ch,data,posn;
    printf("1. Insert element at the certain position\n");
    printf("2. Display the list\n");
    printf("3. Exit\n");
    while(1){
        printf("Enter the operation: ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                printf("Enter the position to insert: ");
                scanf("%d",&posn);
                printf("Enter the element to insert at %d position: ",posn);
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