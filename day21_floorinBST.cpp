//brute force approch
#include <bits/stdc++.h> 
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
void inorder(TreeNode<int>* root, vector<int>&v){
    if(root==NULL)return ;
    inorder(root->left, v);
    v.push_back(root->val);
    inorder(root->right,v);
}
int floorInBST(TreeNode<int> * root, int X)
{
    // Write your code here.
    //brute force
    vector<int>v;
    inorder(root,v);
    for(int i=0;i<v.size();i++){
        if(v[i]>X)
        return v[i-1];
    }
    return v[v.size()-1];

}

//method 2 tc=O(h) SC=O(1)
#include <bits/stdc++.h> 
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

int floorInBST(TreeNode<int> * root, int X)
{  
    int ans=-1;
    while(root!=NULL){
        if(root->val>X){
            root=root->left;
        }
        else{
            ans=root->val;
            root=root->right;
        }
        
    }
    return ans;
    // Write your code here.
}
