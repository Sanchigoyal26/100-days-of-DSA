#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

int main() {
    int n, value;
    cin >> n;

    Node *head = NULL, *temp = NULL, *newNode = NULL;

    // Creating list
    for(int i = 0; i < n; i++) {
        cin >> value;

        newNode = new Node;     // C++ allocation
        newNode->data = value;
        newNode->next = NULL;

        // First node
        if(head == NULL) {
            head = newNode;
            temp = newNode;
        }
        else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    // Traversing list
    temp = head;
    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    return 0;
}