#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

// Function to insert a node at the end of the circular linked list
void insert_end(Node **p, int n) {
    Node *q, *r = *p;
    q = (Node *)malloc(sizeof(Node));
    q->data = n;
    if (*p == NULL) {
        // List is empty, so new node points to itself
        q->next = q;
        *p = q;
    } else {
        q->next = *p;
        // Traverse to the last node
        while (r->next != *p)
            r = r->next;
        r->next = q;
    }
}

// Function to reverse display the list
void rev_display(Node **p) {
    if (p == NULL) return; // Handle empty list
    Node *prev = NULL;
    Node *cur = *p;
    Node *next = NULL;
    do{
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }while(cur!=*p);

    *p = prev;
}

// Function to display the list
void display(Node *p) {
    if (p == NULL) {
        printf("The list is empty\n");
        return;
    }
    else{
        Node *q = p;
        do {
            printf("%d -> ", q->data);
            q = q->next;
        } while (q!= p);
        
        printf("(head)");
    }
}

int main() {
    Node *head = NULL;
    int n, i, num;
    printf("Enter the number of elements: \n");
    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        printf("Enter element %d: \n", i);
        scanf("%d", &num);
        insert_end(&head, num);
    }
    printf("The list you created is: \n");
    display(head);
    printf("\nReverse display: \n");
    rev_display(&head);
    display(head);
    return 0;
}