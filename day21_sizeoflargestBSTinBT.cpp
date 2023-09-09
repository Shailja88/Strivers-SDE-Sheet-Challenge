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
TC==O(n^2)

    BRUTE FORCE:
    
*/
int x=0;

void size(TreeNode* root,int &cnt){
     if(root==NULL)return;
     size(root->left,cnt);
     cnt++;
     size(root->right,cnt);
    
}
bool checkBST(TreeNode* root,int mini,int  maxi){
if(root==NULL)return true;
  else if(root->data>=maxi||root->data<=mini)return false;
    return checkBST(root->left,mini,root->data)&& checkBST(root->right,root->data,maxi);
}
void preorder(TreeNode* root){
    if(!root)return ;
    if(checkBST(root,INT_MIN,INT_MAX)){
        int i=0;
        size(root,i);
     x= max(x,i);
      }
    preorder(root->left);
    preorder(root->right);
}
int largestBST(TreeNode * root){
    // Write your code here.
    preorder(root);
    return x;
}



//optimal
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
 class NodeValue{
     public:
     int maxNode,minNode,maxSize;
     NodeValue(int maxNode,int minNode,int maxSize){
         this->maxNode=maxNode;
         this->minNode=minNode;
         this->maxSize=maxSize;
     }
 };
 int x=0;
class Solution {
    private:
    NodeValue helper(TreeNode* root){
        //postorder left right root;
        if(!root)return  NodeValue(INT_MIN,INT_MAX,0);
    
    auto left=helper(root->left);
    auto right=helper(root->right);
    if(left.maxNode<root->val && root->val<right.minNode){
        int sum=root->val+left.maxSize+right.maxSize;
        x=max(x,sum);
        return NodeValue(max(root->val,right.maxNode),min(root->val,left.minNode),sum);
    }
    return NodeValue(INT_MAX,INT_MIN,max(left.maxSize,right.maxSize));
    }
public:
   
    int maxSumBST(TreeNode* root) {
        
    x=0;
      helper(root);
      return x;
          }
};
