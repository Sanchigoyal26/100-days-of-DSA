#include <iostream>
#include <stack>
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
        cout<<head->val<<" -> ";
        head=head->next;
    }
    cout<<"NULL\n";
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    stack<int> s1, s2;

    while(l1){ s1.push(l1->val); l1=l1->next; }
    while(l2){ s2.push(l2->val); l2=l2->next; }

    int carry = 0;
    ListNode* head = NULL;

    while(!s1.empty() || !s2.empty() || carry){
        int sum = carry;

        if(!s1.empty()){ sum += s1.top(); s1.pop(); }
        if(!s2.empty()){ sum += s2.top(); s2.pop(); }

        ListNode* node = createNode(sum % 10);
        node->next = head;
        head = node;

        carry = sum / 10;
    }
    return head;
}

int main(){
    // 7243 -> 7->2->4->3
    ListNode* l1 = createNode(7);
    l1->next = createNode(2);
    l1->next->next = createNode(4);
    l1->next->next->next = createNode(3);

    // 564 -> 5->6->4
    ListNode* l2 = createNode(5);
    l2->next = createNode(6);
    l2->next->next = createNode(4);

    ListNode* result = addTwoNumbers(l1,l2);
    printList(result);
}