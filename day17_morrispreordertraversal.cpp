#include <bits/stdc++.h> 
/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/
vector<int> getPreOrderTraversal(TreeNode *root)
{
    // Write your code here.
    //Morris Preorder traversal
    vector<int>v;
    TreeNode* curr=root;
    while(curr!= NULL){
        v.push_back(curr->data);
        if(curr->left!=NULL){
            TreeNode* temp=curr->left;
            while(temp->right!=NULL){
                temp=temp->right;
            }
            temp->right=curr->right;
            curr->right=NULL;
            curr=curr->left;
        }
        else{
            curr=curr->right;
        }
        
    }
    return v;
}
