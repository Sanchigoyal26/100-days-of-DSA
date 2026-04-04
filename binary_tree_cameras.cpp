#include <iostream>
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

class Solution {
public:
    int cameras = 0;

    int dfs(TreeNode* root) {

        if(root == NULL)
            return 2;

        int left = dfs(root->left);
        int right = dfs(root->right);

        if(left == 0 || right == 0) {
            cameras++;
            return 1;
        }

        if(left == 1 || right == 1)
            return 2;

        return 0;
    }

    int minCameraCover(TreeNode* root) {
        if(dfs(root) == 0)
            cameras++;

        return cameras;
    }
};

int main() {

    // Example tree
    TreeNode* root = new TreeNode(0);
    root->left = new TreeNode(0);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(0);

    Solution sol;

    cout << "Minimum Cameras Needed: ";
    cout << sol.minCameraCover(root);

    return 0;
}