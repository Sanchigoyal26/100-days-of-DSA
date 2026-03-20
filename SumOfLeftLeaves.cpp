#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int val){
    Node* temp = new Node();
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

int sumOfLeftLeaves(Node* root){
    if(root == NULL)
        return 0;

    int sum = 0;

    if(root->left && root->left->left == NULL && root->left->right == NULL){
        sum += root->left->data;
    }

    sum += sumOfLeftLeaves(root->left);
    sum += sumOfLeftLeaves(root->right);

    return sum;
}

int main(){

    Node* root = newNode(3);
    root->left = newNode(9);
    root->right = newNode(20);
    root->right->left = newNode(15);
    root->right->right = newNode(7);

    cout << "Sum of left leaves: " << sumOfLeftLeaves(root);

}