#include<iostream>
#include<stack>
using namespace std;
int main(){
    string s;
    cout<<"enter string: ";
    cin>> s;
    //brackets opening-> push
    //brackets closing->if stack empty->not balanced, if stack top== closing bracket->pop 
    //at last if stack is empty, then its balanced
    stack<char> st;
    for(int i=0;i<s.length();i++){
        if(s[i]=='(' || s[i]=='{'|| s[i]=='['){
            st.push(s[i]);
        }
        else{
            if(st.empty()){
                cout<<"not balanced.";
            }
            char top= st.top();
           if(s[i]==')' && top=='(' ||s[i]=='}' && top=='{'||s[i]==']' && top=='[' ){
            st.pop();
           }
           else{
            cout<<"not balanced. ";
           }
        }

    }
    if(st.empty()){
        cout<<"balanced. ";
    }
    else{
        cout<<"not balanced. ";
    }

}
