///////this code is for valid BST
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
bool check(TreeNode* root, long long mini,long long maxi){
    if(root==NULL)return true;
    
    else if(root->val>=maxi||root->val<=mini)return false;
    return check(root->left,mini,root->val)&& check(root->right,root->val,maxi);
}
    bool isValidBST(TreeNode* root) {
        return check(root,LLONG_MIN,LLONG_MAX);
    }
};

//This code is for PARTIAL BST
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
bool check(BinaryTreeNode<int>* root,long long maxi,long long mini){
    //[mini,maxi];
    if(root==NULL)return true;
    if(root->data>maxi || root->data<mini)return false;
    return check(root->left,root->data,mini)&&
    check(root->right,maxi,root->data);
    
}
bool validateBST(BinaryTreeNode<int> *root) {
    // Write your code here
    if(root==NULL)return true;
    
    return check(root,LLONG_MAX,LLONG_MIN);
}
