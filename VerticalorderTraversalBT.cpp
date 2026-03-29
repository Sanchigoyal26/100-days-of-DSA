#include <iostream>
#include <queue>
#include <map>
#include <vector>
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

Node* buildTree(vector<int> &arr, int n) {
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

void verticalOrder(Node* root) {
    if(root == NULL) return;

    map<int, vector<int>> mp;
    queue<pair<Node*, int>> q;

    q.push({root, 0});

    while(!q.empty()) {
        Node* curr = q.front().first;
        int hd = q.front().second;
        q.pop();

        mp[hd].push_back(curr->data);

        if(curr->left)
            q.push({curr->left, hd - 1});

        if(curr->right)
            q.push({curr->right, hd + 1});
    }

    for(auto it : mp) {
        for(int x : it.second)
            cout << x << " ";
        cout << endl;
    }
}

int main() {
    int N;
    cin >> N;

    vector<int> arr(N);
    for(int i = 0; i < N; i++)
        cin >> arr[i];

    Node* root = buildTree(arr, N);

    verticalOrder(root);

    return 0;
}