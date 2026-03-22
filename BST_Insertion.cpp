#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) {
        val = x;
        left = NULL;
        right = NULL;
    }
};

TreeNode* insertIntoBST(TreeNode* root, int val) {

    // if tree empty create node
    if (root == NULL) {
        return new TreeNode(val);
    }

    // go to left subtree
    if (val < root->val) {
        root->left = insertIntoBST(root->left, val);
    }
    // go to right subtree
    else {
        root->right = insertIntoBST(root->right, val);
    }

    return root;
}

void inorder(TreeNode* root) {
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {

    TreeNode* root = NULL;

    root = insertIntoBST(root, 4);
    insertIntoBST(root, 2);
    insertIntoBST(root, 7);
    insertIntoBST(root, 1);
    insertIntoBST(root, 3);

    cout << "BST after insertion (inorder): ";
    inorder(root);

    return 0;
}