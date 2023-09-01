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

************************************************************/
#include<bits/stdc++.h>
vector<int> bottomView(TreeNode<int> * root){
    // Write your code here.
    vector<int>ans;
    queue<pair<TreeNode<int> *,int>>q;
    map<int,int>mp;
    if(!root)return ans;
    q.push({root,0});
    while(!q.empty()){
        auto it=q.front();
        q.pop();
        TreeNode<int> * node=it.first;
         int line=it.second;
         mp[line]=node->data;
        if(node->left)q.push({node->left,line-1});
        if(node->right)q.push({node->right,line+1});
    }
    for(auto it:mp){
        ans.push_back(it.second);
    }
    return ans;
}
