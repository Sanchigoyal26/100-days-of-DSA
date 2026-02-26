#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

// Insert node at end
Node* insert(Node* head, int value)
{
    Node* newNode = new Node();  // dynamic memory allocation
    newNode->data = value;
    newNode->next = NULL;

    if(head == NULL)
        return newNode;

    Node* temp = head;
    while(temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

// Count occurrences of key
int countOccurrences(Node* head, int key)
{
    int count = 0;
    Node* temp = head;

    while(temp != NULL)
    {
        if(temp->data == key)
            count++;
        temp = temp->next;
    }
    return count;
}

// Display list
void display(Node* head)
{
    Node* temp = head;
    while(temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL";
}

int main()
{
    Node* head = NULL;
    int n, value, key;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter elements:\n";
    for(int i = 0; i < n; i++)
    {
        cin >> value;
        head = insert(head, value);
    }

    cout << "Linked List: ";
    display(head);

    cout << "\nEnter element to count: ";
    cin >> key;

    int result = countOccurrences(head, key);
    cout << "Occurrences of " << key << " = " << result;

    return 0;
}