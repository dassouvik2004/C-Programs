// Find the maximum data and address of nodes in the linked list
#include <stdio.h>
#include <stdlib.h>
typedef struct NODE{
    int data;
    struct NODE *link;
}node;
void insert_nth(node **head,int data,int posn){
    node *temp, *ptr;
    int i = 1;
    temp = (node*)malloc(sizeof(node));
    temp->data = data;
    if(*head==NULL || posn == 1){
        temp->link = *head;
        *head = temp;
    }
    else{
        ptr = *head;
        while(i<=posn-2 && ptr->link!=NULL){
            ptr = ptr->link;
            i++;
        }
        temp->link = ptr->link;
        ptr->link = temp; 
    }
}
void maxNode(node *head){
    int max;
    node *ptr=NULL,*temp;
    if(head==NULL)
        printf("Linked list is empty.\n");
    else{
        ptr = head;
        max = ptr->data;
        ptr = ptr->link;
        while(ptr!=NULL){
            if(ptr->data>max){
                max = ptr->data;
                temp = ptr;
            }
            ptr = ptr->link;
        }
    }
    printf("Maximum number of nodes is %d and address of the maximum node is %d\n",max,temp);
}
void displayList(node *head){
    printf("List: ");
    while(head!=NULL){
        printf("%d -> ",head->data);
        head = head->link;
    }
    printf("NULL\n");
}
int main(){
    node *head = NULL;
    int n,posn,data,i;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("Enter the position to insert: ");
        scanf("%d",&posn);
        if(posn<1)
            printf("Invalid position. Position must be >=1.\n");
        else{
            printf("Enter the element %d at %d position: ",i+1,posn);
            scanf("%d",&data);
            insert_nth(&head,data,posn);
        }
    }
    maxNode(head);
    displayList(head);
    return 0;
}