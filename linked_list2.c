//Insert element at the ending using linked list.
#include <stdio.h>
#include <stdlib.h>

typedef struct NODE {
    int data;
    struct NODE *link;
} node;

void insertEnd(node **head, int data) {
    node *ptr, *temp;
    temp = (node*)malloc(sizeof(node));// suppose temp points an address(4000) of a node
    temp->data = data;
    temp->link = NULL;
    if(*head==NULL)// If there is no node
        *head = temp;
    else{
        ptr = *head;// ptr = 3000(Address of first node)
        while(ptr->link!=NULL) // 3000->link(NULL) == NULL(Loop exits)
            ptr = ptr->link;
        ptr->link = temp; // 3000->link = 4000
    }
}
void displaylist(node *p) {
    while (p != NULL) { // We are traversing with the help of head 
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
        insertEnd(&head,data);
    }
    printf("Element inserted at the ending: \n");
    displaylist(head);
    return 0;
}
