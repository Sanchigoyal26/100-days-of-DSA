#include<iostream>


int sum_array(int array[],int size)
{
    if(size==0)
    return 0;
    else
    return(array[size-1]+sum_array(array,size-1));

}
int main(){
    int size;
    std::cout<<"enter the number of elements of array\n";
    std::cin>>size;
    int array[size];
    for(int i=0;i<size;i++){
        std::cout<<"enter #"<<i+1<<" element ";
        std::cin>>array[i];
    }
    std::cout<<"Sum of elements of array : "<<sum_array(array,size);
}