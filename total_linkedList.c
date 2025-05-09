// All operations of singular linked list
#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int data;
    struct node *link;
}node;
void insertBegin(node **p,int data){
    node *newnode = (node*)malloc(sizeof(node));
    newnode->data = data;
    newnode->link = *p;
    *p = newnode;
}
void insertEnd(node **head,int data){
    node *ptr,*temp;
    temp = (node*)malloc(sizeof(node));
    temp->data = data;
    temp->link = NULL;
    if(*head==NULL)
        *head = temp;
    else{
        ptr = *head;
        while(ptr->link!=NULL){
            ptr = ptr->link;
        }
        ptr->link = temp;
    }
}
void insert_nth(node **head,int data,int posn){
    node *temp, *ptr;
    int i = 1;
    temp = (node*)malloc(sizeof(node));
    temp->data = data;
    if(*head==NULL||posn==1){
        temp->link = *head;
        *head = temp;
    } 
    else{
        ptr = *head;
        while(i<=posn-2 && ptr->link!=NULL){
            ptr = ptr->link;
            i++;
        }
        temp->link = ptr->link;
        ptr->link = temp;
    }
}
int displayList(node *head){
    if(head==NULL){
        printf("List is empty.\n");
        return 0;
    }
    else{
        while(head!=NULL){
            printf("%d -> ",head->data);
            head = head->link;
        }
        printf("NULL\n");
    }
}
int countList(node *head){
    int count = 0;
    if(head==NULL){
        printf("List is empty.\n");
        return 0;
    }
    node *ptr = NULL;
    ptr = head;
    while(ptr!=NULL){
        count++;
        ptr = ptr->link;
    }
    printf("The total number of nodes is %d\n",count);
}
node* maxNode(node *head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return NULL;
    }

    node *ptr = head;
    node *maxNode = head;

    while (ptr != NULL) {
        if (ptr->data > maxNode->data)
            maxNode = ptr;
        ptr = ptr->link;
    }

    return maxNode;
}
node* minNode(node *head){
    if (head == NULL){
        printf("List is empty.\n");
        return NULL;
    }

    node *ptr = head;
    node *minNode = head;

    while (ptr != NULL) {
        if (ptr->data < minNode->data) 
            minNode = ptr;
        ptr = ptr->link;
    }

    return minNode;
}

int sumNode(node *head){
    node *ptr;
    int sum=0;
    if(head==NULL){
        printf("List is empty.\n");
        return 0;
    }
    else{
        ptr = head;
        while(ptr!=NULL){
            sum += ptr->data;
            ptr = ptr->link;
        }
        printf("Summation of all data: %d\n",sum);
    }
}

