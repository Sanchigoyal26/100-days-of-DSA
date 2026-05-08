#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Create new node
Node* createNode(int val)
{
    Node* temp = new Node();
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

// Insert in BST
Node* insertBST(Node* root, int val)
{
    if(root == NULL)
        return createNode(val);

    if(val < root->data)
        root->left = insertBST(root->left, val);
    else
        root->right = insertBST(root->right, val);

    return root;
}                                                                                                                               

// Preorder Traversal
void preorder(Node* root)
{
    if(root == NULL)
        return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// Search in BST with comparison count
bool searchBST(Node* root, int key, int &count)
{
    if(root == NULL)
        return false;

    count++;

    if(root->data == key)
        return true;

    if(key < root->data)
        return searchBST(root->left, key, count);
    else
        return searchBST(root->right, key, count);
}

// Create Degenerative Tree
Node* createDegenerate(int arr[], int n)
{
    Node* root = createNode(arr[0]);
    Node* temp = root;

    for(int i = 1; i < n; i++)
    {
        temp->right = createNode(arr[i]);
        temp = temp->right;
    }

    return root;
}

// Search in Degenerative Tree
bool searchDegenerate(Node* root, int key, int &count)
{
    while(root != NULL)
    {
        count++;

        if(root->data == key)
            return true;

        root = root->right;
    }

    return false;
}

int main()
{
    int arr[] = {90,60,140,40,70,20,50,10,30,120,170,100,130,160};
    int n = sizeof(arr)/sizeof(arr[0]);

    Node* root = NULL;

    // Create BST
    for(int i = 0; i < n; i++)
        root = insertBST(root, arr[i]);

    cout << "BST Preorder Traversal:\n";
    preorder(root);

    // Search in BST
    int key = 160;
    int bstCount = 0;

    if(searchBST(root, key, bstCount))
        cout << "\n160 found in BST";
    else
        cout << "\n160 not found in BST";

    cout << "\nBST Comparisons = " << bstCount << endl;

    // Create Degenerative Tree using preorder
    int preorderArr[] = {90,60,40,20,10,30,50,70,140,120,100,130,170,160};
    Node* degRoot = createDegenerate(preorderArr, n);

    // Search in Degenerative Tree
    int degCount = 0;

    if(searchDegenerate(degRoot, key, degCount))
        cout << "\n160 found in Degenerative Tree";
    else
        cout << "\n160 not found in Degenerative Tree";

    cout << "\nDegenerative Tree Comparisons = " << degCount;

    return 0;
}