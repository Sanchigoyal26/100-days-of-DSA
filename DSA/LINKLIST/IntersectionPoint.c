#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int getLength(struct Node* head) {
    int len = 0;
    while (head) { len++; head = head->next; }
    return len;
}

struct Node* getIntersection(struct Node* a, struct Node* b) {
    int lenA = getLength(a);
    int lenB = getLength(b);

    while (lenA > lenB) { a = a->next; lenA--; }
    while (lenB > lenA) { b = b->next; lenB--; }

    while (a != b) {
        a = a->next;
        b = b->next;
    }
    return a;
}

struct Node* newNode(int val) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = val; n->next = NULL;
    return n;
}

int main() {
    struct Node* common = newNode(16);
    common->next = newNode(20);

    struct Node* a = newNode(4);
    a->next = newNode(8);
    a->next->next = newNode(12);
    a->next->next->next = common;

    struct Node* b = newNode(3);
    b->next = newNode(6);
    b->next->next = newNode(9);
    b->next->next->next = common;

    struct Node* result = getIntersection(a, b);
    if (result)
        printf("Intersection at node: %d\n", result->data);
    else
        printf("No intersection\n");

    return 0;
}
