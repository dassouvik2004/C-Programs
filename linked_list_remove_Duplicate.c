// Create a singular linked list and remove duplicate element from the list
#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
    int data;
    struct Node *link;
}node;
void removing_duplicate(node *head){
    node *current = head;
    node *temp, *prev;
    while(current!=NULL && current->link!=NULL){
        prev = current;
        temp = current->link;
        while(temp!=NULL){
            if(current->data==temp->data){
                prev->link = temp->link;
                free(temp);
                temp = prev->link;
            }
            else{
                prev = temp;
                temp = temp->link;
            }
        }
        current = current->link;
    }
}
void printList(node *head){
    while(head!=NULL){
        printf("%d -> ",head->data);
        head = head->link;
    }
    printf("(NULL)\n");
}
int main(){
    node *head = NULL;

    node *first = (node*)malloc(sizeof(node));
    node *second = (node*)malloc(sizeof(node));
    node *third = (node*)malloc(sizeof(node));
    node *fourth = (node*)malloc(sizeof(node));
    node *fifth = (node*)malloc(sizeof(node));

    first->data = 5;
    second->data = 10;
    third->data = 5;
    fourth->data = 15;
    fifth->data = 10;


    first->link = second;
    second->link = third;
    third->link = fourth;
    fourth->link = fifth;
    fifth->link = NULL;

    head = first;

    printf("Before removing duplicates: \n");
    printList(head);

    removing_duplicate(head);

    printf("After removing duplicates: \n");
    printList(head);

    return 0;
}