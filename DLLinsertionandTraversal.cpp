#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* prev;
    Node* next;
};

// Insert at beginning
Node* insertAtBeginning(Node* head, int value)
{
    Node* newNode = new Node();
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = head;

    if(head != NULL)
        head->prev = newNode;

    head = newNode;
    return head;
}

// Insert at end
Node* insertAtEnd(Node* head, int value)
{
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;

    if(head == NULL)
    {
        newNode->prev = NULL;
        return newNode;
    }

    Node* temp = head;
    while(temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;

    return head;
}

// Forward traversal
void traverseForward(Node* head)
{
    Node* temp = head;
    cout << "Forward Traversal: ";
    while(temp != NULL)
    {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

// Backward traversal
void traverseBackward(Node* head)
{
    if(head == NULL) return;

    Node* temp = head;
    while(temp->next != NULL)   // go to last node
        temp = temp->next;

    cout << "Backward Traversal: ";
    while(temp != NULL)
    {
        cout << temp->data << " <-> ";
        temp = temp->prev;
    }
    cout << "NULL\n";
}

int main()
{
    Node* head = NULL;
    int n, value;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter elements:\n";
    for(int i = 0; i < n; i++)
    {
        cin >> value;
        head = insertAtEnd(head, value);
    }

    traverseForward(head);
    traverseBackward(head);

    cout << "\nInsert element at beginning: ";
    cin >> value;
    head = insertAtBeginning(head, value);

    cout << "After insertion:\n";
    traverseForward(head);
    traverseBackward(head);

    return 0;
}