#include<iostream>
int main(){
    int rows,columns;
    std::cout<<"enter rows and columns respectively\n";
    std::cin>>rows;
    std::cin>>columns;

    //declaring array
    int array[rows][columns];
    //taking input of array
    for(int i=0;i<rows;i++){
        for(int j=0;j<columns;j++){
            std::cout<<"enter the element of #"<<i+1<<" row's #"<<j+1<<" element ";
            std::cin>>array[i][j];
        }
    }
    //sum of rows
    for (int i=0;i<rows;i++){
        int sum=0;
        for(int j=0;j<columns;j++){
            sum=sum+array[i][j];
        }
        std::cout<<"Sum of #"<<i+1<<" row="<<sum<<'\n';                           
    }

}