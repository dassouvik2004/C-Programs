// Deleting element at the certain position of the doubly singular linked list
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
void delete_nth(Dnode **head,int posn){
    Dnode *ptr;
    if(*head==NULL)
        puts("List is empty\n");
    else{
        ptr = *head;
        if(posn==1){
            if(ptr->next==NULL)
                *head = NULL;
            else{
                ptr->next->prev = NULL;
                *head = ptr->next;
            }
            free(ptr);
            printf("Successfully deleted the given position node\n");            
        }
        else{
            int c;
            Dnode *temp;
            for(c=1;c<=posn-2 && ptr->next!=NULL;c++)
                ptr = ptr->next;
            if(ptr->next==NULL || posn<=0)
                puts("Position is invalid. Please try again\n");
            else{
                temp = ptr->next;
                ptr->next = temp->next;
                if(temp->next!=NULL)
                    temp->next->prev = ptr;
                free(temp);
                printf("Successfully deleted the given position node\n");
            }
        }
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
    int ch,data,posn;
    printf("1. Insert the elememt at the beginning\n");
    printf("2. Display the list\n");
    printf("3. Delete the element from the certain position\n");
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
                printf("Enter the position to delete: ");
                scanf("%d",&posn);
                delete_nth(&head,posn);
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