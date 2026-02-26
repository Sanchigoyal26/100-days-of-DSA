#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Function to detect cycle and return starting node
Node* detectCycle(Node* head) {
    if(head == NULL || head->next == NULL)
        return NULL;

    Node* slow = head;
    Node* fast = head;

    // Detect cycle
    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast) {
            slow = head;
            while(slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }

    return NULL;
}

int main() {
    // Creating nodes dynamically
    Node* head = new Node{3, NULL};
    Node* second = new Node{2, NULL};
    Node* third = new Node{0, NULL};
    Node* fourth = new Node{-4, NULL};

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = second;  // Creating cycle at node with value 2

    Node* result = detectCycle(head);

    if(result)
        cout << "Cycle starts at node with value: " << result->data;
    else
        cout << "No cycle found";

    return 0;
}