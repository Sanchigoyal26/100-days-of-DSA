#include <iostream>
#include <vector>
#include <unordered_map>
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
    unordered_map<int,int> inorderMap;
    int postIndex;

    TreeNode* build(vector<int>& inorder, vector<int>& postorder, int left, int right) {
        if(left > right) return NULL;

        int rootVal = postorder[postIndex--];
        TreeNode* root = new TreeNode(rootVal);

        int index = inorderMap[rootVal];

        root->right = build(inorder, postorder, index + 1, right);
        root->left = build(inorder, postorder, left, index - 1);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

        for(int i = 0; i < inorder.size(); i++) {
            inorderMap[inorder[i]] = i;
        }

        postIndex = postorder.size() - 1;

        return build(inorder, postorder, 0, inorder.size() - 1);
    }
};

void printInorder(TreeNode* root){
    if(!root) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

void printPostorder(TreeNode* root){
    if(!root) return;
    printPostorder(root->left);
    printPostorder(root->right);
    cout << root->val << " ";
}

int main(){

    vector<int> inorder = {9,3,15,20,7};
    vector<int> postorder = {9,15,7,20,3};

    Solution sol;
    TreeNode* root = sol.buildTree(inorder, postorder);

    cout << "Inorder: ";
    printInorder(root);

    cout << endl;

    cout << "Postorder: ";
    printPostorder(root);

    return 0;
}