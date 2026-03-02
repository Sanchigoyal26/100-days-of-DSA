#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
};

ListNode* createNode(int x){
    ListNode* n = new ListNode();
    n->val = x;
    n->next = NULL;
    return n;
}

ListNode* reverse(ListNode* head) {
    ListNode* prev = NULL;
    while(head) {
        ListNode* nextNode = head->next;
        head->next = prev;
        prev = head;
        head = nextNode;
    }
    return prev;
}

bool isPalindrome(ListNode* head) {
    if(!head || !head->next) return true;

    ListNode *slow=head, *fast=head;
    while(fast && fast->next){
        slow=slow->next;
        fast=fast->next->next;
    }

    slow = reverse(slow);

    ListNode* first=head;
    ListNode* second=slow;

    while(second){
        if(first->val != second->val)
            return false;
        first=first->next;
        second=second->next;
    }
    return true;
}

int main(){
    // 1->2->3->2->1
    ListNode* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(2);
    head->next->next->next->next = createNode(1);

    if(isPalindrome(head))
        cout<<"True";
    else
        cout<<"False";
}