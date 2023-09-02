#include <bits/stdc++.h> 
/************************************************************

    Following is the Tree node structure
	
	template <typename T>
    class TreeNode 
    {
        public : 
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) 
        {
            this -> val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
long long  int helper(TreeNode<int>* root,long long int &ans){
 if(root==NULL)return 0;
 long long int left=helper(root->left,ans);
 long long int right=helper(root->right,ans);
 ans=max(ans,left+right+root->val);
 return max(left,right)+root->val;
}
long long int findMaxSumPath(TreeNode<int> *root)
{
    // Write your code here.
    if(!root)return -1;
    if(!root->left || !root->right)return -1;
    long long int ans=LLONG_MIN;
    helper(root,ans);
    return ans;
}
