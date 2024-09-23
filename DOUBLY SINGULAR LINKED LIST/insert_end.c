// Inserting element at the ending in the doubly singular linked list
#include <stdio.h>
#include <stdlib.h>
typedef struct DNode{
    struct DNode *prev;
    int data;
    struct DNode *next;
}Dnode;
void insert_end(Dnode **head,int data){
    Dnode *ptr, *newnode;
    ptr = *head;
    newnode = (Dnode*)malloc(sizeof(Dnode));
    newnode->data = data;
    newnode->next = NULL;
    if(*head==NULL){
        newnode->prev = NULL;
        newnode->next = *head;
        *head = newnode;
    }
    else{
        while(ptr->next!=NULL)
            ptr = ptr->next;
        
        newnode->prev = ptr;
        if(ptr->next!=NULL)
            ptr->next->prev = newnode;
        
        ptr->next = newnode;
    }
}
void displayList(Dnode *head){
    while(head!=NULL){
        printf("%d -> ",head->data);
        head = head->next;
    }
    printf("(NULL)\n");
}
int main(){
    Dnode *head = NULL;
    int ch,data;
    printf("1. Insert the element at the ending\n");
    printf("2. Display the list\n");
    printf("3. Exit\n");
    printf("-------------------\n");
    while(1){
        printf("Enter your operation: ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                printf("Enter the data to insert: ");
                scanf("%d",&data);
                insert_end(&head,data);
                break;
            case 2:
                printf("The list: ");
                displayList(head);
                break;
            case 3:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid operation. Please try again\n");
        }
    }
    return 0;
}