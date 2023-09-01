//using level order traversal
#include <bits/stdc++.h> 
/************************************************************

Following is the Binary Tree node class
    
template <typename T = int>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val)
    {
        this->data = val;
        left = NULL;
        right = NULL;
    }

    ~TreeNode()
    {
        if (left != NULL)
        {
            delete left;
        }
        if (right != NULL)
        {
            delete right;
        }
    }
};

************************************************************/

vector<int> verticalOrderTraversal(TreeNode<int> *root)
{ vector<int>ans;
if(!root)return ans;
    //    Write your code here.
    map<int,map<int,vector<int>>>nodes;
    queue<pair<TreeNode<int> *,pair<int,int>>>todo;//{root,vertical level}
    todo.push({root,{0,0}});//{root vertical level}
    while(!todo.empty()){
        auto p=todo.front();
        todo.pop();
        TreeNode<int>* node=p.first;
        int x=p.second.first;
        int y=p.second.second;
        nodes[x][y].push_back(node->data);
        if(node->left){
            todo.push({node->left,{x-1,y+1}});
            
        }
        if(node->right){
            todo.push({node->right,{x+1,y+1}});
        }
    }
 
  for(auto p:nodes){
      for(auto y:p.second){
          ans.insert(ans.end(),y.second.begin(),y.second.end());
      }
  }
return ans;
    
}
