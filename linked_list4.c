// Count the number of nodes
#include <stdio.h>
#include <stdlib.h>
typedef struct NODE{
    int data;
    struct NODE *link;
}node;
void insert_nth(node **head,int data,int posn){
    node *temp,*ptr;
    int i=1;
    temp = (node*)malloc(sizeof(node));
    temp->data = data;
    ptr = *head;
    if(*head==NULL || posn == 1){
        temp->link = *head;
        *head = temp;
    }
    else{
        while(i<=posn-2 && ptr->link!=NULL){ 
            ptr = ptr->link; 
            i++; // i = 2
        }
        temp->link = ptr->link;
        ptr->link = temp;
    }
}
void countNode(node *head){
    node *ptr=NULL;
    int count=0;
    if(head==NULL)
        printf("Linked list is empty.\n");
    else{
        ptr = head;
        while(ptr!=NULL){
            count++;
            ptr = ptr->link;
        }
        printf("Total number of nodes: %d\n",count);
    }
}
void displayList(node *head){
    printf("List = ");
    while(head!=NULL){
        printf("%d -> ",head->data);
        head = head->link;
    }
    printf("NULL\n");
}
int main(){
    node *head = NULL;
    int i,posn,data,n;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("Enter the position to insert: ");
        scanf("%d",&posn);
        if(posn<1){
            printf("Invalid position. Position must be >=1");
            return 0;
        }
        printf("Enter the element of %d position: ",posn);
        scanf("%d",&data);
        insert_nth(&head,data,posn);
    }
    countNode(head);
    displayList(head);
    node *temp;
    while(head!=NULL){
        temp = head;
        head = head->link;
        free(temp);
    }
    return 0;
}