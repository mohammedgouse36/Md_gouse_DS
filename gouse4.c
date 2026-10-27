#include <stdio.h>
#define SIZE 3
int queue[SIZE];
int front = -1, rear = -1;
void enqueue()
{
    int item;
    if ((rear + 1) % SIZE == front)
    {
        printf("Queue is Full\n");
    }
    else
    {
        printf("Enter the element: ");
        scanf("%d", &item);
        if (front == -1)
            front = 0;
        rear = (rear + 1) % SIZE;
        queue[rear] = item;
        printf("Element inserted successfully\n");
    }
}
void dequeue()
{
    if (front == -1)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        printf("Deleted element: %d\n", queue[front]);
        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front = (front + 1) % SIZE;
        }
    }
}
void display()
{
    int i;
    if (front == -1)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        printf("Queue elements: ");;
        i = front;
        while (1)
        {
            printf("%d ", queue[i]);
            if (i == rear)
                break;
            i = (i + 1) % SIZE;
        }
        printf("\n");
    }
}
int main()
{
    int choice;
    while (1)
    {
        printf("\n1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}
