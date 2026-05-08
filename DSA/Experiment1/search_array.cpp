#include<iostream>
#include<vector>
int main(){
    int n;
    
    std::cout<<"enter number of elements you want to enter in array\n";
    std::cin>>n;
    std::vector<int> arr(n);
    std::cout<<"enter elements of array\n";
    for(int i=0;i<n;i++){
        std::cin>>arr[i];
    }
    int target;
    std::cout<<"enter the element you want to search in the array\n";
    std::cin>>target;

    bool found=false;
    int i;
    for(i=0;i<n;i++){
        if(arr[i]==target){
        found=true;
        break;
    }
    }
    if(found)
    std::cout<<"target is at index:- "<<i;
    else
    std::cout<<"target not found";
}