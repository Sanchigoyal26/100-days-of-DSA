#include <stdio.h>
#include <ctype.h>

char stack[100];
int top = -1;

void push(char c) { stack[++top] = c; }
char pop() { return stack[top--]; }
int priority(char c) {
    if(c == '+' || c == '-') return 1;
    if(c == '*' || c == '/') return 2;
    return 0;
}

int main() {
    char exp[100], result[100];
    int k = 0;

    printf("Enter infix: ");
    scanf("%s", exp);

    for(int i = 0; exp[i]; i++) {
        if(isalnum(exp[i]))
            result[k++] = exp[i];
        else {
            while(top != -1 && priority(stack[top]) >= priority(exp[i]))
                result[k++] = pop();
            push(exp[i]);
        }
    }

    while(top != -1)
        result[k++] = pop();

    result[k] = '\0';
    printf("Postfix: %s\n", result);
}