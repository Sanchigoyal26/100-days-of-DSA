#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* createNode(int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

bool removeLoop(Node* head) 
{
    if(head == NULL || head->next == NULL)
        return false;

    Node *slow = head, *fast = head;

    while(fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast)
        {
            slow = head;
            while(slow != fast)
            {
                slow = slow->next;
                fast = fast->next;
            }

            Node* temp = fast;
            while(temp->next != slow)
                temp = temp->next;

            temp->next = NULL;
            return true;
        }
    }
    return false;
}

void printList(Node* head)
{
    while(head)
    {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

int main()
{
    // Create list: 1->2->3->4->5
    Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    // Create cycle: 5 -> points to node 3
    head->next->next->next->next->next = head->next->next;

    bool removed = removeLoop(head);

    if(removed)
        cout << "true\n";
    else
        cout << "false\n";

    // Print list after removing loop
    printList(head);
}