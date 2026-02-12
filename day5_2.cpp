#include<iostream>
using namespace std;
int main(){
int n,m;
cout<<"enter the number of elements in array 1 and array 2: ";
cin>>n>>m;
//input array 1
int a[n+m];
for(int i=0;i<n;i++){
    cout<<"enter "<<i+1<<" element ";
    cin>>a[i];
}

//input array 2
int b[m];
for(int i=0;i<m;i++){
    cout<<"enter "<<i+1<<" element ";
    cin>>b[i];
}
int i=0,j=0;
while(i<n && j<m){
    if(a[i]<=b[j]){
        i++;
    }
    else{
        for(int c=n;c>i;c--){
            a[c]=a[c-1];
           
        }
        a[i]=b[j];
        j++;
        n++;
        i++;
    }
    
}
while(j<m){
    a[i]=b[j];
    j++;
    n++;
}

for(int d=0;d<n;d++){
    cout<<a[d]<<" ";
}
}