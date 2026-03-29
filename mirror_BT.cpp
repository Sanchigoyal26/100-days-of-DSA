#include <iostream>
#include <vector>
#include <queue>
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

Node* buildTree(vector<int>& arr, int n) {

    if(n == 0 || arr[0] == -1) return NULL;

    Node* root = new Node(arr[0]);
    queue<Node*> q;
    q.push(root);

    int i = 1;

    while(!q.empty() && i < n) {

        Node* curr = q.front();
        q.pop();

        if(arr[i] != -1) {
            curr->left = new Node(arr[i]);
            q.push(curr->left);
        }
        i++;

        if(i < n && arr[i] != -1) {
            curr->right = new Node(arr[i]);
            q.push(curr->right);
        }
        i++;
    }

    return root;
}

void mirror(Node* root) {

    if(!root) return;

    swap(root->left, root->right);

    mirror(root->left);
    mirror(root->right);
}

void inorder(Node* root) {

    if(!root) return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {

    int N;
    cin >> N;

    vector<int> arr(N);

    for(int i = 0; i < N; i++)
        cin >> arr[i];

    Node* root = buildTree(arr, N);

    mirror(root);

    inorder(root);

    return 0;
}