#include<iostream>
using namespace std;
int main(){
int n;
cout<<"enter the number of elements in array: ";
cin>>n;
//input array 1
int arr1[n];
for(int i=0;i<n;i++){
    cout<<"enter "<<i+1<<" element ";
    cin>>arr1[i];
}

int m;
cout<<"enter the number of elements in array: ";
cin>>m;
//input array 2
int arr2[m];
for(int i=0;i<m;i++){
    cout<<"enter "<<i+1<<" element ";
    cin>>arr2[i];
}
int arr3[m+n];
int i=0; int j=0; int k=0;
while(i<n && j<m){
if(arr1[i]<arr2[j]){
    arr3[k]=arr1[i];
    i++;
}
else{
arr3[k]=arr2[j];
j++;
}
k++;
}
    while(i < n){
        arr3[k] = arr1[i];
        i++;
        k++;
    }

    while(j < m){
        arr3[k] = arr2[j];
        j++;
        k++;
    }

//print final array
for(int a=0;a<m+n;a++){
    cout<<arr3[a]<<" ";
}

}