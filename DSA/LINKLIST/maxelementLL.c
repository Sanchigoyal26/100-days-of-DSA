#include <stdio.h>
#include <stdlib.h>

// Step 1: Create node structure
struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;   // start of list

// Step 2: Function to insert node at end
struct node * insert(int value)
{
    struct node *newNode, *temp;
    
    // create new node
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = NULL;

    // if list empty
    if(head == NULL)
    {
        head = newNode;
        return head;
    }
    else
    {
        temp = head;
        while(temp->next != NULL)
        {
            temp = temp->next;   // move to last node
        }
        temp->next = newNode;   // attach new node
        return head;
    }
}

// Step 3: Display Linked List
void display()
{
    struct node *temp = head;

    printf("Linked List: ");
    while(temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL");
}

// Step 4: Main function
int main()
{
    int n, value, i;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for(i = 1; i <= n; i++)
    {
        printf("Enter value %d: ", i);
        scanf("%d", &value);
        insert(value);
    }

    display();

    return 0;
}