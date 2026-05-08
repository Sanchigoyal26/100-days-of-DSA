#include<iostream>
#include<queue>
using namespace std;

queue<int> q1, q2;

void push(int x){
    q2.push(x);

    while(!q1.empty()){
        q2.push(q1.front());
        q1.pop();
    }

    swap(q1,q2);
}

void pop(){
    if(q1.empty()){
        cout<<"Stack Underflow\n";
        return;
    }

    cout<<"Popped: "<<q1.front()<<endl;
    q1.pop();
}

void display(){
    queue<int> temp=q1;

    while(!temp.empty()){
        cout<<temp.front()<<" ";
        temp.pop();
    }
    cout<<endl;
}

int main(){
    push(10);
    push(20);
    push(30);

    display();

    pop();

    display();
}