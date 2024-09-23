// Inserting element at the certain position in the doubly singular linked list
#include <stdio.h>
#include <stdlib.h>
typedef struct DNode{
    struct DNode *prev;
    int data;
    struct DNode *next;
}Dnode;

void insert_nth(Dnode **head,int data,int posn){
    Dnode *ptr = *head, *newnode;
    newnode = (Dnode*)malloc(sizeof(Dnode));
    newnode->data = data;
    if(*head==NULL || posn==1){
        newnode->prev = NULL;
        newnode->next = *head;
        if((*head)!=NULL)
            (*head)->prev = newnode;
        
        *head = newnode;
    }
    else{
        int c;
        for(c=1;c<=posn-2 && ptr->next!=NULL;c++)
            ptr = ptr->next;
        
        newnode->prev = ptr;
        newnode->next = ptr->next;
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
    int ch,data,posn;
    printf("1. Insert the element at the ending\n");
    printf("2. Display the list\n");
    printf("3. Exit\n");
    printf("-------------------\n");
    while(1){
        printf("Enter your operation: ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                printf("Enter the position to insert: ");
                scanf("%d",&posn);
                printf("Enter the data to insert at %d position: ",posn);
                scanf("%d",&data);
                insert_nth(&head,data,posn);
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