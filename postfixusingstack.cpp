#include <iostream>
#include <stack>
using namespace std;

// function to check precedence
int precedence(char op){
    if(op == '+' || op == '-') return 1;
    if(op == '*' || op == '/') return 2;
    if(op == '^') return 3;
    return 0;
}

// function to check operand
bool isOperand(char c){
    if((c >= 'a' && c <= 'z') || 
       (c >= 'A' && c <= 'Z') || 
       (c >= '0' && c <= '9'))
        return true;
    return false;
}

int main(){
    string infix, postfix = "";
    stack<char> st;

    cout << "Enter infix expression: ";
    cin >> infix;

    for(int i = 0; i < infix.length(); i++){
        char c = infix[i];

        // if operand
        if(isOperand(c)){
            postfix += c;
        }

        // if '('
        else if(c == '('){
            st.push(c);
        }

        // if ')'
        else if(c == ')'){
            while(!st.empty() && st.top() != '('){
                postfix += st.top();
                st.pop();
            }
            st.pop(); // remove '('
        }

        // if operator
        else{
            while(!st.empty() && precedence(st.top()) >= precedence(c)){
                postfix += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    // pop remaining operators
    while(!st.empty()){
        postfix += st.top();
        st.pop();
    }

    cout << "Postfix expression: " << postfix;

    return 0;
}