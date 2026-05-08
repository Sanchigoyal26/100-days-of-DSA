#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node * Convert_arr_to_LL(struct node *head, int arr[], int n){
    for(int i=0;i<n;i++){
        struct node *newnode= malloc(sizeof(struct node));
        newnode->data=arr[i];
        newnode->next= NULL;
        if(head==NULL){
            head=newnode;
        }
        else{
            struct node*temp=head;
            while(temp->next!=NULL){
               
                temp=temp->next;
            }
            temp->next=newnode;
            
        }
    }
    return head;
}
void PrintLL(struct node*head){
    if(head==NULL){
        printf("link list is empty");
    }
    else{
        struct node *temp=head;
        while(temp!=NULL){
            printf("%d ", temp->data);
            temp=temp->next;
        }
    }
}
//insert at head
struct node *push(struct node *head, int val){
    struct node * newnode= malloc(sizeof(struct node));
    newnode->data=val;
    newnode->next=NULL;
    if(head==NULL){
        head= newnode;
        return head;
    }
    else{
        newnode->next=head;
        head= newnode;
        return head;
    }

}
// delete and print head
struct node *pop(struct node *head){
    if(head==NULL){
        printf("Link list is empty");
        return NULL;
    }
    else{
        head=head->next;
        return head;
    }
}
int main(){
    int arr []={2,3,4,5,6};
   int n=sizeof(arr)/sizeof(arr[0]);
   struct node *head=NULL;
   head=Convert_arr_to_LL(head,arr,n);
   PrintLL(head);
   int val;
    printf("enter the value to push: ");
    scanf("%d", &val);
    printf("\n");
    head=push(head,val);
    PrintLL(head);
    printf("\n");
    head=pop(head);
    PrintLL(head);

}