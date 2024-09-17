// Deleting element at the ending in the circular linked list
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
void delete_nth(node **head,int posn){
    node *ptr;
    if(*head==NULL){
        puts("NULL node. Deletion is not possible.");
        return;
    }
    else{
        ptr = *head;
        if(posn==1){
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
        }
        else{
            int i = 1;
            node *temp;
            while(i<=posn-2 && ptr->link!=*head){
                ptr = ptr->link;
                i++;
            }
            if(ptr->link==*head){
                puts("Out of range. Please enter a valid position\n");
                return;
            }
            else{
                temp = ptr->link;
                ptr->link = temp->link;
                free(temp); 
            }
        }
    }
    printf("Successfully deleted the data from the list.\n");
}
void displayList(node *head){
    if(head==NULL){
        puts("List is empty.");
        return;
    }
    node *ptr = head;
    printf("The list: ");
    do{
        printf("%d -> ",ptr->data);
        ptr = ptr->link;
    }while(ptr!=head);

    printf("NULL\n");
}
int main(){
    node *head = NULL;
    int ch,data,posn;
    printf("1. Insert at the beginning\n");
    printf("2. Delete at the certain position\n");
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
                printf("Enter the position to delete: ");
                scanf("%d",&posn);
                delete_nth(&head,posn);
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