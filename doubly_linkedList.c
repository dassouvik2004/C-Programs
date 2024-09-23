// IT'S ALL ABOUT DOUBLY LINKED LIST(NOT TOTALLY COMPLETED)
#include <stdio.h>
#include <stdlib.h>
typedef struct DNode{
    struct DNode *prev;
    int data;
    struct DNode *next;
}Dnode;
void insertBeg(Dnode **head,int data){
    Dnode *newnode = (Dnode*)malloc(sizeof(Dnode));
    newnode->data = data;
    newnode->prev = NULL;
    newnode->next = *head;
    if(*head!=NULL)
        (*head)->prev = newnode;
    
    *head = newnode;
}
void insertEnd(Dnode **head,int data){
    Dnode *newnode = (Dnode*)malloc(sizeof(Dnode));
    Dnode *ptr = *head;
    newnode->data = data;
    newnode->next = NULL;
    if(*head==NULL){
        newnode->prev = NULL;
        *head = newnode;
    }
    else{
        while(ptr->next!=NULL)
            ptr = ptr->next;
        ptr->next = newnode;
        newnode->prev = ptr;
    }
}
void displayList(Dnode *head){
    while(head!=NULL){
        printf("%d -> ",head->data);
        head = head->next;
    }
    printf("(NULL)\n");
}
void insert_nth(Dnode **head,int data,int posn){
    Dnode *newnode = (Dnode*)malloc(sizeof(Dnode));
    Dnode *ptr = *head;
    newnode->data = data;
    if(*head==NULL|| posn==1){
        newnode->prev = NULL;
        newnode->next = *head;
        if(ptr!=NULL)
            ptr->prev = newnode;
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
void rev_display(Dnode *head){
    if(head==NULL)
        puts("List is empty\n");
    else{
        while(head->next!=NULL)
            head = head->next;
        while(head!=NULL){
            printf("%d -> ",head->data);
            head = head->prev;
        }
        printf("(NULL)\n");
    }
}
int main(){
    Dnode *head = NULL;
    int data,ch,posn;
    printf("--------MAIN MENU---------\n");
    printf("1. Insert element at the beginning\n");
    printf("2. Insert element at the ending\n");
    printf("3. Insert element at the certain position\n");
    printf("4. Display the list\n");
    printf("5. Reverse display the list\n");
    printf("6. Exit\n");
    while(1){
        printf("Enter the operation: ");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            printf("Enter the element to insert: ");
            scanf("%d",&data);
            insertBeg(&head,data);
            break;
        case 2:
            printf("Enter the element to insert: ");
            scanf("%d",&data);
            insertEnd(&head,data);
            break;
        case 3:
            printf("Enter the position to insert: ");
            scanf("%d",&posn);
            printf("Enter the element to insert at %d position: ",posn);
            scanf("%d",&data);
            insert_nth(&head,data,posn);
            break;
        case 4:
            printf("The doubly linked list: ");
            displayList(head);
            break;
        case 5:
            printf("The reverse display linked list: ");
            rev_display(head);
            break;
        case 6:
            printf("Exiting...\n");
            return 0;
        default:
            printf("Invalid operatioon. Please try again\n");
        }
    }

    return 0;
}