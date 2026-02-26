#include <iostream>
using namespace std;

class MyLinkedList {
    struct Node {
        int val;
        Node* prev;
        Node* next;
        Node(int v){ val=v; prev=next=NULL; }
    };
    
    Node* head;
    Node* tail;
    int size;

public:
    MyLinkedList(){ head=tail=NULL; size=0; }

    void display() {
        Node* temp=head;
        while(temp){
            cout<<temp->val<<" <-> ";
            temp=temp->next;
        }
        cout<<"NULL\n";
    }

    int get(int index) {
        if(index<0 || index>=size) return -1;
        Node* temp=head;
        for(int i=0;i<index;i++) temp=temp->next;
        return temp->val;
    }

    void addAtHead(int val) {
        Node* n=new Node(val);
        if(size==0) head=tail=n;
        else { n->next=head; head->prev=n; head=n; }
        size++;
    }

    void addAtTail(int val) {
        Node* n=new Node(val);
        if(size==0) head=tail=n;
        else { tail->next=n; n->prev=tail; tail=n; }
        size++;
    }

    void addAtIndex(int index,int val) {
        if(index<0 || index>size) return;
        if(index==0){ addAtHead(val); return; }
        if(index==size){ addAtTail(val); return; }

        Node* temp=head;
        for(int i=0;i<index-1;i++) temp=temp->next;

        Node* n=new Node(val);
        n->next=temp->next;
        n->prev=temp;
        temp->next->prev=n;
        temp->next=n;
        size++;
    }

    void deleteAtIndex(int index) {
        if(index<0 || index>=size) return;

        if(index==0){
            Node* t=head;
            head=head->next;
            if(head) head->prev=NULL;
            else tail=NULL;
            delete t;
        }
        else if(index==size-1){
            Node* t=tail;
            tail=tail->prev;
            tail->next=NULL;
            delete t;
        }
        else{
            Node* temp=head;
            for(int i=0;i<index;i++) temp=temp->next;
            temp->prev->next=temp->next;
            temp->next->prev=temp->prev;
            delete temp;
        }
        size--;
    }
};

int main(){
    MyLinkedList list;
    int choice,val,index;

    while(true){
        cout<<"\n1.Add Head 2.Add Tail 3.Add Index 4.Delete Index 5.Get 6.Display 0.Exit\n";
        cin>>choice;
        if(choice==0) break;

        switch(choice){
            case 1: cin>>val; list.addAtHead(val); break;
            case 2: cin>>val; list.addAtTail(val); break;
            case 3: cin>>index>>val; list.addAtIndex(index,val); break;
            case 4: cin>>index; list.deleteAtIndex(index); break;
            case 5: cin>>index; cout<<list.get(index)<<endl; break;
            case 6: list.display(); break;
        }
    }
}