/**********************************************************
    Following is the Binary Tree Node structure:

    class BinaryTreeNode
    {
    public:
        int data;
        BinaryTreeNode *left, *right;
        BinaryTreeNode() : data(0), left(NULL), right(NULL) {}
        BinaryTreeNode(int x) : data(x), left(NULL), right(NULL) {}
        BinaryTreeNode(int x, BinaryTreeNode *left, BinaryTreeNode *right) : data(x), left(left), right(right) {}
    };

    TC=O(n^2)
***********************************************************/
#include<bits/stdc++.h>
void inorder(BinaryTreeNode* root, set<int>&st){
    if(!root)return ;
    inorder(root->left,st);
    st.insert(root->data);
    inorder(root->right, st);

}
bool pairSumBst(BinaryTreeNode *root, int k)
{
    // Write your code here
    //brute force approach
  set<int>st;
  inorder(root, st);
  for(auto in:st){
      if(st.find(k-in)!=st.end())return true;
  }
  return false;
}


//optimal approach
/**********************************************************
    Following is the Binary Tree Node structure:

    class BinaryTreeNode
    {
    public:
        int data;
        BinaryTreeNode *left, *right;
        BinaryTreeNode() : data(0), left(NULL), right(NULL) {}
        BinaryTreeNode(int x) : data(x), left(NULL), right(NULL) {}
        BinaryTreeNode(int x, BinaryTreeNode *left, BinaryTreeNode *right) : data(x), left(left), right(right) {}
    };
***********************************************************/
#include<bits/stdc++.h>
void inorder(BinaryTreeNode* root, vector<int>&st){
    if(!root)return ;
    inorder(root->left,st);
    st.push_back(root->data);
    inorder(root->right, st);

}
bool pairSumBst(BinaryTreeNode *root, int k)
{
    // Write your code here
    //brute force approach
   vector<int>st;
   inorder(root, st);
   int i=0; int j=st.size()-1;
   while(i<=j){
       int sum=st[i]+st[j];
       if(sum==k)return true;
       if(sum>k){
           j--;
       }
       if(sum<k){
           i++;
       }

   }
  return false;
}
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

TC=O(n)
SC=O(h)
 */
 class BSTIterator{
     private:
     stack<TreeNode*>st;
     bool reverse=true;
     public:
     BSTIterator(TreeNode* root, bool isReverse){
         reverse=isReverse;
         pushAll(root);
     }
     bool hasNext(){
         return !st.empty();
     }
     int next(){
         TreeNode* temp=st.top();
         st.pop();
         if(!reverse)
         pushAll(temp->right);
         else
         pushAll(temp->left);
         return temp->val;
         
     }
     private:
     void pushAll(TreeNode* root){
         while(root){
             st.push(root);
             if(reverse==true){
                ///before k liye
             root=root->right;
             }
             else{
              //next k liye
              root=root->left;
             }
         }
     }

 };
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        //by using the concept of BSTIterator
        if(!root)return false;
        BSTIterator l(root,false);//for  finding next(); st.top() will be smallest
        BSTIterator r(root, true);//for finding before();st.top() will be largest;
        int i=l.next();//sbse chhoti value
        int j=r.next();//sbse bdi value;
        while(i<j){
            if(i+j==k)return true;
            else if(i+j>k) j=r.next();
            else
            i=l.next();
        }
        return false;
    }
};
