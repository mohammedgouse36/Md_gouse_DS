#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;
void create()
{
    int n, i, data;
    struct node *newnode, *temp;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for(i = 1; i <= n; i++)
    {
        printf("Enter data: ");
        scanf("%d", &data);

        newnode = (struct node*)malloc(sizeof(struct node));

        if(newnode == NULL)
        {
            printf("Memory allocation failed\n");
            return;
        }

        newnode->data = data;
        newnode->next = NULL;

        if(head == NULL)
        {
            head = newnode;
        }
        else
        {
            temp = head;

            while(temp->next != NULL)
            {
                temp = temp->next;
            }

            temp->next = newnode;
        }
    }
}
void delete_first()
{
    struct node *temp;

    if(head == NULL)
    {
        printf("List is Empty\n");
        return;
    }

    temp = head;
    head = head->next;

    free(temp);

    printf("Node deleted successfully\n");
}
void delete_position(int pos)
{
    struct node *temp, *prev;
    int i;

    if(head == NULL || pos < 1)
    {
        printf("Invalid Position\n");
        return;
    }

    if(pos == 1)
    {
        delete_first();
        return;
    }

    temp = head;

    for(i = 1; i < pos && temp != NULL; i++)
    {
        prev = temp;
        temp = temp->next;
    }

    if(temp == NULL)
    {
        printf("Invalid Position\n");
        return;
    }

    prev->next = temp->next;

    free(temp);

    printf("Node deleted successfully\n");
}
void delete_end()
{
    struct node *temp, *prev;

    if(head == NULL)
    {
        printf("List is Empty\n");
        return;
    }

    temp = head;

    if(head->next == NULL)
    {
        head = NULL;
        free(temp);

        printf("Node deleted successfully\n");
        return;
    }

    while(temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;

    free(temp);

    printf("Node deleted successfully\n");
}
void display()
{
    struct node *temp;

    if(head == NULL)
    {
        printf("List is Empty\n");
        return;
    }

    temp = head;

    printf("Linked List: ");

    while(temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}
int main()
{
    int choice, pos;

    while(1)
    {
        printf("\n--- SINGLY LINKED LIST DELETION ---");
        printf("\n1. Create Linked List");
        printf("\n2. Delete at Beginning");
        printf("\n3. Delete at Any Position");
        printf("\n4. Delete at End");
        printf("\n5. Display");
        printf("\n6. Exit");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                create();
                break;

            case 2:
                delete_first();
                break;

            case 3:
                printf("Enter position: ");
                scanf("%d", &pos);
                delete_position(pos);
                break;

            case 4:
                delete_end();
                break;

            case 5:
                display();
                break;

            case 6:
                exit(0);

            default:
                printf("Invalid Choice\n");
        }
    }

    return 0;
}

