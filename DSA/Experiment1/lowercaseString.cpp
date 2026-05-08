#include<iostream>
#include<string>

int main(){
    std::string str;

    std::cout<<"enter string in uppercase\n";
    std::getline(std::cin,str);
    for(int i=0;i<str.length();i++){
        if(str[i]>='A' && str[i]<='Z')
        {
            str[i]=str[i]+32;
        }
    }

    std::cout<<"lower case string:- "<<str;


}