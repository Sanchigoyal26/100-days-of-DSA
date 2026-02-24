#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Insert node at end
Node* insertEnd(Node* head, int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL)
        return newNode;

    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

// Delete first occurrence of key
Node* deleteKey(Node* head, int key) {
    
    // Case 1: Empty list
    if (head == NULL) {
        cout << "List is empty\n";
        return head;
    }

    Node* temp = head;
    Node* prev = NULL;

    // Case 2: Key at head
    if (temp->data == key) {
        head = temp->next;
        delete temp;
        return head;
    }

    // Case 3: Search key in rest of list
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // Case 4: Key not found
    if (temp == NULL) {
        cout << "Key not found\n";
        return head;
    }

    // Delete node
    prev->next = temp->next;
    delete temp;

    return head;
}

// Display linked list
void display(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main() {
    Node* head = NULL;
    int n, value, key;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> value;
        head = insertEnd(head, value);
    }

    cout << "Original List:\n";
    display(head);

    cout << "Enter key to delete: ";
    cin >> key;

    head = deleteKey(head, key);

    cout << "Updated List:\n";
    display(head);

    return 0;
}