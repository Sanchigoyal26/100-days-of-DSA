#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};
struct Node* createNode(int val){
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=val;
    newNode->next=NULL;
    return newNode;
}
void insertAtBeg(struct Node** head,int val){
    struct Node* nn=createNode(val);
    if(*head==NULL)
    {
        *head=nn;
        return;
    }
    struct Node* temp=nn;
    temp->next=(*head);
    *head=temp;

}
void deleteAtEnd(struct Node** head){
    if(*head==NULL){
        printf("List is empty\n");
        return;
    }
    struct Node* temp=*head;
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    struct Node* del = temp->next;
    temp->next = NULL;
    free(del);
}
void display(struct Node *head){
    struct Node* temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
}
int main(){

    struct Node* head=NULL;
    int n;
    printf("enter the number of nodes you want\n");
    scanf("%d",&n);
    int data;
    for(int i=0;i<n;i++){
        printf("enter value\n");
        scanf("%d",&data);
        insertAtBeg(&head,data);

    }
    display(head);
}