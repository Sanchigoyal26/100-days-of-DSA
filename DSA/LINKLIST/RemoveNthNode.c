#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* removeNthFromEnd(struct Node* head, int n) {
    struct Node dummy;
    dummy.next = head;
    struct Node* left  = &dummy;
    struct Node* right = &dummy;

    for (int i = 0; i <= n; i++)
        right = right->next;

    while (right != NULL) {
        left  = left->next;
        right = right->next;
    }

    struct Node* del = left->next;
    left->next = left->next->next;
    free(del);

    return dummy.next;
}

struct Node* newNode(int val) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = val; n->next = NULL;
    return n;
}

void printList(struct Node* head) {
    while (head) { printf("%d ", head->data); head = head->next; }
    printf("\n");
}

int main() {
    struct Node* head = newNode(3);
    head->next = newNode(7);
    head->next->next = newNode(11);
    head->next->next->next = newNode(15);
    head->next->next->next->next = newNode(19);
    head->next->next->next->next->next = newNode(23);

    head = removeNthFromEnd(head, 2);
    printf("Result: ");
    printList(head);
    return 0;
}