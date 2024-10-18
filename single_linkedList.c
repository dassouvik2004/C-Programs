// SINGLE LINKED LIST
#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
    int data;
    struct Node *link;
}node;
void insert(node **head,int data,int posn){
    node *newnode;
    newnode = (node*)malloc(sizeof(node));
    newnode->data = data;
    if(*head==NULL || posn==1){
        newnode->link = *head;
        *head = newnode;
    }
    else{
        node *ptr = *head;
        int i;
        for(i=1;i<=posn-2 && ptr->link!=NULL;i++)
            ptr = ptr->link;

        newnode->link = ptr->link;
        ptr->link = newnode;
    }
}
int delete(node **head,int data){
    if(*head==NULL){
        printf("NULL list. Deletion is not possible\n");
        return -1;
    }
    else{
        node *prev, *cur;
        cur = *head;
        if(cur->data==data){
            *head = cur->link;
            free(cur);
        }
        else{
            prev = cur;
            cur = cur->link;
            while(cur!=NULL){
                if(cur->data==data)
                    break;
                prev = cur;
                cur = cur->link;
            }
            if(cur==NULL){
                printf("Element is not found...\n");
                return -1;
            }
            else{
                prev->link = cur->link;
                free(cur);
            }
        }
        printf("Successfully delete %d from the list...\n",data);
    }
}
void printList(node *head){
    if(head==NULL)
        printf("List is empty...\n");
    else{
        printf("The Linked List: ");
        while(head!=NULL){
            printf("%d -> ",head->data);
            head = head->link;
        }
        printf("(NULL)\n");
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