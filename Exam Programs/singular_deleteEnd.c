// Deleting element at the ending in the singular linked list
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
    newnode->link = *head;
    *head = newnode;
}
void deleteEnd(node **head){
    node *ptr;
    if(*head==NULL)
        puts("Null node. Deletion is not possible.\n");
    else{
        ptr = *head;
        if(ptr->link==NULL){
            *head = NULL;
            free(ptr);
        }
        else{
            node *prev;
            while(ptr->link!=NULL){
                prev = ptr;
                ptr = ptr->link;
            }
            prev->link = NULL;
            free(ptr);
            printf("Successfully deleted the last element of the list.\n");
        }
        
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
    printf("1. Insert at the beginning\n");
    printf("2. Delete at the ending\n");
    printf("3. Display the list\n");
    printf("4. Exit\n");
    while(1){
        printf("Enter the operation: ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                printf("Enter the data to insert: ");
                scanf("%d",&data);
                insertBeg(&head,data);
                break;
            case 2:
                deleteEnd(&head);
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