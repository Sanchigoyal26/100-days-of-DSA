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
int find;
cout<<"enter element to find: ";
cin>>find;
int count=0;
//if arr[i]==find
for(int i=0;i<n;i++){
    count++;
    if(arr[i]==find){
       cout<<"found at index "<<i<<"\n";
       cout<<"comparisons "<<count;
       break;
    }
    }

}