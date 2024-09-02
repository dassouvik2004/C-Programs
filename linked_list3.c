// Insert the element at the n-th position
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
            i++
        }
        temp->link = ptr->link;
        ptr->link = temp;
    }
}
void displayList(node *head){
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
    displayList(head);
    node *temp;
    while(head!=NULL){
        temp = head;
        head = head->link;
        free(temp);
    }
    return 0;
}