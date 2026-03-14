#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Queue {
    Node* front;
    Node* rear;

public:
    Queue() {
        front = rear = NULL;
    }

    void enqueue(int x) {
        Node* temp = new Node();
        temp->data = x;
        temp->next = NULL;

        if (rear == NULL) {
            front = rear = temp;
            return;
        }

        rear->next = temp;
        rear = temp;
    }

    int dequeue() {
        if (front == NULL)
            return -1;

        Node* temp = front;
        int val = temp->data;

        front = front->next;

        if (front == NULL)
            rear = NULL;

        delete temp;
        return val;
    }
};

int main() {
    int N;
    cin >> N;

    Queue q;

    for(int i = 0; i < N; i++) {
        string op;
        cin >> op;

        if(op == "enqueue") {
            int x;
            cin >> x;
            q.enqueue(x);
        }
        else if(op == "dequeue") {
            cout << q.dequeue() << endl;
        }
    }

    return 0;
}