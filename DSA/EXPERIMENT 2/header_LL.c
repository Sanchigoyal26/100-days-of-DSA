#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    char name[50];
    int roll;
    float cgpa;
    struct Student* next;
};

int main() {
    struct Student *head = (struct Student*)malloc(sizeof(struct Student));
    head->next = NULL;

    struct Student *temp = head;

    int n;
    printf("Enter number of students: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        struct Student *newNode = (struct Student*)malloc(sizeof(struct Student));
        
        printf("Name Roll CGPA: ");
        scanf("%s %d %f", newNode->name, &newNode->roll, &newNode->cgpa);

        newNode->next = NULL;
        temp->next = newNode;
        temp = newNode;
    }

    float max = 0;
    temp = head->next;

    while(temp != NULL) {
        if(temp->cgpa > max)
            max = temp->cgpa;
        temp = temp->next;
    }

    printf("Topper(s):\n");
    temp = head->next;

    while(temp != NULL) {
        if(temp->cgpa == max)
            printf("%s %d %.2f\n", temp->name, temp->roll, temp->cgpa);
        temp = temp->next;
    }

    return 0;
}