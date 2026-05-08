#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* rotateRight(struct Node* head, int k) {
    if (!head || !head->next || k == 0) return head;

    int len = 1;
    struct Node* tail = head;
    while (tail->next) { tail = tail->next; len++; }

    k = k % len;
    if (k == 0) return head;

    tail->next = head;

    int stepsToNewTail = len - k - 1;
    struct Node* newTail = head;
    for (int i = 0; i < stepsToNewTail; i++)
        newTail = newTail->next;

    struct Node* newHead = newTail->next;
    newTail->next = NULL;
    return newHead;
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
    struct Node* head = newNode(10);
    head->next = newNode(20);
    head->next->next = newNode(30);
    head->next->next->next = newNode(40);
    head->next->next->next->next = newNode(50);
    head->next->next->next->next->next = newNode(60);

    head = rotateRight(head, 4);
    printf("After rotation: ");
    printList(head);
    return 0;
}