#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

// Insert node at end in Circular Linked List
void insertEnd(Node*& head, int data) {
    Node* newNode = new Node;
    newNode->data = data;

    // If list is empty
    if (head == NULL) {
        head = newNode;
        newNode->next = head; // circular link
        return;
    }

    // Find last node
    Node* temp = head;
    while (temp->next != head)
        temp = temp->next;

    temp->next = newNode;
    newNode->next = head; // maintain circular link
}

// Traversal of circular linked list
void traverse(Node* head) {
    if (head == NULL) {
        cout << "List is empty";
        return;
    }

    Node* temp = head;
    do {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != head);

    cout << "(Back to Head)\n";
}

int main() {
    Node* head = NULL;

    // Creating Circular Linked List
    insertEnd(head, 10);
    insertEnd(head, 20);
    insertEnd(head, 30);
    insertEnd(head, 40);
    insertEnd(head, 50);

    cout << "Circular Linked List:\n";
    traverse(head);

    return 0;
}