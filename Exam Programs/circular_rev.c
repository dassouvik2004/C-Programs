// Maximum data and the address of the node in the circular linked list
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
node* Max_Data(node *head){
    if (head == NULL)
        return NULL;

    node *max = head;
    node *ptr = head->link;

    while (ptr != head) {
        if (ptr->data > max->data) {
            max = ptr;
        }
        ptr = ptr->link;
    }

    return max;
}
int rev_display(node **head){
    if(*head==NULL){
        return 0;
    }
    node *prev = NULL;
    node *cur = *head;
    node *next = NULL;
    node *last = *head;
    do{
        next = cur->link;
        cur->link = prev;
        prev = cur;
        cur = next;
    }while(cur!=*head);

    last->link = prev;

    *head = prev;
}
void displayList(node *head){
    node *ptr = head;
    do{
        printf("%d -> ",ptr->data);
        ptr = ptr->link;
    }while(ptr!=head);

    printf("NULL\n");
}
int main(){
    node *head = NULL;
    int ch,data;
    node *max;
    printf("1. Enter element to insert at the beginning\n");
    printf("2. Maximum data of the nodes\n");
    printf("3. Display the list\n");
    printf("4. Reverse the list\n");
    printf("5. Exit\n");
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
                max = Max_Data(head);
                if (max != NULL)
                    printf("The maximum data is %d and address is : %p\n", max->data, (void*)max);
                else
                    printf("The list is empty.\n");
                break;
            case 3:
                rev_display(&head);
                displayList(head);
                break;
            case 4:
                printf("The list: ");
                displayList(head);
                break;
            case 5:
                printf("Exiting.....\n");
                return 0;
            default:
                printf("Invalid operation.Please try again.\n");
        }
    }
    return 0;
}