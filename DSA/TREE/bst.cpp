#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

Node* insert(Node* root, int val) {
    if (root == NULL)
        return new Node(val);

    if (val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}

void preorder(Node* root) {
    if (root == NULL)
        return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
bool search(Node* root, int key, int &count)
{
    if (root == NULL)
        return false;

    count++;

    if (root->data == key)
        return true;

    if (key < root->data)
        return search(root->left, key, count);
    else
        return search(root->right, key, count);
}

int main() {

    int arr[] = {90,60,140,40,70,20,50,10,30,120,170,100,130,160};
    int n = sizeof(arr)/sizeof(arr[0]);

    Node* root = NULL;

    for(int i = 0; i < n; i++)
        root = insert(root, arr[i]);

    cout << "Preorder Traversal: ";
    preorder(root);
    int key = 30;
int count = 0;

if(search(root, key, count))
    cout << "Element found\n";
else
    cout << "Element not found\n";

cout << "Comparisons = " << count;

    return 0;
} 