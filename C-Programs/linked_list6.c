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
int sumData(node *head){
    node *ptr=NULL;
    int sum = 0;
    if(head==NULL){
        printf("List is empty");
        return 0;
    }
    else{
        ptr = head;
        while(ptr!=NULL){
            sum += ptr->data;
            ptr = ptr->link;
        }
        printf("Summation of the data in nodes: %d\n",sum);
    }
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
    sumData(head);
    displayList(head);
    node *temp;
    while(head!=NULL){
        temp = head;
        head = head->link;
        free(temp);
    }
    return 0;
} 