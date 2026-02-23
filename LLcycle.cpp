#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* createNode(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Insert at end
Node* insertEnd(Node* head, int value) {
    Node* newNode = createNode(value);
    if(head == NULL) return newNode;

    Node* temp = head;
    while(temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
    return head;
}

// Function to create cycle at given position
void createCycle(Node* head, int pos) {
    if(pos == -1) return;

    Node* tail = head;
    Node* joinNode = NULL;
    int index = 0;

    while(tail->next != NULL) {
        if(index == pos)
            joinNode = tail;
        tail = tail->next;
        index++;
    }
    tail->next = joinNode; // cycle created
}

// Cycle detection function
bool hasCycle(Node* head) {
    if(head == NULL || head->next == NULL)
        return false;

    Node* slow = head;
    Node* fast = head;

    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast)
            return true;
    }
    return false;
}

int main() {
    Node* head = NULL;
    int n, x, pos;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter values: ";
    for(int i = 0; i < n; i++) {
        cin >> x;
        head = insertEnd(head, x);
    }

    cout << "Enter position to create cycle (-1 for no cycle): ";
    cin >> pos;

    createCycle(head, pos);

    if(hasCycle(head))
        cout << "Cycle detected";
    else
        cout << "No cycle";

    return 0;
}