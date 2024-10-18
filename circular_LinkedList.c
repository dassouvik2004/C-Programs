// CIRCULAR LINKED LIST
#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
    int data;
    struct Node *link;
}node;
void insert(node **head,int data,int posn){
    node *ptr = *head, *newnode;
    newnode = (node*)malloc(sizeof(node));
    int i;
    newnode->data = data;
    if(*head==NULL){
        newnode->link = newnode;
        *head = newnode;
    }
    else{
        if(posn==1){
            newnode->link = *head;
            while(ptr->link!=*head)
                ptr = ptr->link;
            ptr->link = newnode;
            *head = newnode;
        }
        else{
            for(i=1;i<=posn-2 && ptr->link!=*head;i++)
                ptr = ptr->link;
            newnode->link = ptr->link;
            ptr->link = newnode;
        }
    }
}
int delete(node **head,int val){
    node *ptr = *head;
    if(*head==NULL){
        puts("NULL node. Deletion is not possible.\n");
        return -1;
    }
    else{
        if(ptr->data == val){
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
            printf("Successfully deleted the given element...\n");
        }
        else{
            node *prev = *head;
            ptr = ptr->link;
            while(ptr!=*head){
                if(ptr->data==val)
                    break;
                prev = ptr;
                ptr = ptr->link;
            }
            if(ptr==*head){
                printf("Element is not found.\n");
                return -1;
            }
            else{
                prev->link = ptr->link;
                free(ptr);
            }
            printf("Successfully deleted the given element...\n");   
        }
    }
}
void printList(node *head){
    if(head==NULL)
        puts("List is empty.");
    else{
        node *ptr;
        ptr = head;
        do{
            printf("%d -> ",ptr->data);
            ptr = ptr->link;
        }while(ptr!=head);

        printf("(head)\n");
    }
}
int main(){
    node *head = NULL;
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
                printf("Enter the element to delete: ");
                scanf("%d",&data);
                delete(&head,data);
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