#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

Node* create(int val)
{
    Node* temp=new Node();
    temp->data=val;
    temp->left=temp->right=NULL;
    return temp;
}

Node* insert(Node* root,int val)
{
    if(root==NULL)
        return create(val);

    if(val<root->data)
        root->left=insert(root->left,val);
    else
        root->right=insert(root->right,val);

    return root;
}

Node* findMin(Node* root)
{
    while(root->left!=NULL)
        root=root->left;
    return root;
}

Node* deleteNode(Node* root,int key)
{
    if(root==NULL)
        return NULL;

    if(key<root->data)
        root->left=deleteNode(root->left,key);

    else if(key>root->data)
        root->right=deleteNode(root->right,key);

    else
    {
        int children=0;

        if(root->left!=NULL) children++;
        if(root->right!=NULL) children++;

        cout<<"Deleting "<<key<<" , Children = "<<children<<endl;

        if(root->left==NULL && root->right==NULL)
            return NULL;

        else if(root->left==NULL)
            return root->right;

        else if(root->right==NULL)
            return root->left;

        Node* temp=findMin(root->right);
        root->data=temp->data;
        root->right=deleteNode(root->right,temp->data);
    }

    return root;
}

void inorder(Node* root)
{
    if(root==NULL)
        return;

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main()
{
    int arr[]={10,5,2,4,7,6,21,15,12,17,24,22,29};
    int n=13;

    Node* root=NULL;

    for(int i=0;i<n;i++)
        root=insert(root,arr[i]);

    cout<<"Inorder traversal:\n";
    inorder(root);

    cout<<"\n\nDeleting nodes\n";

    root=deleteNode(root,2);
    root=deleteNode(root,7);
    root=deleteNode(root,21);

    cout<<"\nFinal tree (Inorder):\n";
    inorder(root);

}