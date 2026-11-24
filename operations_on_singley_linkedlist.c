#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *next;
};
struct node *createNode(int data) {
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}
struct node *insert(struct node *head, int data) {
    struct node *newnode = createNode(data);
    struct node *temp;
    if (head == NULL)
        return newnode;
    temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newnode;
    return head;
}
void display(struct node *head) {
    struct node *temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
void sort(struct node *head) {
    struct node *i, *j;
    int temp;
    for (i = head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}
struct node *reverse(struct node *head) {
    struct node *prev = NULL;
    struct node *current = head;
    struct node *next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}
struct node *concatenate(struct node *head1,
                         struct node *head2) {
    struct node *temp;
    if (head1 == NULL)
        return head2;
    temp = head1;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = head2;
    return head1;
}
int main() {
    struct node *head1 = NULL;
    struct node *head2 = NULL;
    int n, i, value;
    printf("Enter number of nodes in first list: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Enter data: ");
        scanf("%d", &value);
        head1 = insert(head1, value);
    }
    printf("Original List: ");
    display(head1);

    sort(head1);
    printf("Sorted List: ");
    display(head1);
    head1 = reverse(head1);
    printf("Reversed List: ");
    display(head1);
    printf("\nEnter number of nodes in second list: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Enter data: ");
        scanf("%d", &value);
        head2 = insert(head2, value);
    }
    printf("Second List: ");
    display(head2);
    head1 = concatenate(head1, head2);
    printf("Concatenated List: ");
    display(head1);
    return 0;
}
