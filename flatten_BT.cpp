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

void flatten(Node* root) {

    if(!root) return;

    flatten(root->left);
    flatten(root->right);

    Node* leftSub = root->left;
    Node* rightSub = root->right;

    root->left = NULL;
    root->right = leftSub;

    Node* curr = root;

    while(curr->right)
        curr = curr->right;

    curr->right = rightSub;
}

void printList(Node* root) {

    Node* curr = root;

    while(curr) {
        cout << curr->data << " ";
        curr = curr->right;
    }
}

int main() {

    int N;
    cin >> N;

    vector<int> arr(N);

    for(int i = 0; i < N; i++)
        cin >> arr[i];

    Node* root = buildTree(arr, N);

    flatten(root);

    printList(root);

    return 0;
}