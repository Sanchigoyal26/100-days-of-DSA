#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* createNode(int data){
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Insert at end
void insertEnd(Node*& head, int data){
    Node* newNode = createNode(data);
    if(!head){
        head = newNode;
        return;
    }
    Node* temp = head;
    while(temp->next)
        temp = temp->next;
    temp->next = newNode;
}

// Print list
void printList(Node* head){
    while(head){
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

// Rotate right by k
Node* rotateRight(Node* head, int k){
    if(!head || !head->next || k==0)
        return head;

    // STEP 1: Find length and last node
    Node* temp = head;
    int len = 1;
    while(temp->next){
        temp = temp->next;
        len++;
    }

    // STEP 2: Make circular
    temp->next = head;

    // STEP 3: Find new tail
    k = k % len;
    int stepsToNewTail = len - k - 1;

    Node* newTail = head;
    for(int i=0; i<stepsToNewTail; i++)
        newTail = newTail->next;

    // STEP 4: Break circle
    Node* newHead = newTail->next;
    newTail->next = NULL;

    return newHead;
}

int main(){
    Node* head = NULL;

    insertEnd(head,1);
    insertEnd(head,2);
    insertEnd(head,3);
    insertEnd(head,4);
    insertEnd(head,5);

    cout<<"Original List:\n";
    printList(head);

    head = rotateRight(head,2);

    cout<<"After Rotation:\n";
    printList(head);
}