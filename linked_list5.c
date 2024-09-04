// Maximum data of the linked list
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *link;
} node;

void insertBegin(node **head, int data) {
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = data;
    newnode->link = *head;
    *head = newnode;
}

node* maxNode(node **head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return NULL;
    }

    node *ptr = *head;
    node *temp = ptr; 
    int max = ptr->data;

    while (ptr != NULL) {
        if (ptr->data > max) {
            max = ptr->data;
            temp = ptr;
        }
        ptr = ptr->link;
    }

    return temp;
}

void displayList(node *head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->link;
    }
    printf("NULL\n");
}

int main() {
    node *head = NULL;
    int n, i, data;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter the element %d: ", i + 1);
        scanf("%d", &data);
        insertBegin(&head, data);
    }

    printf("The list before finding the max: ");
    displayList(head);

    node *max = maxNode(&head);
    if (max != NULL)
        printf("Maximum value of the node: %d\n", max->data);

    node *temp;
    while (head != NULL) {
        temp = head;
        head = head->link;
        free(temp);
    }

    return 0;
}