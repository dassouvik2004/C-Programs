// Summatation of the data in the singular linked list
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
int SumData(node *head){
    int sum;
    node *ptr;
    if(head==NULL)
        return -1;
    else{
        ptr = head;
        while(ptr!=NULL){
            sum += ptr->data;
            ptr = ptr->link;
        }
        return sum;
    }
}
int main(){
    node *head = NULL;
    int ch,data,sum;
    printf("1. Enter element to insert at the beginning\n");
    printf("2. Summatation of the data\n");
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
                sum = SumData(head);
                if(sum==-1)
                    puts("The list is empty.");
                else
                    printf("Summatation of the data in list: %d\n",sum);
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