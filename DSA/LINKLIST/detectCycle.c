#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* detectCycle(struct Node* head) {
    struct Node* slow = head;
    struct Node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            slow = head;
            while (slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }
    return NULL;
}

struct Node* newNode(int val) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = val; n->next = NULL;
    return n;
}

int main() {
    struct Node* head = newNode(8);
    head->next = newNode(14);
    struct Node* cycleStart = newNode(23);
    head->next->next = cycleStart;
    head->next->next->next = newNode(35);
    head->next->next->next->next = newNode(49);
    head->next->next->next->next->next = cycleStart;

    struct Node* result = detectCycle(head);
    if (result != NULL)
        printf("True, cycle starts at node: %d\n", result->data);
    else
        printf("False, no cycle\n");

    return 0;
}