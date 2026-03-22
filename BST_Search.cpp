#include <iostream>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) {
        val = value;
        left = NULL;
        right = NULL;
    }
};

TreeNode* searchBST(TreeNode* root, int val) {

    if (root == NULL || root->val == val) {
        return root;
    }

    if (val < root->val) {
        return searchBST(root->left, val);
    } 
    else {
        return searchBST(root->right, val);
    }
}

void inorder(TreeNode* root) {
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {

    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    int val;
    cout << "Enter value to search: ";
    cin >> val;

    TreeNode* result = searchBST(root, val);

    if (result == NULL) {
        cout << "Value not found in BST";
    } 
    else {
        cout << "Subtree rooted at " << result->val << " (inorder): ";
        inorder(result);
    }

    return 0;
}