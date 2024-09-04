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
node* maxNode(node **head){
    int max;
    node *ptr,*temp;
    ptr = NULL;
    if(*head == NULL){
        printf("List is empty.\n");
        return NULL;
    }
    else{
        ptr = *head;
        max = ptr->data;
        ptr = ptr->link;
        while(ptr!=NULL){
            if(ptr->data>max){
                max = ptr->data;
                temp = ptr; 
            }
            ptr = ptr->link;
        }
        return temp;
    } 
}
void displayList(node *head){
    while(head!=NULL){
        printf("%d -> ",head->data);
        head = head->link;
    }
    printf("NULL\n");
}
void sortingList(node **head){
    node *current, *next;
    current = *head;
    int max,temp;
    while(current!=NULL){
        max = current->data;
        next = current->link;
        while(next!=NULL){
            if(current->data>next->data){
                temp = current->data;
                current->data = next->data;
                current->data = temp; 
            }
            next = next->link;
        }
        current = current->link;
    }
}
int deleteEnd(node **head){
    node *temp;
    if(*head==NULL){
        printf("NULL list. Delection is not possible.\n");
        return 0;
    }
    else{
        temp = *head;
        if(temp->link==NULL){
            *head = NULL;
            free(temp);
        }
        else{
            while(temp->link->link!=NULL){
                temp = temp->link;
            }
            free(temp->link);
            temp->link = NULL;
        }
        printf("Successfully deleted the last node.\n");
    }
}
int main(){
    node *head = NULL;
    int ch,n,i,data;
    printf("MAIN MENU\n");
    printf("-------------------\n");
    printf("1. Insert at the beginning\n");
    printf("2. Delete at the ending\n");
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
                deleteEnd(&head);
                break;
            case 3:
                printf("The list: ");
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