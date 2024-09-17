// Count of the nodes in the singular linked list
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
int countData(node *head){
    int count;
    node *ptr;
    if(head==NULL)
        return -1;
    else{
        ptr = head;
        while(ptr!=NULL){
            count++;
            ptr = ptr->link;
        }
        return count;
    }
}
int main(){
    node *head = NULL;
    int ch,data,count;
    printf("1. Enter element to insert at the beginning\n");
    printf("2. count of the data\n");
    printf("2. Display the list\n");
    printf("3. Exit\n");
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
                count = countData(head);
                if(count==-1)
                    puts("The list is empty.");
                else
                    printf("The number of the node: %d\n",count);
                break;
            case 3:
                printf("The list: ");
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