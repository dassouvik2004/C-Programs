#include <stdio.h>
#include <stdlib.h>

#define MAX 6

typedef struct {
    int list[MAX];
    int rear, front;
} Queue;

Queue q;

void initializeQueue() {
    q.front = -1;
    q.rear = -1;
}

void insert() {
    int num;
    printf("Enter the number to be inserted in the queue: ");
    scanf("%d", &num);
    
    if (q.rear == MAX - 1) {
        printf("\nQueue Overflow\n");
    } else {
        if (q.front == -1) // Queue is initially empty
            q.front = 0;
        q.list[++q.rear] = num;
    }
}

int delete_element() {
    if (q.front == -1) {
        printf("\nQueue Underflow\n");
        return -1;
    } else {
        int val = q.list[q.front];
        if (q.front >= q.rear) { // Queue has become empty
            q.front = q.rear = -1;
        } else {
            q.front++;
        }
        return val;
    }
}

int isempty() {
    return q.front == -1;
}

int peek() {
    if (isempty()) {
        printf("\nQueue is empty.\n");
        return -1;
    } else {
        return q.list[q.front];
    }
}

void display() {
	int i;
    if (isempty()) {
        printf("\nQueue is empty.\n");
    } else {
        printf("\nQueue elements are:\n");
        for (i = q.front; i <= q.rear; i++) {
            printf("\t%d", q.list[i]);
        }
        printf("\n");
    }
}

int main() {
    int option, val;
    initializeQueue();
    
    while (1) {
        printf("MAIN MENU\n1. Insert\n2. Delete\n3. Is Empty\n4. Peek\n5. Display\n6. Exit\n");
        scanf("%d", &option);
        
        switch (option) {
            case 1:
                insert();
                break;
            case 2:
                val = delete_element();
                if (val != -1) {
                    printf("\nThe number deleted is: %d\n", val);
                }
                break;
            case 3:
                if (isempty()) {
                    printf("\nQueue is empty.\n");
                } else {
                    printf("\nQueue is not empty.\n");
                }
                break;
            case 4:
                val = peek();
                if (val != -1) {
                    printf("\nFront element is: %d\n", val);
                }
                break;
            case 5:
                display();
                break;
            case 6:
                return 0;
            default:
                printf("INVALID OPTION! Please choose a correct option.\n");
                break;
        }
    }
	return 0;
}
