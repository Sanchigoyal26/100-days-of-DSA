#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *prev;
    struct node *next;
};
//fuction to create ll from array
struct node * create_LL_from_array(struct node *head,int n,int arr[]){
    //create node
 for(int i=0;i<n;i++){
struct node *newnode=malloc(sizeof(struct node));
 newnode->data=arr[i];
 newnode->prev=NULL;
 newnode->next=NULL;

 if(head==NULL){
    head=newnode;  
 }
 else{
    struct node *temp=head;
    while(temp->next!=NULL){
        temp= temp->next;
    }
        temp->next=newnode;
        newnode->prev=temp;
        temp= temp->next;
 }
 }   
 return head;
}
void PrintLL(struct node *head){
    if(head==NULL){
        printf("the link list is empty");
    }
    else{
        struct node *temp= head;
        while(temp!=NULL){
            printf("%d ", temp->data);
            temp=temp->next;
        }

    }
}
struct Node* Delete_begginning(struct node *head){
    if(head==NULL){
        printf("link list is empty.");
        return  NULL;
    }
    else{
        struct node *temp=head;
        head= head->next;
        free(temp);
    
    }
    return head;
}
int main(){
    int n;
    int arr[]={2,3,4,5,6};
    n=sizeof(arr)/sizeof(arr[0]);
    struct node *head=NULL;
    head=create_LL_from_array(head,n,arr);
    printf("link list before deletion: \n");
     PrintLL(head);
     head=Delete_begginning(head);
     printf("\nlink list after deletion: \n");
     PrintLL(head);
}
