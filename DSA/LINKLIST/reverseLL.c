#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* reverse(struct Node* head) {
    struct Node* prev = NULL;
    struct Node* curr = head;
    struct Node* next = NULL;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

struct Node* newNode(int val) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = val;
    n->next = NULL;
    return n;
}

void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = newNode(5);
    head->next = newNode(10);
    head->next->next = newNode(15);
    head->next->next->next = newNode(20);
    head->next->next->next->next = newNode(25);
    head->next->next->next->next->next = newNode(30);

    printf("Original: ");
    printList(head);

    head = reverse(head);

    printf("Reversed: ");
    printList(head);

    return 0;
}