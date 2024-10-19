#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
    int data;
    struct Node *link;
}node;
void sorting(node **head){
    int temp;
    node *current  = *head, *next;
    while(current!=NULL){
        next = current->link;
        while(next!=NULL){
            if(current->data>next->data){
                temp = current->data;
                current->data = next->data;
                next->data = temp;
            }
            next = next->link;
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

    first->data = 5;
    second->data = 10;
    third->data = 15;

    first->link = second;
    second->link = third;
    third->link = NULL;

    head = first;

    sorting(&head);

    printList(head);

    return 0;
}