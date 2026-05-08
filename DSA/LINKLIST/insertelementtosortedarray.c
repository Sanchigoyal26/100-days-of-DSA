#include<stdio.h>
int main(){
    int n;
    int arr[100];
    int pos,num;
    printf("enter the number of elements in array? ");
    scanf("%d", &n);
    //input array
    for(int i=0;i<n;i++){
        printf("enter %d element: ", i+1);
        scanf("%d", &arr[i]);
    }
    //input number
    printf("enter number to add in array: ");
    scanf("%d", &num);

    //check the position at which number sits
    int i=0;
    while(i<n){
        if(arr[i]>num)
        break;
        else
        i++;
    }
    pos=i;
    //shifting elements
    for(int j=n;j>pos;j--){
        arr[j]=arr[j-1];
    }
    arr[pos]=num;
    //printing final array
    for(int k=0;k<n+1;k++){
        printf("%d ", arr[k]);
    }

}