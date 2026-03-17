#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = NULL;
        right = NULL;
    }
};

TreeNode* buildTree(int arr[], int n) {

    if(arr[0] == -1)
        return NULL;

    TreeNode* root = new TreeNode(arr[0]);
    queue<TreeNode*> q;
    q.push(root);

    int i = 1;

    while(!q.empty() && i < n) {

        TreeNode* curr = q.front();
        q.pop();

        if(i < n && arr[i] != -1) {
            curr->left = new TreeNode(arr[i]);
            q.push(curr->left);
        }
        i++;

        if(i < n && arr[i] != -1) {
            curr->right = new TreeNode(arr[i]);
            q.push(curr->right);
        }
        i++;
    }

    return root;
}

int maxDepth(TreeNode* root) {

    if(root == NULL)
        return 0;

    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}

int main() {

    int n;
    cin >> n;

    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    TreeNode* root = buildTree(arr, n);

    cout << maxDepth(root);

    return 0;
}