#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
};

ListNode* createNode(int x){
    ListNode* n = new ListNode();
    n->val = x;
    n->next = NULL;
    return n;
}

void printList(ListNode* head){
    while(head){
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){
    ListNode* dummy = new ListNode();
    dummy->next = NULL;
    ListNode* curr = dummy;
    int carry = 0;

    while(l1 || l2 || carry){
        int sum = carry;

        if(l1){
            sum += l1->val;
            l1 = l1->next;
        }
        if(l2){
            sum += l2->val;
            l2 = l2->next;
        }

        carry = sum / 10;
        curr->next = createNode(sum % 10);
        curr = curr->next;
    }

    return dummy->next;
}

int main(){
    // 342 → 2->4->3
    ListNode* l1 = createNode(2);
    l1->next = createNode(4);
    l1->next->next = createNode(3);

    // 465 → 5->6->4
    ListNode* l2 = createNode(5);
    l2->next = createNode(6);
    l2->next->next = createNode(4);

    ListNode* result = addTwoNumbers(l1,l2);

    cout<<"Result:\n";
    printList(result);
}