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
 SC=O(1)
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        ///Morris inorder traversal 
        vector<int>v;
        TreeNode* curr=root;
        while(curr!=NULL){
          if(curr->left!=NULL){
              TreeNode* temp=curr->left;
              TreeNode* leftPtr=curr->left;
           while(temp->right!=NULL){
               temp=temp->right;
           }
          temp->right=curr;
          curr->left=NULL;
          curr=leftPtr;
          }
          else{
              v.push_back(curr->val);
              curr=curr->right;
          }


          }

        return v;
    }
};
