#include<iostream>
#include<vector>
using namespace std;
void pushfront(vector<int> &stack, int size, int &ftop){
    if(ftop == size - 1) {
        cout << "Stack Overflow\n";
        return; 
    }
    int val;
    cout << "Enter value to push: ";
    cin >> val;

    ftop++;
    stack[ftop] = val;
}
void pushback(vector<int> &stack, int size, int &btop){
    if(btop == -1) {
        cout << "Stack Overflow\n";
        return;
    }
    int val;
    cout << "Enter value to push: ";
    cin >> val;

    btop--;
    stack[btop] = val;
}

    void display(vector<int> &stack, int top,int size) {

    if(top == -1) {
        cout << "Stack is empty\n";
        return;
    }

    cout << "Stack elements:\n";
    for(int i = top; i <size; i++) {
        cout << stack[i] << " ";
    }
    cout << endl;
}



int main(){
    int size;
    cout<<"enter stack size: ";
    cin>>size;
    vector<int> stack(size,0);
    int ftop=-1;
    int btop=size;
    int s1;
    cout<<"elements to push in stack 1: ";
    cin>> s1;
    for(int i=0;i<s1;i++){
        pushfront(stack,size,ftop);
    }
    int s2;
    cout<<"elements to push in stack 2: ";
    cin>> s2;
    for(int i=0;i<s2;i++){
        pushback(stack,size,btop);
    }
    int top=0;
    display(stack,top,size);


}