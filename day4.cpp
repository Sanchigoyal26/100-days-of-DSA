//Given an array of n integers, reverse the array in-place using two-pointer approach.

#include<iostream>
using namespace std;
int main(){
int n;
cout<<"enter the number of elements in array: ";
cin>>n;
//input array
int arr[n];
for(int i=0;i<n;i++){
    cout<<"enter "<<i+1<<" element ";
    cin>>arr[i];
}
//reverse array
int i=0,j=n-1;
while(i<j){
    swap(arr[i],arr[j]);
    i++;
    j--;
}
//printing array
for(int i=0;i<n;i++){
    cout<< arr[i]<<" ";
}
}