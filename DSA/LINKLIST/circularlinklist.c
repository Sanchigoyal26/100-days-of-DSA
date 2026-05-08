#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

/* Insert at end (CIRCULAR) */
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);

    if (*head == NULL) {
        *head = newNode;
        newNode->next = *head;   // circular link
        return;
    }

    struct Node* temp = *head;
    while (temp->next != *head) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = *head;   // last points to head
}

/* Insert at beginning (CIRCULAR) */
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);

    if (*head == NULL) {
        *head = newNode;
        newNode->next = *head;
        return;
    }

    struct Node* temp = *head;
    while (temp->next != *head) {
        temp = temp->next;
    }

    newNode->next = *head;
    temp->next = newNode;
    *head = newNode;
}

/* Display circular list */
void displayList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = head;
    printf("Circular Linked List: ");

    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("(back to head)\n");
}

int main() {
    struct Node* head = NULL;

    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);

    displayList(head);

    insertAtBeginning(&head, 5);
    displayList(head);

    return 0;
}