#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int findMiddle(struct Node* head) {
    struct Node* slow = head;
    struct Node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow->data;
}

struct Node* newNode(int val) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = val; n->next = NULL;
    return n;
}

int main() {
    struct Node* head = newNode(12);
    head->next = newNode(24);
    head->next->next = newNode(36);
    head->next->next->next = newNode(48);
    head->next->next->next->next = newNode(60);
    head->next->next->next->next->next = newNode(72);
    head->next->next->next->next->next->next = newNode(84);

    printf("Middle element: %d\n", findMiddle(head));
    return 0;
}