#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* front = NULL;
Node* rear = NULL;

// Enqueue operation
void enqueue(int x) {
    Node* temp = new Node();
    temp->data = x;

    if (front == NULL) {
        front = rear = temp;
        rear->next = front;   // circular link
    } 
    else {
        rear->next = temp;
        rear = temp;
        rear->next = front;   // maintain circular link
    }
}

// Dequeue operation
void dequeue() {
    if (front == NULL) {
        return;
    }

    if (front == rear) {
        delete front;
        front = rear = NULL;
    } 
    else {
        Node* temp = front;
        front = front->next;
        rear->next = front;
        delete temp;
    }
}

// Display queue
void display() {
    if (front == NULL) return;

    Node* temp = front;

    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != front);
}

int main() {
    int n, m, x;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x;
        enqueue(x);
    }

    cin >> m;

    for (int i = 0; i < m; i++) {
        dequeue();
    }

    display();

    return 0;
}