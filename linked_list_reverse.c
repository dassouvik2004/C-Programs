#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
    int data;
    struct Node *link;
}node;
void revList(node **head){
    node *prev = NULL, *cur = *head, *next = NULL;
    while(cur!=NULL){
        next = cur->link;
        cur->link = prev;
        prev = cur;
        cur = next;
    }
    *head = prev;
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

    printf("Before reversing: \n");
    printList(head);

    revList(&head);

    printf("After reversing: \n");
    printList(head);

    return 0;
}