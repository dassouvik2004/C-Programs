// Deleting element at the certain position in the circular linked list
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
void deleteEnd(node **head){
    node *ptr;
    if(*head==NULL){
        puts("NULL node. Deletion is not possible.");
        return;
    }
    else{
        ptr = *head;
        if(ptr->link==ptr){
            *head = NULL;
            free(ptr);
            printf("Deleting element at the ending of the list.\n");
            return;
        }
        else{
            while(ptr->link->link!=*head)
                ptr = ptr->link;
            
            free(ptr->link);
            ptr->link = *head;
            printf("Deleting element at the ending of the list.\n");
        }
    }
}
void displayList(node *head){
    if(head==NULL){
        puts("List is empty.");
        return;
    }
    node *ptr = head;
    do{
        printf("The list: ");
        printf("%d -> ",ptr->data);
        ptr = ptr->link;
    }while(ptr!=head);

    printf("NULL\n");
}
int main(){
    node *head = NULL;
    int ch,data;
    printf("1. Insert at the beginning\n");
    printf("2. Delete at the ending\n");
    printf("3. Display the list\n");
    printf("4. Exit\n");
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
                deleteEnd(&head);
                break;
            case 3:
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