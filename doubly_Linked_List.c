// DOUBLY LINKED LIST
#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
    int data;
    struct Node *prev;
    struct Node *next;
}Dnode;
void insert(Dnode **head,int data,int posn){
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
void delete(Dnode **head,int posn){
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
void printList(Dnode *head){
    if(head==NULL)
        printf("List is empty...\n");
    else{
        printf("The Linked List: ");
        while(head!=NULL){
            printf("%d -> ",head->data);
            head = head->next;
        }
        printf("(NULL)\n");
    }
}
int main(){
    Dnode *head = NULL;
    int run = 1, ch, data,posn;
    while(run){
        printf("---MAIN MENU---\n");
        printf("1. Inserting element at any position\n");
        printf("2. Deleting element from any position\n");
        printf("3. Display the list\n");
        printf("4. Exiting\n");
        printf("--------------------------\n");
        printf("Enter an operation: ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                printf("Enter the position to insert: ");
                scanf("%d",&posn);
                printf("Enter the data to insert at %d position: ",posn);
                scanf("%d",&data);
                insert(&head,data,posn);
                break;
            case 2:
                printf("Enter the position to delete: ");
                scanf("%d",&posn);
                delete(&head,posn);
                break;
            case 3:
                printList(head);
                break;
            case 4:
                printf("Exiting...\n");
                run = 0;
                break;
            default:
                printf("Invalid operation.. Please try again...\n");
        }
    } 
    return 0;
}