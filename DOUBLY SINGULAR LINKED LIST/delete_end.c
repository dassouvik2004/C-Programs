// Deleting element at the ending of the doubly singular linked list
#include <stdio.h>
#include <stdlib.h>
typedef struct DNODE{
    struct DNODE *prev;
    int data;
    struct DNODE *next;
}Dnode;
void insert_beg(Dnode **head,int data){
    Dnode *newnode = (Dnode*)malloc(sizeof(Dnode));
    newnode->data = data;
    newnode->prev = NULL;
    newnode->next = *head;
    if(*head!=NULL)
        (*head)->prev = newnode;
    *head = newnode;
}
void delete_end(Dnode **head){
    Dnode *ptr;
    ptr = *head;
    if(ptr==NULL)
        puts("NULL node. Deletion is not possible\n");
    else{
        if(ptr->next==NULL){
            *head = NULL;
            free(ptr);
        }
        else{
            while(ptr->next->next!=NULL)
                ptr = ptr->next;
        
            free(ptr->next);
            ptr->next = NULL;
        }
        printf("Successfully deleted the last element\n"); 
    }
}
void displayList(Dnode *head){
    if(head==NULL)
        puts("List is empty");
    else{
        while(head!=NULL){
            printf("%d -> ",head->data);
            head = head->next;
        }
        printf("(NULL)\n");
    }
}
int main(){
    Dnode *head = NULL;
    int ch,data;
    printf("1. Insert the elememt at the beginning\n");
    printf("2. Display the list\n");
    printf("3. Delete the element from the ending\n");
    printf("4. Exit\n");
    printf("------------------------------------\n");
    while(1){
        printf("Enter any opeartion: ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d",&data);
                insert_beg(&head,data);
                break;
            case 2:
                printf("The Doubly linked list: ");
                displayList(head);
                break;
            case 3:
                delete_end(&head);
                break;
            case 4:
                printf("Exiting\n");
                return 0;
            default:
                printf("Invalid operation. Please try again\n");
        }
    }
    return 0;
}