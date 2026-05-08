#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* newNode(int val) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = val; n->next = NULL;
    return n;
}

struct Node* addTwoNumbers(struct Node* l1, struct Node* l2) {
    struct Node dummy;
    dummy.next = NULL;
    struct Node* cur = &dummy;
    int carry = 0;

    while (l1 != NULL || l2 != NULL || carry) {
        int sum = carry;
        if (l1) { sum += l1->data; l1 = l1->next; }
        if (l2) { sum += l2->data; l2 = l2->next; }
        carry = sum / 10;
        cur->next = newNode(sum % 10);
        cur = cur->next;
    }
    return dummy.next;
}

void printList(struct Node* head) {
    while (head) { printf("%d ", head->data); head = head->next; }
    printf("\n");
}

int main() {
    struct Node* l1 = newNode(9);
    l1->next = newNode(9);
    l1->next->next = newNode(9);

    struct Node* l2 = newNode(1);
    l2->next = newNode(0);
    l2->next->next = newNode(0);

    struct Node* result = addTwoNumbers(l1, l2);
    printf("Sum: ");
    printList(result);
    return 0;
}