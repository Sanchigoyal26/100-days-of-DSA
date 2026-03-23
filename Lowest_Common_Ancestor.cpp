#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = right = NULL;
    }
};

Node* insert(Node* root, int val){
    
    if(root == NULL)
        return new Node(val);

    if(val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}

Node* LCA(Node* root, int n1, int n2){

    while(root != NULL){

        if(n1 < root->data && n2 < root->data)
            root = root->left;

        else if(n1 > root->data && n2 > root->data)
            root = root->right;

        else
            return root;
    }

    return NULL;
}

int main(){

    int N;
    cin >> N;

    Node* root = NULL;

    for(int i=0;i<N;i++){
        int x;
        cin >> x;
        root = insert(root,x);
    }

    int a,b;
    cin >> a >> b;

    Node* ans = LCA(root,a,b);

    cout << ans->data;

}