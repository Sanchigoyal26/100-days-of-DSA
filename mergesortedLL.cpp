#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

// Function to create a new node (dynamic allocation)
Node* createNode(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Insert node at end of list
Node* insertEnd(Node* head, int value) {
    Node* newNode = createNode(value);

    if (head == NULL)
        return newNode;

    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

// Print linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Merge two sorted linked lists
Node* mergeLists(Node* l1, Node* l2) {
    // Dummy node
    Node* dummy = createNode(-1);
    Node* tail = dummy;

    while (l1 != NULL && l2 != NULL) {
        if (l1->data <= l2->data) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }

    // Attach remaining nodes
    if (l1 != NULL)
        tail->next = l1;
    else
        tail->next = l2;

    return dummy->next;
}

// MAIN FUNCTION
int main() {
    Node* list1 = NULL;
    Node* list2 = NULL;

    int n, m, x;

    cout << "Enter size of first sorted list: ";
    cin >> n;
    cout << "Enter elements (sorted): ";
    for (int i = 0; i < n; i++) {
        cin >> x;
        list1 = insertEnd(list1, x);
    }

    cout << "Enter size of second sorted list: ";
    cin >> m;
    cout << "Enter elements (sorted): ";
    for (int i = 0; i < m; i++) {
        cin >> x;
        list2 = insertEnd(list2, x);
    }

    cout << "\nList 1: ";
    printList(list1);

    cout << "List 2: ";
    printList(list2);

    Node* merged = mergeLists(list1, list2);

    cout << "Merged Sorted List: ";
    printList(merged);

    return 0;
}