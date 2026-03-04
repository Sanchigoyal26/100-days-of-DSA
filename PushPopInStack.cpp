#include <iostream>
using namespace std;

#define MAX 100

int stackArr[MAX];
int top = -1;

// Push operation
void push(int x) {
    if (top == MAX - 1) {
        cout << "Stack Overflow\n";
        return;
    }
    stackArr[++top] = x;
}

// Pop operation
void pop() {
    if (top == -1) {
        cout << "Stack Underflow\n";
        return;
    }
    top--;
}

// Display stack
void display() {
    if (top == -1) {
        cout << "Stack is empty";
        return;
    }

    for (int i = top; i >= 0; i--) {
        cout << stackArr[i] << " ";
    }
}

int main() {
    int n, m;

    cin >> n;  // number of elements

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        push(x);
    }

    cin >> m;  // number of pops

    for (int i = 0; i < m; i++) {
        pop();
    }

    display();

    return 0;
}