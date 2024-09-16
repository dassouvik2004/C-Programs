// Deleting element at the beginning in the circular linked list
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
void deleteBeg(node **head){
    node *ptr;
    if(*head==NULL)
        puts("NULL node. Deletion is not possible.\n");
    else{
        ptr = *head;
        if(ptr->link==ptr){
            *head = NULL;
            free(ptr);
        }
        else{
            while(ptr->link!=*head)
                ptr = ptr->link;
            
            ptr->link = (*head)->link;
            free(*head);
            *head = ptr->link;
        }
        printf("Deleting element at the beginning of the list.\n");
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
    int ch,data;
    printf("1. Insert at the beginning\n");
    printf("2. Delete at the beginning\n");
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
                deleteBeg(&head);
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