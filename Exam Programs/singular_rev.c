// Summatation of the data in the singular linked list
#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
    int data;
    struct Node *link;
}node;
void insertBeg(node **head,int data){
    node *newnode;
    newnode = (node*)malloc(sizeof(node));
    newnode->data = data;
    newnode->link = *head;
    *head = newnode;
}
void displayList(node *head){
    while(head!=NULL){
        printf("%d -> ",head->data);
        head = head->link;
    }
    printf("NULL\n");
}
int SumData(node *head){
    int sum;
    node *ptr;
    if(head==NULL)
        return -1;
    else{
        ptr = head;
        while(ptr!=NULL){
            sum += ptr->data;
            ptr = ptr->link;
        }
        return sum;
    }
}
node *maxData(node *head){
    node *ptr,*max;
    if(head==NULL)
        return NULL;
    else{
        max = head;
        ptr = head->link;
        while(ptr!=NULL){
            if(ptr->data>max->data)
                max = ptr;
            ptr = ptr->link;
        }
        return max;
    }
}
int rev_display(node **head){
    node *prev,*cur,*next;
    if(*head==NULL)
        return 0;
    else{
        prev = NULL;
        cur = *head;
        next = NULL;
        while(cur!=NULL){
            next = cur->link;
            cur->link = prev;
            prev = cur;
            cur = next;
        }
        *head = prev;
    }
}
int main(){
    node *head = NULL,*max;
    int ch,data,sum;
    printf("1. Enter element to insert at the beginning\n");
    printf("2. Summatation of the data\n");
    printf("3. Maximum data of the list\n");
    printf("4. Display the list\n");
    printf("5. Reverse display of the list\n");
    printf("6. Exit\n");
    while(1){
        printf("Enter the operation: ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d",&data);
                insertBeg(&head,data);
                break;
            case 2:
                sum = SumData(head);
                if(sum==-1)
                    puts("The list is empty.");
                else
                    printf("Summatation of the data in list: %d\n",sum);
                break;
            case 3:
                max = maxData(head);
                if (max==NULL)
                    printf("List is empty.\n");
                else
                    printf("Maximum data of the node is %d and the address id %d\n",max->data,(void*)max);
                    break;
            case 4:
                printf("The list: ");
                displayList(head);
                break;
            case 5:
                rev_display(&head);
                printf("The reverse list: ");
                displayList(head);
                break;
            case 6:
                printf("Exiting.....\n");
                return 0;
            default:
                printf("Invalid operation.Please try again.\n");
        }
    }
    return 0;
}