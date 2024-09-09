// Reversing the linked list using recursion function
#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int data;
    struct node *link;
}node;
void insertBegin(node **head, int data){
    node *newnode;
    newnode = (node*)malloc(sizeof(node));
    newnode->data = data;
    newnode->link = *head;
    *head = newnode;
}
void displayList(node *head){
    while(head!=NULL){
        printf("%d -> ",head->data);
        head = head->link;
    }
    printf("NULL\n");
}
void display_rev(node *head){
    node *ptr;
    if(head!=NULL){
        ptr = head;
        display_rev(head->link);
        printf("%d ",ptr->data);
    }
}
int main(){
    node *head = NULL;
    int ch,n,i,data,val;
    printf("MAIN MENU\n");
    printf("-------------------\n");
    printf("1. Insert at the beginning\n");
    printf("2. Display the list\n");
    printf("3. Display the list in reverse order using recursion.\n");
    printf("4. Exit\n");
    printf("-------------------\n");
    while(1){
        printf("\nEnter any operation: ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d",&data);
                insertBegin(&head,data);
                break;
            case 2:
                displayList(head);
                break;
            case 3:
                display_rev(head);
                break;
            case 4:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid operation. Please try again.\n");
        }
    }
    
    node *temp;
    while(head!=NULL){
        temp = head;
        head = head->link;
        free(temp);
    }
    return 0;
}