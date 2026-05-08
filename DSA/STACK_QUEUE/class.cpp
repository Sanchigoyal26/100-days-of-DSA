#include<iostream>
using namespace std;

#define SIZE 10

int stack_arr[SIZE];
int top = -1;

void display()
{
    if(top == -1)
    {
        cout<<"Stack is Empty\n\n";
        return;
    }

    cout<<"Stack (Top -> Bottom):\n";
    for(int i = top; i >= 0; i--)
        cout<<stack_arr[i]<<endl;

    cout<<endl;
}

void push(int x)
{
    if(top == SIZE-1)
    {
        cout<<"Stack Overflow\n";
        return;
    }

    stack_arr[++top] = x;

    cout<<"After push "<<x<<":\n";
    display();
}

void pop()
{
    if(top == -1)
    {
        cout<<"Stack Underflow\n";
        return;
    }

    cout<<"Popped "<<stack_arr[top]<<endl;
    top--;

    display();
}

bool checkAscending()
{
    for(int i=0;i<top;i++)
    {
        if(stack_arr[i] > stack_arr[i+1])
            return false;
    }
    return true;
}

void emptyStack()
{
    cout<<"Stack not in ascending order. Emptying stack...\n";

    while(top!=-1)
    {
        cout<<"Removing "<<stack_arr[top]<<endl;
        top--;
    }

    cout<<"\nFinal Stack:\n";
    display();
}

int main()
{
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);
    push(60);

    pop();
    pop();

    push(70);

    if(checkAscending())
        cout<<"Stack is in ascending order\n";
    else
        emptyStack();

    return 0;
}