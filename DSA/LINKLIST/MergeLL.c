#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* mergeSorted(struct Node* l1, struct Node* l2) {
    struct Node dummy;
    dummy.next = NULL;
    struct Node* cur = &dummy;

    while (l1 != NULL && l2 != NULL) {
        if (l1->data <= l2->data) {
            cur->next = l1;
            l1 = l1->next;
        } else {
            cur->next = l2;
            l2 = l2->next;
        }
        cur = cur->next;
    }
    cur->next = (l1 != NULL) ? l1 : l2;
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
    struct Node* l1 = newNode(1);
    l1->next = newNode(5);
    l1->next->next = newNode(9);
    l1->next->next->next = newNode(13);

    struct Node* l2 = newNode(2);
    l2->next = newNode(4);
    l2->next->next = newNode(8);
    l2->next->next->next = newNode(16);
    l2->next->next->next->next = newNode(20);

    struct Node* merged = mergeSorted(l1, l2);
    printf("Merged: ");
    printList(merged);
    return 0;
}