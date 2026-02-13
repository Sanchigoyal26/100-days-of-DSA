#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"enter the number of elements in array";
    cin>>n;
    //input array
    int arr[n+1];
    for(int i=0;i<n;i++){
        cout<<"enter "<<i+1<<" element"<<" ";
        cin>>arr[i];
    }
    //input position and number
    int pos,num;
    cout<<"enter the number to add ";
    cin>>num;
    cout<<"enter the position ";
    cin>>pos;
    //put that number in position
    int temp=arr[n-1];
    for(int i=n;i>pos;i--){
        arr[i-1]=arr[i-2];
    }
    arr[n]=temp;
    arr[pos]=num;
    //printing final array
    cout<<"new array"<<"\n";
    for(int i=0;i<n+1;i++){
        cout<<arr[i]<<" ";
    }
    

}