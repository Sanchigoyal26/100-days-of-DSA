#include <iostream>
#include <vector>
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

vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> result;

    if (root == NULL)
        return result;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {

        int size = q.size();
        vector<int> level;

        for (int i = 0; i < size; i++) {
            TreeNode* node = q.front();
            q.pop();

            level.push_back(node->val);

            if (node->left)
                q.push(node->left);

            if (node->right)
                q.push(node->right);
        }

        result.push_back(level);
    }

    return result;
}

int main() {

    // Creating example tree
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    vector<vector<int>> ans = levelOrder(root);

    for (auto level : ans) {
        for (auto x : level)
            cout << x << " ";
        cout << endl;
    }

    return 0;
}