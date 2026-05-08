#include<stdio.h>
#include<stdlib.h>
//structure of generalised ll
struct Node {
    int tag;
    union{
        char data;
        struct Node * down;
    };
    struct Node *next;
};
//function for data node
struct Node * createDataNode(int value){
    struct Node *newnode= malloc(sizeof(struct Node));
    newnode->tag=0;
    newnode->data= value;
    newnode->next= NULL;
    return newnode;
};
// Function to create a sublist node
struct Node* createSublistNode(struct Node *sublistHead) {
    struct Node* newnode = malloc(sizeof(struct Node));
    newnode->tag = 1;
    newnode->down = sublistHead;
    newnode->next = NULL;
    return newnode;
}
// Function to traverse GLL
void traverse(struct Node *head) {
    while (head != NULL) {
        if (head->tag == 0) {
            printf("%c ", head->data);
        } else {
            printf("( ");
            traverse(head->down);   // Recursive call
            printf(") ");
        }
        head = head->next;
    }
}

int main() {

    // Creating sublist (C → D)
   struct Node *C = createDataNode('C');
    struct Node *D = createDataNode('D');
    C->next = D;

    // Creating main list: A → B → (C,D) → E
   struct Node *A = createDataNode('A');
   struct Node *B = createDataNode('B');
   struct Node *sub = createSublistNode(C);
   struct Node *E = createDataNode('E');

    A->next = B;
    B->next = sub;
    sub->next = E;

    printf("Generalized Linked List Traversal:\n");
    traverse(A);

    return 0;
}
