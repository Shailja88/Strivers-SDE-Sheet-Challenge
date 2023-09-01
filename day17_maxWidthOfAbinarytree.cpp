/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
#include<bits/stdc++.h>
int getMaxWidth(TreeNode<int> *root)
{
    // Write your code here.
    int ans=INT_MIN;
    if(!root)return 0;
    queue<TreeNode<int>*>q;
    q.push(root);
    while(!q.empty()){
        int size=q.size();
        ans=max(ans,size);
        while(size--){
            TreeNode<int>* t=q.front();
            q.pop();
            if(t->left)q.push(t->left);
            if(t->right)q.push(t->right);
        }
    }
    return ans;
}



///leetcode
//tc=o(n)
//sc=o(n)
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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        int maxwidth=1;
        while(!q.empty()){
         int start=q.front().second;
         int end=q.back().second;
         maxwidth=max(maxwidth,end-start+1);
         int count=q.size();
         while(count--){
             int idx=q.front().second-end;
             TreeNode* node=q.front().first;
              q.pop();
              if(node->left){
                  q.push({node->left,2*idx+1});
                  
              }
              if(node->right){
                  q.push({node->right,2*idx+2});
              }
         }

        }
        return maxwidth;
    }
};
