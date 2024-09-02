#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define max 100

int enqueue();
int dequeue();
int peek();
void display();

int main()
{
      char name[max][80], data[80];
      int front, rear, value;
      int ch;
      front = rear = -1;
        printf("------------------------------\n");
        printf("\tMenu");
        printf("\n------------------------------");
        printf("\n [1] ENQUEUE");
        printf("\n [2] DEQUEUE");
        printf("\n [3] PEEK");
        printf("\n [4] DISPLAY");
      printf("\n------------------------------\n");
      while(1)
      {
            printf("Choice : ");
            scanf("%d", &ch);
            switch(ch)
            {
                  case 1 : // insert
                        printf("\nEnter the Name : ");
                        scanf("%s",data);
                        value = enqueue(name, &rear, data);
                        if(value == -1 )
                              printf("\n QUEUE is Full \n");
                        else
                              printf("\n'%s' is inserted in QUEUE.\n\n",data);
                        break;
                  case 2 : // delete
                        value = dequeue(name, &front, &rear, data);
                        if( value == -1 )
                              printf("\n QUEUE is Empty \n");
                        else
                              printf("\n Deleted Name from QUEUE is : %s\n", data);
                              printf("\n");
                        break;
                 case 3:
                    value = peek(name, &front, &rear, data);
                    if(value != -1)
                    {
                        printf("\n The front is: %s", value);
                    }
                        break;
                  case 5 : exit(0);
                  default: printf("Invalid Choice \n");
            }
      }
      return 0;
}

int enqueue(char name[max][80], int *rear, char data[80])
{
      if(*rear == max -1)
            return(-1);
      else
      {
            *rear = *rear + 1;
            strcpy(name[*rear], data);
            return(1);
      }
}
int dequeue(char name[max][80], int *front, int *rear, char data[80])
{
      if(*front == *rear)
            return(-1);
      else
      {
            (*front)++;
            strcpy(data, name[*front]);
            return(1);
      }
}
int peek(char name[max][80], int *front, int *rear, char data[80])
{
     if(*front == -1 || *front > *rear)
    {
        printf(" QUEUE IS EMPTY\n");
        return -1;
    }
    else
    {
        return data[*front];
    }
}
