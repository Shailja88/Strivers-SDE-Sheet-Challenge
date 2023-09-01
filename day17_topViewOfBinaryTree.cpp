/************************************************************

    Following is the TreeNode class structure:

    template <typename T>
    class TreeNode
    {
    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T dat)
        {
            this->data = dat;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
#include<bits/stdc++.h>
vector<int> getTopView(TreeNode<int> *root)
{
    //without recursion
    vector<int>ans;
  
    if(!root)return ans;
    queue<pair<TreeNode<int> *,int>>q;
   map<int,int>mp;
    q.push({root,0});
    while(!q.empty()){
        auto it=q.front();
        q.pop();
        TreeNode<int> *n1=it.first;
        int line=it.second;
          if(mp.find(line)==mp.end()){
              
               mp[it.second]=n1->data;
          }
      if(n1->left)q.push({n1->left,line-1});
      if(n1->right)q.push({n1->right,line+1});  
    }
    for(auto  in:mp){
        ans.push_back(in.second);
    }
    return ans;
}
