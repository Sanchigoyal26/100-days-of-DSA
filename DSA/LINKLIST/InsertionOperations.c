#include <stdio.h>
#include <stdlib.h>

// Define the node structure for doubly linked list
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;  // Added previous pointer
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;  // Initialize prev to NULL
    return newNode;
}

// Function to insert at the beginning
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    newNode->next = *head;
    (*head)->prev = newNode;  // Update previous head's prev pointer
    *head = newNode;
}

// Function to insert at the end
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;  // Set the prev pointer of new node
}

// Function to insert at a specific position
void insertAtPosition(struct Node** head, int data, int position) {
    if (position < 1) {
        printf("Invalid position!\n");
        return;
    }

    if (position == 1) {
        insertAtBeginning(head, data);
        return;
    }

    struct Node* newNode = createNode(data);
    struct Node* temp = *head;

    // Traverse to the position-1 node
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of range!\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
}
int main() {
    struct Node* head = NULL;

    printf("=== DOUBLY LINKED LIST DEMONSTRATION ===\n\n");

    // Adding nodes at the end
    printf("Adding nodes at the end:\n");
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    displayListForward(head);
    displayListBackward(head);

    // Adding node at the beginning
    printf("\nAdding node at the beginning (5):\n");
    insertAtBeginning(&head, 5);
    displayListForward(head);

    // Adding node at a specific position
    printf("\nAdding node at position 3 (25):\n");
    insertAtPosition(&head, 25, 3);
    displayListForward(head);

    // Display list length
    printf("\nList length: %d\n", getLength(head));

    // Search for an element
    int searchValue = 20;
    int position = search(head, searchValue);
    if (position != -1) {
        printf("Value %d found at position %d\n", searchValue, position);
    } else {
        printf("Value %d not found in the list\n", searchValue);
    }
}