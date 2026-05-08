#include<iostream>
#include<vector>
int main(){
    int n;
    std::cout<<"enter the number of elements you want to enter in array\n";
    std::cin>>n;
    std::vector<int> a1(n);

    for(int i=0;i<n;i++){
        std::cout<<"enter #"<<i+1<<" element of array\n";
        std::cin>>a1[i];
    }

int insertpos;
int del;
int element;
std::cout<<"enter the index position you want to insert element\n";
std::cin>>insertpos;
std::cout<<"enter value you want to insert in the array\n";
std::cin>>element;
std::cout<<"enter the index position you want to delete an element\n";
std::cin>>del;
if(insertpos >= 0 && insertpos <= a1.size()) {
 a1.resize(a1.size()+1);
for(int i=a1.size()+1;i>insertpos;i--){
    a1[i]=a1[i-1];
}
a1[insertpos]=element;
}

if(del >= 0 && del < n){
for(int i=del;i<a1.size();i++){
    a1[i]=a1[i+1];
}
a1.resize(a1.size()-1);
}

std::cout<<"array after insertion and deletion\n";
for(int i=0;i<a1.size();i++){
    std::cout<<a1[i]<<" ";
}
}