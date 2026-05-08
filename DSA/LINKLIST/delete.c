#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
};
//function to convert arr to linked list
struct Node *arr2LL(int arr[],int n){
    if(n==0)
    return NULL;
    else{
        struct Node *head= malloc(sizeof(struct Node));
        struct Node *mover = head;
        head->data = arr[0];
        head ->next= NULL;
        for(int i=1;i<n;i++){
            struct Node *temp = malloc(sizeof(struct Node));
            temp->data= arr[i];
            temp ->next = NULL;
            mover ->next = temp;
            mover = temp;
        }
        return head;
    }
}

//function to print
void printLL(struct Node *head){
    struct Node *temp;
    temp = head;
    while(temp !=NULL){
        printf("%d ", temp ->data);
        temp= temp->next;
    }
}
//function to delete head
struct Node *deleteHead(struct Node *head){
    if(head ==NULL)
    return NULL;
    else{
        struct Node *temp;
        temp = head;
        head = head->next;
        free(temp);
        return head;
    }
}

//function to delete tail
struct Node *deleteTail(struct Node *head){
    if(head ==NULL || head ->next ==NULL)
    return NULL;
    else{
        struct Node *temp= head;
        while(temp ->next ->next !=NULL){
            temp= temp->next;     
        }
          {
            free(temp-> next);
            temp ->next = NULL;
        }
        return head;
    }
}

//function to insert at kth position
struct Node *removeK(struct Node *head, int k, int n){
    if(k==1){
        struct Node *temp=head;
        head = head->next;
        free(temp);
        return head;
    }
    int cnt=0;
    struct Node *temp=head;
    struct Node *prev=temp;
     while(temp !=NULL){
        cnt++;
        prev=temp;
        temp= temp->next;
        if(cnt==k){
            prev->next= prev->next->next;
            free(temp);
            return head;
        }
        
        
     }
            return head;
     
}
struct Node *removeVal(struct Node *head, int val){
    if(head==NULL)
    return NULL;
    struct Node *temp = head;
    struct Node *prev = NULL;
    while(temp ->data !=val){
        prev= temp;
        temp= temp->next;
    }
    prev->next= prev->next ->next;
    free(temp);
    return head;
}


int main(){
    //enter array
    int arr[]= {11,5,8,9};
    int n= sizeof(arr)/sizeof(arr[0]);
    struct Node *head= arr2LL(arr, n);
   // head = deleteTail(head);
    // head = deleteHead(head);
   
   int k;
    printf("enter the position k to remove that node: ");
    scanf("%d", &k);
     head= removeK(head, k, n);
   /*
   int val;
   printf("enter value to remove: ");
   scanf("%d", &val);
   head= removeVal(head, val);
   */
   
    printLL(head);
}