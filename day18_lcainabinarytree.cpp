/**
method 1
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
bool find(TreeNode* root, vector<TreeNode*>&path,TreeNode* x){
    if(root==NULL)return false;
      path.push_back(root);
    if(root==x)return true;
  
   if(find(root->left,path,x)||find(root->right,path,x))
    return true;
    path.pop_back();
    return false;
}
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*>path1,path2;
        TreeNode* ans=NULL;
        find(root,path1,p);
        find(root,path2,q);
        for(int i=0;i<path1.size()&& i<path2.size();i++){
            if(path1[i]==path2[i])
            ans=path1[i];
        }
        return ans;
    }
};


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 TC=O(n)
 SC=O(n)
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
     if(root==NULL)return NULL;
     if(root==p || root==q)return root;
     TreeNode* lca1=lowestCommonAncestor(root->left,p,q);
     TreeNode* lca2=lowestCommonAncestor(root->right,p,q);
     if(lca1!=NULL && lca2!=NULL)return root;
     if(lca1!=NULL)return lca1;
     else return lca2;
    }
};
