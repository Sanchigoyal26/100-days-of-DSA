#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void printReverse(struct Node* head) {
    if (!head) return;
    printReverse(head->next);
    printf("%d ", head->data);
}

int main() {
    struct Node *a = malloc(sizeof(struct Node));
    struct Node *b = malloc(sizeof(struct Node));
    struct Node *c = malloc(sizeof(struct Node));

    a->data = 10; a->next = b;
    b->data = 20; b->next = c;
    c->data = 30; c->next = NULL;

    printReverse(a);
    return 0;
}