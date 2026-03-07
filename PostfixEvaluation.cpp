#include <iostream>
#include <cmath>
using namespace std;

// Node for stack
struct Node {
    int data;
    Node* next;
};

// Push operation
void push(Node* &top, int val) {
    Node* newnode = new Node;
    newnode->data = val;
    newnode->next = top;
    top = newnode;
}

// Pop operation
int pop(Node* &top) {
    if(top == NULL) {
        cout << "Stack Underflow";
        return -1;
    }
    
    Node* temp = top;
    int val = temp->data;
    top = top->next;
    delete temp;
    
    return val;
}

// Evaluate postfix expression
int evaluatePostfix(string exp) {
    Node* top = NULL;

    for(int i = 0; i < exp.length(); i++) {
        char c = exp[i];

        // If operand
        if(isdigit(c)) {
            push(top, c - '0'); 
        }
        else {
            int b = pop(top);
            int a = pop(top);

            switch(c) {
                case '+': push(top, a + b); break;
                case '-': push(top, a - b); break;
                case '*': push(top, a * b); break;
                case '/': push(top, a / b); break;
                case '^': push(top, pow(a,b)); break;
            }
        }
    }

    return pop(top);
}

int main() {
    string postfix;

    cout << "Enter postfix expression: ";
    cin >> postfix;

    cout << "Result = " << evaluatePostfix(postfix);

    return 0;
}