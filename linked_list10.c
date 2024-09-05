// Delete the element at any position
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
void delete_Any(node **head,int val){
    node *ptr,*prev;
    ptr = *head;
    if(*head==NULL){
        puts("NULL node. Delection isn't possible.\n");
    }
    else{
        if(ptr->data==val){
            *head = ptr->link;
            free(ptr);
        }
        else{
            prev = ptr;
            ptr = ptr->link;
            while(ptr!=NULL){
                if(ptr->data==val)
                    break;
                prev = ptr;
                ptr = ptr->link;
            }
            if(ptr==NULL)
                puts("Node not found");
            else{
                prev->link = ptr->link;
                free(ptr);
                printf("Successfully deleted the value from the list.\n");
            }
        }
    }
}
int main(){
    node *head = NULL;
    int ch,n,i,data,val;
    printf("MAIN MENU\n");
    printf("-------------------\n");
    printf("1. Insert at the beginning\n");
    printf("2. Delete the value at any position\n");
    printf("3. Display the list\n");
    printf("4. Exit\n");
    printf("-------------------\n");
    while(1){
        printf("Enter any operation: ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d",&data);
                insertBegin(&head,data);
                break;
            case 2:
                printf("Enter the value to delete: ");
                scanf("%d",&val);
                delete_Any(&head,val);
                break;
            case 3:
                displayList(head);
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