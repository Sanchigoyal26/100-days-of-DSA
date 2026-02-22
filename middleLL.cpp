#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
};

// Function to find middle node
ListNode* middleNode(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

int main() {
    int n, x;
    cin >> n;

    // create linked list
    ListNode *head = NULL, *temp = NULL, *newNode = NULL;

    for(int i = 0; i < n; i++) {
        cin >> x;
        newNode = new ListNode;
        newNode->val = x;
        newNode->next = NULL;

        if(head == NULL) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    // find middle
    ListNode* mid = middleNode(head);

    // print middle node value
    cout << mid->val;

    return 0;
}