#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
    int data;
    struct Node *link;
}node;
void insertBegin(node **head,int data){
    node *ptr =  *head, *newnode = (node*)malloc(sizeof(node));
    newnode->data = data;
    if(*head==NULL){
        newnode->link = newnode;
        *head = newnode;
    }
    else{
        newnode->link = *head;
        while(ptr->link!=*head)
            ptr = ptr->link;
        ptr->link = newnode;
        *head = newnode;
    }
}
void insertEnd(node **head,int data){
    node *ptr = *head, *newnode;
    newnode = (node*)malloc(sizeof(node));
    newnode->data = data;
    if(*head==NULL){
        newnode->link = newnode;
        *head = newnode;
    }
    else{
        newnode->link = *head;
        while(ptr->link!=*head)
            ptr = ptr->link;
        ptr->link = newnode;
    }
}
void insert_nth(node **head,int data,int posn){
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
void deleteBegin(node **head){
    node *ptr = *head;
    if(*head==NULL)
        puts("NULL node. Deletion is not possible\n");
    else{
        if(ptr->link == ptr){
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
        printf("Succesfully deleted the first node.\n");
    }
    
}
void deleteEnd(node **head){
    node *ptr = *head;
    if(*head==NULL)
        puts("NULL node. Deletion is not possible.\n");
    else{
        if(ptr->link==ptr){
            *head = NULL;
            free(ptr);
        }
        else{
            // while(ptr->link->link!=*head)
            //     ptr = ptr->link;
            // free(ptr->link);
            
            // ptr->link = *head;
            node *prev;
            while(ptr->link!=*head){
                prev = ptr;
                ptr = ptr->link;
            }
            prev->link = *head;
            free(ptr);
        }
        printf("Succssfully deleted the last node.\n");
    }
}
int delete_nth(node **head,int val){
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
void displayList(node *head){
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
void freeSpace(node **head) {
    if(*head == NULL)
        puts("List is empty.\n");
    else{
        node *ptr = *head, *temp;
        ptr = (*head)->link;
        while (ptr != *head){
            temp = ptr;
            ptr = ptr->link;
            free(temp);
        }
        free(*head);
        *head = NULL;
    }
}
int main(){
    node *head = NULL;
    int ch,data,posn,posn2;
    printf("MAIN MENU\n");
    printf("------------------\n");
    printf("1. Insert element at the beginning\n");
    printf("2. Insert element at the ending\n");
    printf("3. Insert element at the certain position.\n");
    printf("4. Delete element at the beginning\n");
    printf("5. Delete element at the ending\n");
    printf("6. Delete element at the certain position.\n");
    printf("7. Display the list\n");
    printf("8. Exit\n");
    printf("------------------\n");
    while(1){
        printf("Enter any operation: ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                printf("Enter the data to insert at the beginning: ");
                scanf("%d",&data);
                insertBegin(&head,data);
                break;
            case 2:
                printf("Enter the data to insert at the ending: ");
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
                deleteBegin(&head);
                break;
            case 5:
                deleteEnd(&head);
                break;
            case 6:
                printf("Enter the element to delete: ");
                scanf("%d",&data);
                delete_nth(&head,data);
                break;
            case 7:
                displayList(head);
                break;
            case 8:
                printf("Exiting...\n");
                freeSpace(&head);
                return 0;
            default:
                printf("Invalid operation.Please try again.\n");
        }
    }
    return 0;
}