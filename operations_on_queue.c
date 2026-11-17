#include<stdio.h>
#define MAX 4
int queue[MAX];
int front=-1, rear=-1;
void insert()
{
    int x;
    if(rear==MAX-1)
        printf("Queue Overflow\n");
    else
    {
        printf("Enter the element");
        scanf("%d",&x);
        if(front==-1)
            front=0;
        rear++;
        queue[rear]=x;
    }
}
void delete()
{
    if(front==-1||front>rear)
        printf("Queue is empty");
    else
    {
        printf("Deleted element is %d",queue[front]);
        front++;
    }
}
void display()
{
    int i;
    if(front==-1||front>rear)
        printf("Queue is empty");
    else
    {
        for(i=front;i<=rear;i++)
            printf("%d",queue[i]);
        printf("\n");
    }
}
int main()
{
    int choice;
    while(1)
    {
        printf("Select Choice from Menu:\n");
        printf("1.Insert 2.Delete 3.Display 4.Exit");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                insert();
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid Choice !");
        }
    }
    return 0;
}
