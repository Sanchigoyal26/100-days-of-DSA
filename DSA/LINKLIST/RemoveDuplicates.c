#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void removeDuplicates(struct Node* head) {
    struct Node* curr = head;
    while (curr != NULL && curr->next != NULL) {
        if (curr->data == curr->next->data) {
            struct Node* dup = curr->next;
            curr->next = curr->next->next;
            free(dup);
        } else {
            curr = curr->next;
        }
    }
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
    struct Node* head = newNode(2);
    head->next = newNode(2);
    head->next->next = newNode(4);
    head->next->next->next = newNode(5);
    head->next->next->next->next = newNode(5);
    head->next->next->next->next->next = newNode(5);
    head->next->next->next->next->next->next = newNode(7);
    head->next->next->next->next->next->next->next = newNode(9);
    head->next->next->next->next->next->next->next->next = newNode(9);

    removeDuplicates(head);
    printf("After removing duplicates: ");
    printList(head);
    return 0;
}