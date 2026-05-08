#include<iostream>
using namespace std;

void push(int stack[], int &top, int size) {
    int val;

    if(top == size - 1) {
        cout << "Stack Overflow\n";
        return;
    }

    cout << "Enter value to push: ";
    cin >> val;

    top++;
    stack[top] = val;
}

void pop(int stack[], int &top) {

    if(top == -1) {
        cout << "Stack Underflow\n";
        return;
    }

    cout << "Popped element: " << stack[top] << endl;
    top--;
}

void display(int stack[], int top) {

    if(top == -1) {
        cout << "Stack is empty\n";
        return;
    }

    cout << "Stack elements:\n";
    for(int i = top; i >= 0; i--) {
        cout << stack[i] << " ";
    }
    cout << endl;
}

int main() {

    int size;
    cout << "Enter stack size: ";
    cin >> size;

    int stack[size];
    int top = -1;

    int n;

    cout << "How many elements to push: ";
    cin >> n;

    for(int i = 0; i < n; i++) {
        push(stack, top, size);
    }

    display(stack, top);

    cout << "How many elements to pop: ";
    cin >> n;

    for(int i = 0; i < n; i++) {
        pop(stack, top);
    }

    display(stack, top);

}