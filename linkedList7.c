#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int data;
    struct node *link;
}node;
void insertBegin(node **head, int data){
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
void sortingList(node **head){
    node *current, *next;
    current = *head;
    int max,temp;
    while(current!=NULL){
        max = current->data;
        next = current->link;
        while(next!=NULL){
            if(current->data>next->data){
                temp = current->data;
                current->data = next->data;
                current->data = temp; 
            }
            next = next->link;
        }
        current = current->link;
    }
}
int main(){
    node *head = NULL;
    int n,i, data;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("Enter the element %d: ",i+1);
        scanf("%d",&data);
        insertBegin(&head,data);
    }
    printf("The list before sorting: ");
    displayList(head);

    sortingList(&head);

    printf("The list after After sorting: ");
    displayList(head);
    
    node *temp;
    while(head!=NULL){
        temp = head;
        head = head->link;
        free(temp);
    }
    return 0;
}