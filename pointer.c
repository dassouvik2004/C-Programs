#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
};

int main() {
    struct node *head = (struct node *)malloc(sizeof(struct node));  // Correct memory allocation
    
    
    head->data = 10;  // Set the data of the head node
    head->link = NULL;  // Set the link of the head node to NULL

    // Output the data to verify
    printf("%d\n",head->data);

    // Free the allocated memory
    
	struct node *current = (struct node *)malloc(sizeof(struct node)); 
	current->data = 45;  // Set the data of the head node
	current->link = NULL;  // Set the link of the head node to NULL
	head->link = current;
	printf("%d\n",current->data);

    return 0;
}
