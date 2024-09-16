// Reversing circular linked list using recursion method
#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
    int data;
    struct Node *link;
}node;
void rev_display(node *head){
    static int i = 0;
    static node *p;
    node *r;
    if(i==0){
        p = head;
        i++;
    }

    if(head->link!=p)
        rev_display(head->link);

    printf("%d ",head->data);
}
int main(){
    node *head = NULL;
    node *first = (node*)malloc(sizeof(node));
    node *second = (node*)malloc(sizeof(node));
    node *third= (node*)malloc(sizeof(node));

    first->data = 5;
    second->data = 10;
    third->data = 15;
    head = first;
    first->link = second;
    second->link = third;
    third->link = head;


    rev_display(head);
    return 0;
}