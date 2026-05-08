#include<iostream>
using namespace std;

int queuee[100];
int front = -1;
int rear = -1;
int size;

void enqueue(int x){
    if(rear == size - 1){
        cout<<"Queue Overflow\n";
        return;
    }

    if(front == -1){
        front = 0;
    }

    rear++;
    queuee[rear] = x;
}

void dequeue(){
    if(front == -1 || front > rear){
        cout<<"Queue Underflow\n";
        return;
    }

    cout<<"Deleted element: "<<queuee[front]<<endl;
    front++;
}

void display(){
    if(front == -1 || front > rear){
        cout<<"Queue is empty\n";
        return;
    }

    for(int i = front; i <= rear; i++){
        cout<<queuee[i]<<" ";
    }
    cout<<endl;
}

int main(){
    cout<<"Enter size of queue: ";
    cin>>size;

    enqueue(10);
    enqueue(20);
    enqueue(30);

    display();

    dequeue();

    display();
}