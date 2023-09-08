#include <bits/stdc++.h> 
/************************************************************
method 1:brute force taking 

EXTRA SPACE


    Following is the TreeNode class structure:

    class BinaryTreeNode {
    public:
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;
        
        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        
        ~BinaryTreeNode() {
            if (left) {
              delete left;
            }
            if (right) {
              delete right;
            }
        }
    };

************************************************************/
void inorder(BinaryTreeNode<int> *root,vector<int>&v){
    if(root==NULL)return ;
    inorder(root->left,v);
    v.push_back(root->data);
    inorder(root->right,v);
}
int findCeil(BinaryTreeNode<int> *node, int x){
    // Write your code here.
    vector<int>v;
    inorder(node,v);
    for(auto in:v){
        if(in>=x)return in;
    }
    return -1;
}'
  #include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure:

    class BinaryTreeNode {
    public:
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;
        
        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        
        ~BinaryTreeNode() {
            if (left) {
              delete left;
            }
            if (right) {
              delete right;
            }
        }
    };

************************************************************/

int findCeil(BinaryTreeNode<int> *node, int x){
    // Write your code here.
    int ans=-1;
    while(node!=NULL){
        if(node->data==x)return x;
        if(node->data>x){
            ans=node->data;
            node=node->left;
        }
        else{
            //node->data<x
            node=node->right;
        }
    }
    return ans;
}
