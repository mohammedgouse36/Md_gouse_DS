#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *next;
};
struct node *top = NULL;
struct node *front = NULL;
struct node *rear = NULL;
void push(int value) {
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = top;
    top = newnode;
    printf("Element pushed: %d\n", value);
}
void pop() {
    struct node *temp;
    if (top == NULL) {
        printf("Stack Underflow\n");
        return;
    }
    temp = top;
    printf("Element popped: %d\n", top->data);
    top = top->next;
    free(temp);
}
void displayStack() {
    struct node *temp = top;
    if (top == NULL) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
void enqueue(int value) {
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = NULL;
    if (front == NULL) {
        front = rear = newnode;
    } else {
        rear->next = newnode;
        rear = newnode;
    }
    printf("Element inserted: %d\n", value);
}
void dequeue() {
    struct node *temp;
    if (front == NULL) {
        printf("Queue Underflow\n");
        return;
    }
    temp = front;
    printf("Element deleted: %d\n", front->data);
    front = front->next;
    if (front == NULL)
        rear = NULL;
    free(temp);
}
void displayQueue() {
    struct node *temp = front;
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int main() {
    int choice, value;
    while (1) {
        printf("\n1. Push");
        printf("\n2. Pop");
        printf("\n3. Display Stack");
        printf("\n4. Enqueue");
        printf("\n5. Dequeue");
        printf("\n6. Display Queue");
        printf("\n7. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                displayStack();
                break;
            case 4:
                printf("Enter value: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 5:
                dequeue();
                break;
            case 6:
                displayQueue();
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid Choice\n");
        }
    }
    return 0;
}
