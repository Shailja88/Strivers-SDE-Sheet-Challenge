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
   void inorder(TreeNode* root,vector<int>&v){
       
       if(root!=NULL){
        inorder(root->left,v);
        v.push_back(root->val);
       inorder(root->right,v);
       }
       else{

           v.push_back(100000);
       }
   
   }
      void preorder(TreeNode* root,vector<int>&v){
       
       if(root!=NULL){
           v.push_back(root->val);
        preorder(root->left,v);
        
       preorder(root->right,v);
       }
       else{

           v.push_back(100000);
       }
   
   }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<int>v1;
        vector<int>v2;
        vector<int>p1;
        vector<int>p2;
    inorder(p,v1);
        inorder(q,v2);
        preorder(p,p1);
        
        preorder(q,p2);
        return (v1==v2&& p1==p2);
    }
};
///using reecursion
/**********************************************************

    Following is the Binary Tree Node class structure:

    template <typename T>

    class BinaryTreeNode {
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

***********************************************************/

bool identicalTrees(BinaryTreeNode<int>* root1, BinaryTreeNode<int>* root2) {
    // Write your code here. //recursive	
    if(root1==NULL && root2== NULL)return true;
    if(root1==NULL || root2==NULL)return false;
    return (root1->data==root2->data && identicalTrees(root1->left ,root2->left) &&  identicalTrees(root1->right ,root2->right));
}
