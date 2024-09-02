//Insert element at the beginning using linked list.
#include <stdio.h>
#include <stdlib.h>

typedef struct NODE {
    int data;
    struct NODE *link;
} node;

void insertBegin(node **p, int data) {
    node *newnode = (node*)malloc(sizeof(node));
    newnode->data = data;
    newnode->link = *p;
    *p = newnode;
}
void displaylist(node *p) {
    while (p != NULL) {
        printf("%d -> ", p->data);
        p = p->link;
    }
    printf("NULL\n");
}

int main() {
    node *head = NULL;
    int i, n, data;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &data);
        insertBegin(&head, data);
    }
    printf("Element inserted at the beginning process: \n");
    displaylist(head);
    return 0;
}
