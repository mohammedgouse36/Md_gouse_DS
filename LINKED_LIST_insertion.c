#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

void insertFirst(int x) {
    struct node *n = malloc(sizeof(struct node));
    n->data = x;
    n->next = head;
    head = n;
}

void insertEnd(int x) {
    struct node *n = malloc(sizeof(struct node));
    struct node *t = head;

    n->data = x;
    n->next = NULL;

    if (head == NULL) {
        head = n;
        return;
    }

    while (t->next != NULL)
        t = t->next;

    t->next = n;
}

void insertPos(int x, int pos) {
    struct node *n, *t = head;
    int i;

    if (pos == 1) {
        insertFirst(x);
        return;
    }

    for (i = 1; t != NULL && i < pos - 1; i++)
        t = t->next;

    if (t == NULL) {
        printf("Invalid position\n");
        return;
    }

    n = malloc(sizeof(struct node));
    n->data = x;
    n->next = t->next;
    t->next = n;
}

void display() {
    struct node *t = head;

    while (t != NULL) {
        printf("%d -> ", t->data);
        t = t->next;
    }
    printf("NULL\n");
}

int main() {
    int ch, x, pos;

    do {
        printf("\n1.Insert First\n2.Insert Position");
        printf("\n3.Insert End\n4.Display\n5.Exit\n");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                scanf("%d", &x);
                insertFirst(x);
                break;
            case 2:
                scanf("%d%d", &x, &pos);
                insertPos(x, pos);
                break;
            case 3:
                scanf("%d", &x);
                insertEnd(x);
                break;
            case 4:
                display();
                break;
        }
    } while (ch != 5);

    return 0;
}

