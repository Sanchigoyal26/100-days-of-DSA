#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* front = NULL;
Node* rear = NULL;

// Enqueue operation
void enqueue(int val) {
    Node* newnode = new Node;
    newnode->data = val;
    newnode->next = NULL;

    if(front == NULL && rear == NULL) {
        front = rear = newnode;
    }
    else {
        rear->next = newnode;
        rear = newnode;
    }
}

// Display queue
void display() {
    Node* temp = front;

    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main() {
    int n, x;

    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> x;
        enqueue(x);
    }

    display();

    return 0;
}