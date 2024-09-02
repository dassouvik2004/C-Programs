#include <stdio.h>
#include <stdlib.h>
typedef struct NODE{
    int data;
    struct NODE *link;
}node;
void insertBegin(node **head,int data){
    node *newnode;
    newnode = (node*)malloc(sizeof(node));
    newnode->data = data;
    newnode->link = *head;
    *head = newnode;
}
void insertEnd(node **head,int data){
    node *newnode,*ptr;
    newnode = (node*)malloc(sizeof(node));
    newnode->data = data;
    newnode->link = NULL;
    ptr = *head;
    if(*head==NULL){
        newnode->link = *head;
        *head = newnode;
    }
    else{
      while(ptr->link!=NULL){
        ptr = ptr->link; 
      }
      ptr->link = newnode;  
    }
}
void insert_nth(node **head,int data,int posn){
    node *newnode, *ptr;
    int i = 1;
    newnode = (node*)malloc(sizeof(node));
    newnode->data = data;
    if(*head == NULL || posn == 1){
        newnode->link = *head;
        *head = newnode;
    }
    else{
        ptr = *head;
        while(i<=posn-2 && ptr->link!=NULL){
            ptr = ptr->link;
            i++;
        }
        newnode->link = ptr->link;
        ptr->link = newnode;
    }
}
void countList(node *head){
    node *ptr;
    int count=0;
    if(head==NULL){
        printf("List is empty.\n");
    }
    else{
        ptr = head;
        while(ptr!=NULL){
            count++;
            ptr = ptr->link;
        }
        printf("Number of nodes in the list: %d\n",count);
    }
}
void maxData(node *head){
    node *ptr,*temp;
    int max;
    if(head==NULL)
        printf("List is empty.\n");
    else{
        ptr = head;
        max = ptr->data;
        ptr = ptr->link;
        while(ptr!=NULL){
            if(ptr->data>max){
                max = ptr->data;
                temp = ptr;
            }
            ptr = ptr->link;
        }
        printf("Maximum data of the list is %d and address of the maximum data is %d\n",max,temp);
    }
}
void sumData(node *head){
    int sum = 0;
    node *ptr;
    if(head==NULL)
        printf("List is empty.\n");
    else{
        ptr = head;
        while(ptr!=NULL){
            sum = sum + ptr->data;
            ptr = ptr->link;
        }
        printf("Summation of data of the list: %d\n",sum);
    }
}
int sortingList(node **head){
    node *current, *next;
    int temp;
    int flag = 0;
    current = *head;
    if(*head==NULL){
        printf("List is empty.\n");
        return 0;
    }
    else{
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
   
}
void displayList(node *head){
    if(head==NULL)
        printf("List is empty.\n");
    else{
        while(head!=NULL){
            printf("%d -> ",head->data);
            head = head->link;
        }
        printf("NULL\n");
    }
   
}
int main(){
    node *head = NULL;
    int n,ch,i,data,posn;
    printf("MAIN MENU\n");
    printf("----------------\n");
    printf("1. Insert the element at the beginning.\n");
    printf("2. Insert the element at the ending\n");
    printf("3. Insert the element at certain position\n");
    printf("4. Count the number of node\n");
    printf("5. Maximum data of the list\n");
    printf("6. Summation of all data of the list\n");
    printf("7. Display the list\n");
    printf("8. Sorting the linked list.\n");
    printf("9. Exit the list\n");
    printf("----------------\n");
    while(1){
        printf("Enter the operation: ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                printf("Enter the element at the beginning: ");
                scanf("%d",&data);
                insertBegin(&head,data);
                break;
            case 2:
                printf("Enter the element at the ending: ");
                scanf("%d",&data);
                insertEnd(&head,data);
                break;
            case 3:
                printf("Enter the position you want to insert: ");
                scanf("%d",&posn);
                printf("Enter the element at %d position: ",posn);
                scanf("%d",&data);
                insert_nth(&head,data,posn);
                break;
            case 4:
               countList(head);
               break;
            case 5:
                maxData(head);
                break;
            case 6:
                sumData(head);
                break;
            case 7:
                printf("List: ");
                displayList(head);
                break;
            case 8:
                sortingList(&head);
                printf("Sorting list: ");
                displayList(head);
                break;
            case 9:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid operation. Please try again.\n");
        }
    }
    node *temp;
    while(head!=NULL){
        temp = head;
        head = head->link;
        free(temp);
    }
    return 0;
}