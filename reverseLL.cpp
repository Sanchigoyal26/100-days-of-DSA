#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Reverse function
Node* reverseList(Node* head) {
    Node* prev = NULL;
    Node* curr = head;
    Node* nextNode = NULL;

    while (curr != NULL) {
        nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    return prev;
}

// Print list
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main() {
    int n, x;
    cin >> n;

    Node *head = NULL, *temp = NULL, *newNode = NULL;

    // create list
    for(int i = 0; i < n; i++) {
        cin >> x;
        newNode = new Node;
        newNode->data = x;
        newNode->next = NULL;

        if(head == NULL) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    // reverse list
    head = reverseList(head);

    // print reversed list
    printList(head);

    return 0;
}