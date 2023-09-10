#include <bits/stdc++.h> 
/*************************************************************
 
    Following is the Binary Tree node structure

    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
BinaryTreeNode<int>* helper(BinaryTreeNode<int>*root,BinaryTreeNode<int>*&prev,BinaryTreeNode<int>*&head){
    if(!root)return NULL;//base case
    helper(root->left,prev,head);
    if(prev==NULL)head=root;
    else{
         prev->right=root;
         root->left=prev;
    }
    prev=root;
    helper(root->right,prev,head);
    return head;
    
}
BinaryTreeNode<int>* BTtoDLL(BinaryTreeNode<int>* root) {
    // Write your code here
    BinaryTreeNode<int>*prev=NULL,*head=NULL;
    return helper(root,prev,head);
    
}
