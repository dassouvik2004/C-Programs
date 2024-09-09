#include <stdio.h>
#include <stdlib.h>
typedef struct NODE{
    int data;
    struct NODE *link;
}node;
void insertBegin(node **head,int data){
    node *newnode = (node*)malloc(sizeof(node));
    newnode->data = data;
    newnode->link = *head;
    *head = newnode;
}
void insertEnd(node **head,int data){
    node *newnode, *ptr;
    newnode = (node*)malloc(sizeof(node));
    newnode->data = data;
    newnode->link = NULL;
    if(*head==NULL)
        *head = newnode;
    else{
        ptr = *head;
        while(ptr->link!=NULL)
            ptr = ptr->link;
        
        ptr->link = newnode;
    }    
}
void insert_nth(node **head,int data,int posn){
    node *newnode,*ptr;
    int i=1;
    newnode = (node*)malloc(sizeof(node));
    newnode->data = data;
    ptr = *head;
    if(*head == NULL || posn == 1){
        newnode->link = *head;
        *head = newnode;
    }
    else{
        while(ptr->link!=NULL && i<=posn-2){
            ptr = ptr->link;
        }
        newnode->link = ptr->link;
        ptr->link = newnode;
    }
}
void deleteBegin(node **head){
    node *temp;
    if(*head==NULL)
        puts("NULL node.Delection is not possible.\n");
    else{
        temp = *head;
        *head = temp->link;
        free(temp);
    }
}
void deleteEnd(node **head){
    node *temp;
    if(*head==NULL)
        puts("NULL node.Delection is not possible.\n");
    else{
        temp = *head;
        while(temp->link->link!=NULL)
            temp = temp->link;
        
        free(temp->link);
        temp->link = NULL;
        puts("Succesfully deleted the first node.\n");
    }
}
void delete_Any(node **head,int val){
    node *ptr,*prev;
    ptr = *head;
    if(*head==NULL)
        puts("NULL node.Delection is not possible\n");
    else{
        if(ptr->data==val){
            *head = ptr->link;
            free(ptr);
            printf("Successfullly deleted the first node.\n");
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
                puts("Value not found in the list\n");
            else{
            prev->link = ptr->link;
            free(ptr);
            printf("Successfullly deleted the last node.\n");
            }
        }         
    }
}
void displayList(node *head){
    if(head==NULL)
        printf("List is empty.\n");
    else{
        while(head!=NULL){
            printf("%d -> ",head->data);
            head = head->link;
        }
        printf("NULL\n");
    }
}
void physically_rev(node **head){
    node *prev = NULL;  
    node *cur = *head;  
    node *next = NULL;  

    while (cur != NULL) {  
        next = cur->link;  
        cur->link = prev;  
        prev = cur;        
        cur = next;        
    }
    *head = prev;         
}
int main(){
    node *head = NULL; 
    int ch,data,posn;
    printf("MAIN MENU\n");
    printf("--------------\n");
    printf("1. Insert element at the beginning\n");
    printf("2. Insert element at the ending\n");
    printf("3. Insert elememt at the certain position\n");
    printf("4. Delete element at the beginning.\n");
    printf("5. Delete element at the ending\n");
    printf("6. Delete element at the certain position\n");
    printf("7. Display the linked list\n");
    printf("8. Reverse display the linked list\n");
    printf("9. Exit\n");
    printf("--------------\n");
    while(1){
        printf("Enter the operation: ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                printf("Enter the element to insert at the beginnging: ");
                scanf("%d",&data);
                insertBegin(&head,data);
                break;
            case 2:
                printf("Enter the element to insert at the ending: ");
                scanf("%d",&data);
                insertEnd(&head,data);
                break;
            case 3:
                printf("Enter the position to insert: ");
                scanf("%d",&posn);
                printf("Enter the element to insert at %d positon: ",posn);
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
                delete_Any(&head,data);
                break;
            case 7:
                displayList(head);
                break;
            case 8:
                physically_rev(&head);
                break;
            case 9:
                printf("Exiting.\n");
                return 0;
            default:
                printf("Invalid operation. Please try again.\n");
        }
    }
    return 0;
}