int sortingList(node **head){
    int temp;
    node *current, *next;
    current = *head;
    if(head==NULL){
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
void deleteBegin(node **head){
    node *ptr;
    if(*head==NULL)
        puts("NULL node.Deletion is not possible.\n");
    else{
        ptr = *head;
        *head = ptr->link;
        free(ptr);
        printf("Successfully deleted the first element of the node.\n");
    }
}
void deleteEnd(node **head) {
    node *ptr, *prev;
    if (*head == NULL) {
        puts("List is empty. Deletion is not possible.\n");
        return;
    }
    ptr = *head;
    if (ptr->link == NULL) {
        free(ptr);
        *head = NULL;
        printf("Successfully deleted the only element of the list.\n");
        return;
    }
    while (ptr->link->link != NULL) {
        ptr = ptr->link;
    }

    free(ptr->link); 
    ptr->link = NULL;

    printf("Successfully deleted the last element of the list.\n");
}
void deleteAny(node **head,int data){
    node *prev,*cur,*next;
    cur = *head;
    if(*head==NULL)
        puts("NULL node. Deletion is not possible.\n");
    else{
        if(cur->data==data){
            *head = cur->link;
            free(cur);
        }
        else{
            prev = cur;
            cur = cur->link;
            while(cur!=NULL){
                if(cur->data==data)
                    break;
                prev = cur;
                cur = cur->link;
            }
            if(cur==NULL)
                puts("Data is not found in the list.");
            else{
                prev->link = cur->link;
                free(cur);
            }
        }
    }
}
void delete_nth(node **head,int posn){
    node *ptr;
    if(posn<=0){
        printf("Invalid position.Please try again\n");
        return;
    }
    if(*head==NULL)
        puts("NULL node. Deletion is not possible.\n");
    else{
        ptr = *head;
        if(posn==1){
            *head = ptr->link;
            free(ptr);
            printf("Successfully deleted the %d position element.\n",posn);
        }
        else{
            int c;
            for(c = 1; c<=posn-2 && ptr->link!=NULL;c++)
                ptr = ptr->link;
            
            if(ptr->link==NULL)
                puts("Invalid position. Please try again.\n");
            else{
                node *temp;
                temp = ptr->link;
                ptr->link = temp->link;
                free(temp);
                printf("Successfully deleted the %d position element.\n",posn);
            }
        }
    }
}
void display_rev(node *head){
    node *ptr;
    if(head!=NULL){
        ptr = head;
        display_rev(head->link);
        printf("%d ",ptr->data);
    }
}
void physically_rev(node **head){
    node *prev = NULL, *cur = *head, *next = NULL;
    while(cur!=NULL){
        next = cur->link;
        cur->link = prev;
        prev = cur;
        cur = next;
    }
    *head = prev;
    printf("Reversing is completed in physically.\n");
}
int search_list(node *head,int data){
    node *ptr;
    int flag,i = 0;

    if(head==NULL)
        return -2;
    else{
        ptr = head;
        while(ptr!=NULL){
            if(ptr->data==data){
                return i;
                flag = 0;
            }
            else   
                flag = 1;
            i++;
            ptr = ptr->link;
        }
        if(flag==1)
            return -1;
    }
}
int main(){
    node *head = NULL,*max,*min;
    int ch,data,posn,posn2,search,run=1;
    while(run){
        printf("|MAIN MENU|\n");
        printf("---------------------------------------------------\n");
        printf("1. Insert element at the beginning\n");
        printf("2. Insert element at the ending\n");
        printf("3. Insert element at the n-th position\n");
        printf("4. Print the list\n");
        printf("5. Count the number of node\n");
        printf("6. Find the maximum data\n");
        printf("7. Find the minimum data\n");
        printf("8. Sum of the data in the list\n");
        printf("9. Sorting the linked list.\n");
        printf("10. Delete element at the beginning\n");
        printf("11. Delete element at the ending.\n");
        printf("12. Delete element from any position using data\n");
        printf("13. Delete element from any position using position.\n");
        printf("14. Display the list in reverse order using recursion.\n");
        printf("15. Reverse display the linked list\n");
        printf("16. Searching the data from the data\n");
        printf("17. Exit\n");
        printf("---------------------------------------------------\n");
        printf("Enter the operation: ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                printf("Enter the element to insert at the beginning: ");
                scanf("%d",&data);
                insertBegin(&head,data);
                break;
            case 2:
                printf("Enter the element to insert at the end: ");
                scanf("%d",&data);
                insertEnd(&head,data);
                break;
            case 3:
                printf("Which position you want to insert: ");
                scanf("%d",&posn);
                if(posn<1){
                    printf("Invalid position. Position must be >= 1.\n");
                    break;
                }
                printf("Enter the element to insert at %d position: ",posn);
                scanf("%d",&data);
                insert_nth(&head,data,posn);
                break;
            case 4:
                printf("List: ");
                displayList(head);
                break;
            case 5:
                countList(head);
                break;
            case 6:
                max = maxNode(head);
                printf("Maximum data is %d and its address is %d\n",max->data,max);
                break;
            case 7:
                min = minNode(head);
                printf("Minimum data is %d and its address is %d\n",min->data,min);
                break;
            case 8:
                sumNode(head);
                break;
            case 9:
                sortingList(&head);
                printf("Sorting list: ");
                displayList(head);
                break;
            case 10:
                deleteBegin(&head);
                break;
            case 11:
                deleteEnd(&head);
                break;
            case 12:
                printf("Enter the value to delete: ");
                scanf("%d",&data);
                deleteAny(&head,data);
                break;
            case 13:
                printf("Enter the position to delete: ");
                scanf("%d",&posn2);
                delete_nth(&head,posn2);
                break;
            case 14:
                display_rev(head);
                printf("\n");
                break;
            case 15:
                physically_rev(&head);
                break;
            case 16:
                printf("Enter the data to search: ");
                scanf("%d",&data);
                search = search_list(head,data);
                if(search==-2)
                    printf("List is empty\n");
                else if(search==-1)
                    printf("Element is not found.\n");
                else  
                    printf("Element is found in index no. %d\n",search);
                break;
            case 17:
                run = 0;
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid operation. Please try again..\n");
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