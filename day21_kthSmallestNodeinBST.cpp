//brute force
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode
    {
    public:
        T data;
        TreeNode<T> *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(T x) : data(x), left(NULL), right(NULL) {}
        TreeNode(T x, TreeNode<T> *left, TreeNode<T> *right) : data(x), left(left), right(right) {}
    };

************************************************************/
void inorder(TreeNode<int>* root,vector<int>&v){
      if(!root)return;
      inorder(root->left,v);
      v.push_back(root->data);
      inorder(root->right,v);
}
int kthSmallest(TreeNode<int> *root, int k)
{
    //  Write the code here.
    //brute force
    vector<int>v;
    inorder(root,v);
    return v[k-1];
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
 */
class Solution {
public:
int ans;
void inorder(TreeNode* root, int &i,int k){
    if(root==NULL)return;
    inorder(root->left, i,k);
      if(i==k){
        ans=root->val;
        i++;
      }
      else{
          i++;
      }
 inorder(root->right,i,k);

}
    int kthSmallest(TreeNode* root, int k) {
        
        int i=1;
 inorder(root,i,k);
return ans;
    }
};
