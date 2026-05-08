//DOUBLE LINK LIST
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
//DELETION
struct node * delete_Head(struct node *head){
    if(head==NULL){
        printf("linked list is empty");
        return NULL;
    }
    else if(head->next==NULL){
        free(head);
        return NULL;
    }
    else{
       head= head->next;
       head->prev=NULL;

    }
    return head;
}
struct node * delete_Tail(struct node *head){
    if(head==NULL|| head->next == NULL){
        free(head);
        printf("link list is empty");
        return NULL;
    }
    else{
        struct node *temp= head;
        while(temp->next!=NULL){
            temp= temp->next;
        }
        temp->prev->next= NULL;
        free(temp);
    }
    return head;
}
struct node * delete_Kth_node(struct node *head,int k){
    if(head==NULL){
        printf("the list is empty");
        return NULL;
    }
    
    else{
        struct node *temp= head;
        int count =1;
        if(k==1){
            head= head->next;
            head->prev=NULL;
            return head;
        }
        
        while(temp!=NULL){
            if(count==k){
                if(temp->prev != NULL)
                temp->prev->next= temp->next;
                if(temp->next != NULL)
                temp->next->prev= temp->prev;
                free(temp);
                break;
            }
            count++;
            temp= temp->next;
        }
    }
    return head;
}
struct node * delete_after_pos(struct node *head,int pos){
    if (head==NULL){
        printf("link list is empty. ");
        return NULL;
    }
    else {
        struct node *temp=head;
        struct node * back=NULL;
        int count =0;
        while(temp!=NULL){
            count++;
            if(count==pos){
                back->next= temp->next;
                temp->next->prev= back;
                free(temp);
              }
                back=temp;
                temp= temp->next;
            }
        }
        return head;
    }



int main(){
    int n;
    int arr[]={2,3,4,5,6};
    n=sizeof(arr)/sizeof(arr[0]);
    struct node *head=NULL;
    //int k;
   // printf("enter position to delete: ");
   // scanf("%d", &k);
    /*
    printf("link list before deletion: \n");
    head=create_LL_from_array(head,n,arr);
    PrintLL(head);
    */
   /*
   printf("link list after deletion of head : \n");
    head=delete_Head(head);
    PrintLL(head);
   */
 /*
    head=create_LL_from_array(head,n,arr);
    head=delete_Tail(head);
    PrintLL(head);
 */
/*
    head=create_LL_from_array(head,n,arr);
    head=delete_Kth_node(head,k);
    PrintLL(head);
*/
int pos;
printf("enter position after which node should be deleted: ");
scanf("%d ", &pos);
head=create_LL_from_array(head,n,arr);
head=delete_after_pos(head,pos);
PrintLL(head);
}