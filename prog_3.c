#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void printReverse(struct node *head) {
    if (head == NULL)
        return;
    printReverse(head->next);
    printf("%d ", head->data);
}

int main() {
    struct node *head = NULL, *temp;
    int i;

    for (i = 1; i <= 5; i++) {
        temp = (struct node *)malloc(sizeof(struct node));
        temp->data = i;
        temp->next = head;
        head = temp;
    }

    printf("Reverse Traversal: ");
    printReverse(head);
    return 0;
}
