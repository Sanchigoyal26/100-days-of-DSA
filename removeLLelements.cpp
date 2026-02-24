#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Insert at end
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

// Remove all occurrences of val
Node* removeElements(Node* head, int val) {

    // Remove from beginning
    while (head != NULL && head->data == val) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    Node* current = head;

    while (current != NULL && current->next != NULL) {
        if (current->next->data == val) {
            Node* temp = current->next;
            current->next = current->next->next;
            delete temp;
        } else {
            current = current->next;
        }
    }

    return head;
}

// Display
void display(Node* head) {
    while (head != NULL) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

int main() {
    Node* head = NULL;
    int n, value, val;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> value;
        head = insertEnd(head, value);
    }

    cout << "Enter value to remove: ";
    cin >> val;

    head = removeElements(head, val);

    cout << "Updated List:\n";
    display(head);

    return 0;
}