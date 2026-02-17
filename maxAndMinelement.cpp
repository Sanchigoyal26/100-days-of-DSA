#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> a(n);

    //input array
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    //max element
    int max=a[0];
    for(int i=1;i<n;i++){
        if(a[i]>max){
            max=a[i];
        }
    }
    cout<<"the maximum element is: "<< max<<"\n";

    //min element
    int min=a[0];
    for(int i=1; i<n;i++){
        if(a[i]<min){
            min=a[i];
        }
    }
    cout<<"the minimum element is: "<< min;
}
