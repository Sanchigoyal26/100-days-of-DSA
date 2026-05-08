#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* reverseList(struct Node* head) {
    struct Node* prev = NULL;
    struct Node* curr = head;
    while (curr) {
        struct Node* nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }
    return prev;
}

int isPalindrome(struct Node* head) {
    if (!head || !head->next) return 1;

    struct Node* slow = head;
    struct Node* fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    struct Node* secondHalf = reverseList(slow);
    struct Node* p1 = head;
    struct Node* p2 = secondHalf;

    while (p2 != NULL) {
        if (p1->data != p2->data) return 0;
        p1 = p1->next;
        p2 = p2->next;
    }
    return 1;
}

struct Node* newNode(int val) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = val; n->next = NULL;
    return n;
}

int main() {
    struct Node* head = newNode(1);
    head->next = newNode(3);
    head->next->next = newNode(5);
    head->next->next->next = newNode(3);
    head->next->next->next->next = newNode(1);

    if (isPalindrome(head))
        printf("True\n");
    else
        printf("False\n");

    return 0;
}