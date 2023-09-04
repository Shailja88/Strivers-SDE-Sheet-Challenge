
/************************************************************
TC=O(N)
SC=O(1)
    Following is the TreeNode class structure:

    template <typename T>
    class TreeNode
    {
    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T dat)
        {
            this->data = dat;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
#include<bits/stdc++.h>
void flattenBinaryTree(TreeNode<int>* root)
{
    // Write your code here.
    //inplace 
    if(!root)return;
    TreeNode<int>* curr=root;
    while(curr){
        //first check whether the left node exits or not
        if(curr->left){
         //find the predecessor
         TreeNode<int>* pred=curr->left;
         while(pred->right){
             pred=pred->right;
         }   
         pred->right=curr->right;
         curr->right=curr->left;
         curr-> left=NULL;    

            
        }
        curr=curr->right;
        
    }
    
}
