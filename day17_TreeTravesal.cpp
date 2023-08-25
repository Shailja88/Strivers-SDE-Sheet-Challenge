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
void inorder(TreeNode *root,vector<int>&v){
  if(root==NULL)return;
   inorder(root->left,v);
   v.push_back(root->data);
   inorder(root->right,v);
}
void preorder(TreeNode *root,vector<int>&v){
  if(root==NULL)return;
  v.push_back(root->data);
  preorder(root->left,v);
  preorder(root->right,v);

}
void postorder(TreeNode *root,vector<int>&v){
  if(root==NULL)return;
  postorder(root->left,v);
  postorder(root->right,v);
  v.push_back(root->data);
}
vector<vector<int>> getTreeTraversal(TreeNode *root){
    // Write your code here.
    vector<int>v;
    vector<vector<int>>ans;
    inorder(root,v);
    ans.push_back(v);
     v.clear();
    preorder(root,v);
     ans.push_back(v);
     v.clear();
    postorder(root,v);
     ans.push_back(v);
     v.clear();
     return ans;
}

/////
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
#include<bits/stdc++.h>
vector<vector<int>> getTreeTraversal(TreeNode *root){
    // Write your code here.
    /*tc=o(3n)
    sc=o(4n)*/
    vector<vector<int>>ans;
     vector<int>pre;
     vector<int>inn;
     vector<int>pos;
    if(root==NULL)return ans;
    stack<pair<TreeNode*,int>>st;
    st.push({root,1});
    while(!st.empty()){
     auto it=st.top();
     st.pop();
   if(it.second==1){
       pre.push_back(it.first->data);
       it.second+=1;
       st.push(it);
       if(it.first->left)
       st.push({it.first->left,1});
   }
   else if(it.second==2){
       inn.push_back(it.first->data);
       it.second+=1;
       st.push(it);
       if(it.first->right)
       st.push({it.first->right,1});
   }
 else{
     pos.push_back(it.first->data);
 }


        
    }
    ans.push_back(inn);
    ans.push_back(pre);
    ans.push_back(pos);
    return ans;
    
}
