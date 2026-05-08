#include <stdio.h>
#include <stdlib.h>

// Define structure
struct node {
    int data;
    struct node* next;
};

int main() {
    int n, i, value;

    scanf("%d", &n);

    struct node *head = NULL, *temp = NULL, *newnode = NULL;

    for(i = 0; i < n; i++) {
        scanf("%d", &value);

        // Allocate memory
        newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = value;
        newnode->next = NULL;

        // If first node
        if(head == NULL) {
            head = newnode;
            temp = newnode;
        }
        else {
            temp->next = newnode;
            temp = newnode;
        }
    }

    // Traverse and print
    temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}