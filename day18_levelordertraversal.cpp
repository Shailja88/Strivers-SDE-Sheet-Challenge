/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

    CODESTUDIO

************************************************************/

vector<int> levelOrder(TreeNode<int> * root){
    // Write your code here.
    vector<int>ans;
    if(root==NULL)return ans;
    queue<TreeNode<int>*>q;
    q.push(root);
    while(!q.empty()){
        TreeNode<int>* temp=q.front();
        q.pop();
        ans.push_back(temp->data);
        if(temp->left!=NULL)
        q.push(temp->left);
        if(temp->right!=NULL)
        q.push(temp->right);
}return ans;
}



////LEETCODE
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        queue<TreeNode*>q;
        q.push(root);
        if(root==NULL)return ans;
        while(1){
           int size=q.size();
           if(size==0)return ans;
           vector<int>data;
           while(size--){
             TreeNode* temp=q.front();
             q.pop();
             data.push_back(temp->val);
             if(temp->left!=NULL)q.push(temp->left);
             if(temp->right!=NULL)q.push(temp->right);

            }
            ans.push_back(data);
}
return ans;
    }
};
