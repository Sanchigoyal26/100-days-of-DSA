#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

// Function to create new node
Node* createNode(int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to get length of list
int getLength(Node* head) {
    int length = 0;
    while (head != NULL) {
        length++;
        head = head->next;
    }
    return length;
}

// Function to find intersection point
Node* findIntersection(Node* head1, Node* head2) {
    int len1 = getLength(head1);
    int len2 = getLength(head2);

    int diff = abs(len1 - len2);

    // Move pointer of longer list
    if (len1 > len2) {
        while (diff--)
            head1 = head1->next;
    } else {
        while (diff--)
            head2 = head2->next;
    }

    // Move both pointers together
    while (head1 != NULL && head2 != NULL) {
        if (head1 == head2)
            return head1;

        head1 = head1->next;
        head2 = head2->next;
    }

    return NULL;
}

// Function to print list
void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

int main() {
    // Creating first linked list: 10 -> 20 -> 30 -> 40 -> 50
    Node* head1 = createNode(10);
    head1->next = createNode(20);
    head1->next->next = createNode(30);
    head1->next->next->next = createNode(40);
    head1->next->next->next->next = createNode(50);

    // Creating second linked list: 15 -> 25 -> 30 -> 40 -> 50
    Node* head2 = createNode(15);
    head2->next = createNode(25);

    // Creating intersection
    head2->next->next = head1->next->next;  
    // 30 node of first list

    cout << "List 1: ";
    printList(head1);

    cout << "List 2: ";
    printList(head2);

    Node* intersection = findIntersection(head1, head2);

    if (intersection)
        cout << "Intersection at node with value: " << intersection->data << endl;
    else
        cout << "No intersection found.\n";

    return 0;
}